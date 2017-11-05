-- This file is licensed under the New BSD License
{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE ForeignFunctionInterface #-}
{-# LANGUAGE EmptyDataDecls #-}
{-# LANGUAGE FlexibleInstances #-}

--
-- COMPtr.hs:
--
-- Interfaces and (smart) pointers to COM objects.
--

module System.Win32.HCOM.COMPtr
  -- Interfaces
( Interface(..)
, IUnknown
, IDispatch
  -- COM pointers
, COMPtr()
, nullCOMPtr
  -- Raw pointer access functions.
, mkOutParam
, withRawCOMPtr
  -- Invocable functions
, vcall
, queryInterface
, qi
, qiChecked
) where

import Control.Category hiding ((.), id)
import Control.Exception
import Control.Monad
import Control.Monad.Trans
import Foreign hiding (newForeignPtr, void)
import Foreign.Concurrent
import System.IO.Unsafe (unsafePerformIO)

import System.Win32.HCOM.COMCall
import System.Win32.HCOM.GUID
import System.Win32.HCOM.Flatten
import System.Win32.HCOM.RawFunctions
import System.Win32.HCOM.SafeArray
import System.Win32.HCOM.Stack
import System.Win32.HCOM.Tags
import System.Win32.HCOM.ErrorBase

-- NB: In various places below, we use unsafePerformIO to construct
-- singletons that need to be constructed in the IO monad. We do this
-- as we don't want to have to keep constructing new objects, or push
-- the IO monad into quite so many operations.

------------------------------------------------------------------------
-- Interfaces
--

-- | Our Interfaces are simply types which we use with COM pointers to
-- create phantom types, representing the underlying interface exposed
-- by the COM object.
--
-- We define a type class to represent things which are Interfaces.
-- The type class allows us to access the IID associated with an
-- interface (useful for CoCreate, QueryInterface, etc.)

class Interface a where
    iidOf :: COMPtr a -> IID

-- Now let's define a couple of common interfaces!

data IUnknown

instance Interface IUnknown where
    iidOf _ = GUID 0x00000000 0x0000 0x0000 0xC000 0x00 0x00 0x00 0x00 0x00 0x46

data IDispatch

instance Interface IDispatch where
    iidOf _ = GUID 0x00020400 0x0000 0x0000 0xC000 0x00 0x00 0x00 0x00 0x00 0x46

------------------------------------------------------------------------
-- Raw access to IUnknown reference counts
--

-- This is access to IUnknown using raw 'Ptr ()'s, rather than
-- COMPtrs. We wrap them up later.

-- Adding special code to ignore null pointers on the IUnknown
-- interface operations reduces the need for boilerplate elsewhere.

rawAddRef :: Ptr () -> IO Word32
rawAddRef obj =
    if obj /= nullPtr
    then rawVCall obj 1 id
    else return 0

rawRelease :: LPUNKNOWN -> IO Word32
rawRelease obj =
    if obj /= nullPtr
    then rawVCall obj 2 id
    else return 0

------------------------------------------------------------------------
-- COM pointers
--

-- These COM pointers behave like smart pointers in C++. Each COMPtr
-- holds a reference count on the underlying object, and releases it
-- when it dies.

-- To do this, we simply wrap up a ForeignPtr (), and assume (by
-- construction) that the thing we're wrapping implements IUnknown.

-- We use phantom types to show exactly which interface is accessible.

newtype COMPtr a = CP (ForeignPtr ())
    deriving (Show, Eq, Ord)

comFinalizer :: LPUNKNOWN -> IO ()
comFinalizer = void . rawRelease

-- | A null COM pointer.
nullCOMPtr :: COMPtr a
nullCOMPtr = unsafePerformIO (CP <$> newForeignPtr_ nullPtr)

-- Create a COMPtr from an ordinary pointer, taking a reference.
mkCOMPtr :: LPUNKNOWN -> IO (COMPtr a)
mkCOMPtr obj = do
  rawAddRef obj
  CP <$> newForeignPtr obj (comFinalizer obj)

-- Perform an operation using the raw COM pointer.
withRawCOMPtr :: COMPtr a -> (LPUNKNOWN -> IO b) -> IO b
withRawCOMPtr (CP fptr) = withForeignPtr fptr

-- Create an ordinary pointer from COMPtr. The newly created pointer
-- has its own reference count that whoever receives it must
-- eventually release.
getRawCOMPtrWithRef :: COMPtr a -> IO LPUNKNOWN
getRawCOMPtrWithRef comPtr = do
  withRawCOMPtr comPtr $ \obj -> do
    rawAddRef obj
    return obj

-- Create a pointer to an 'out parameter' slot, from which we'll take
-- ownership to create a COM pointer, once the nested operation
-- completes.
--
-- NB: No new reference count is added (the add in 'mkCOMPtr' matches
-- the release in 'finally'), but instead the COMPtr takes ownership
-- of the thing being pointed to.
mkOutParam :: (Ptr LPUNKNOWN -> IO a) -> IO (a, COMPtr b)
mkOutParam op = do
  with nullPtr $ \ptr -> do
    finally (do
               res    <- op ptr
               comObj <- mkCOMPtr =<< peek ptr
               return (res, comObj))
            (rawRelease =<< peek ptr)

------------------------------------------------------------------------
-- Functions using COMPtr.
--

-- A wrapper for rawVCall
vcall :: Flatten b c => COMPtr a -> String -> Int -> Stack ((), HRESULT) b -> IO c
vcall (CP fptr) name idx stack =
  inContext name . withForeignPtr fptr $ \obj -> do
    when (obj == nullPtr) $ throwHCOM "Invoking method on null COM pointer"
    rawVCall obj idx stack

-- The forall is because we're using scoped type variables to get the
-- right IID.
queryInterface :: forall a b . Interface b =>
                  COMPtr a -> IO (HResult, COMPtr b)
queryInterface obj =
    if obj /= nullCOMPtr
    then do
          let riid = iidOf (undefined :: COMPtr b)
          (hr, res) <- vcall obj "queryInterface" 0 $ argInByRef riid >>> argOut
          return (HResult hr, res)
    else return (e_FAIL, nullCOMPtr)

-- Calls queryInterface using UnsafePerformIO. This *should* be safe, but relies
-- on the COM server behaving itself.
-- returns nullCOMPtr on failure
qi :: Interface b => COMPtr a -> COMPtr b
qi = snd . unsafePerformIO . queryInterface

-- Calls queryInterface using UnsafePerformIO. This *should* be safe, but relies
-- on the COM server behaving itself.
-- Throws an exception on failure.
qiChecked :: Interface b => COMPtr a -> COMPtr b
qiChecked obj = unsafePerformIO $ do
    (hr, res) <- queryInterface obj
    when (failed hr) $ throwHCOM $ "Failed to queryInterface to " ++
                                   show (iidOf res) ++ " " ++ show hr
    return res

------------------------------------------------------------------------
-- Instance of Stackable
--

instance Stackable (COMPtr a) where
    -- In this case, no need to bump reference counts.
    argIn (CP fptr) f = do
      withForeignPtr' fptr $ \obj -> argIn obj f

    argInByRef (CP fptr) f = do
      withForeignPtr' fptr $ \obj -> argInByRef obj f

    -- On the way in, we created a raw pointer with a reference count.
    -- The callee will release if it overwrites this field without
    -- taking a reference.
    --
    -- On the way out, we have a reference to whatever's returned, so
    -- we take ownership of it with a new COMPtr.
    argInOut comPtr f = do
      liftNest mkOutParam $ \ptr -> do
        lift $ getRawCOMPtrWithRef comPtr >>= poke ptr
        argIn ptr f

    -- No need to bump reference counts.
    argOut f = do
      liftNest mkOutParam $ \ptr -> argIn ptr f

------------------------------------------------------------------------
-- Instance of COMStorable
--

-- NB: Cut and paste code. :(

-- Store: The destination is given a reference, which it must release.
-- Fetch: We must add a new reference, as the containing memory keeps
--        ownership.

instance COMStorable (COMPtr IUnknown) where
    getVarType _ = c_VT_UNKNOWN
    store p x    = getRawCOMPtrWithRef x >>= poke (castPtr p)
    fetch p      = mkCOMPtr              =<< peek (castPtr p)

instance COMStorable (COMPtr IDispatch) where
    getVarType _ = c_VT_DISPATCH
    store p x    = getRawCOMPtrWithRef x >>= poke (castPtr p)
    fetch p      = mkCOMPtr              =<< peek (castPtr p)

