-- This file is licensed under the New BSD License
{-# LANGUAGE FlexibleInstances, TypeSynonymInstances #-}

--
-- Variant.hs:
--
-- Defines the Haskell equivalent of 'VARIANT'.
--

-- Very short exports list, as most everything else is done through
-- the Stackable instance
module System.Win32.HCOM.Variant (Variant(..)) where

import Control.Applicative
import Control.Monad.Reader
import qualified Data.ByteString.Char8 as B
import Data.Time
import Data.Ratio
import Foreign

import System.Win32.HCOM.BSTR()
import System.Win32.HCOM.COMPtr
import System.Win32.HCOM.ErrorBase
import System.Win32.HCOM.RawFunctions
import System.Win32.HCOM.SafeArray
import System.Win32.HCOM.Stack
import System.Win32.HCOM.Tags

------------------------------------------------------------------------
-- Variant data definitions.
--

-- First, let's define a Variant on the Haskell side as an algebraic
-- datatype:

-- | The tags here match up with what's supported by VARIANT according
-- to WTypes.h.
--
-- We explicitly support both individual values, and safearrays of
-- those values marked with the VT_ARRAY flag.
--
-- <http://msdn.microsoft.com/en-us/library/e305240e-9e11-4006-98cc-26f4932d2118(VS.85)> is quite useful, too.
--
-- The types we currently do not support are:
--
-- * Anything VT_BYREF (non-VT_ARRAY VT_VARIANT is /only/ allowed with
--   VT_BYREF, and thus is not supported).
--
-- * VT_CY      - slightly obscure
--
-- * VT_RECORD  - not sure how to handle this

data Variant = -- Non-array types.
               VT_EMPTY                         -- ^ Nothing
             | VT_NULL                          -- ^ SQL-style NULL
             | VT_I2        Int16               -- ^ 2 byte signed int
             | VT_I4        Int32               -- ^ 4 byte signed int
             | VT_R4        Float               -- ^ 4 byte real
             | VT_R8        Double              -- ^ 8 byte real
             | VT_DATE      UTCTime             -- ^ Date
             | VT_BSTR      B.ByteString        -- ^ String
             | VT_DISPATCH  (COMPtr IDispatch)  -- ^ IDispatch *
             | VT_ERROR     HResult             -- ^ SCODE
             | VT_BOOL      Bool                -- ^ \-1 = True, 0 = False
             | VT_UNKNOWN   (COMPtr IUnknown)   -- ^ IUnknown *
             | VT_I1        Int8                -- ^ Signed char
             | VT_UI1       Word8               -- ^ Unsigned char
             | VT_UI2       Word16              -- ^ Unsigned short
             | VT_UI4       Word32              -- ^ Unsigned long
             | VT_INT       Int                 -- ^ Signed machine int
             | VT_UINT      Word                -- ^ Unsigned machine int
             | VT_DECIMAL   Rational            -- ^ High precesion decimals
               -- Array types.
             | VT_I2a       (SafeArray Int16)
             | VT_I4a       (SafeArray Int32)
             | VT_R4a       (SafeArray Float)
             | VT_R8a       (SafeArray Double)
             | VT_DATEa     (SafeArray UTCTime)
             | VT_BSTRa     (SafeArray B.ByteString)
             | VT_DISPATCHa (SafeArray (COMPtr IDispatch))
             | VT_ERRORa    (SafeArray HResult)
             | VT_BOOLa     (SafeArray Bool)
             | VT_VARIANTa  (SafeArray Variant)
             | VT_UNKNOWNa  (SafeArray (COMPtr IUnknown))
             | VT_I1a       (SafeArray Int8)
             | VT_UI1a      (SafeArray Word8)
             | VT_UI2a      (SafeArray Word16)
             | VT_UI4a      (SafeArray Word32)
             | VT_INTa      (SafeArray Int)
             | VT_UINTa     (SafeArray Word)
               deriving (Show, Eq, Ord)

unsupportedTagError :: VARTYPE -> a
unsupportedTagError tag =
  throwHCOM $ (case tag of
             x | x .&. c_VT_BYREF  /= 0              -> "VT_BYREF"
             x | x .&. c_VT_VECTOR /= 0              -> "VT_VECTOR"
             x | x .&. c_VT_TYPEMASK == c_VT_CY      -> "VT_CY"
             x | x .&. c_VT_TYPEMASK == c_VT_VARIANT -> "VT_VARIANT"
             x | x .&. c_VT_TYPEMASK == c_VT_RECORD  -> "VT_RECORD"
             _ -> "VARIANT tag " ++ show tag) ++ " not supported."

------------------------------------------------------------------------
-- Low-level field accessors and mutators.
--

-- Get a pointer to the actual data.
getDataPtr :: Ptr VARIANT -> Ptr a
getDataPtr p = p `plusPtr` 8

-- Get the type field.
getVT :: Ptr VARIANT -> IO VARTYPE
getVT p = peek $ castPtr p

-- Set the type field.
setVT :: Ptr VARIANT -> VARTYPE -> IO ()
setVT p vt = poke (castPtr p) vt

------------------------------------------------------------------------
-- Functions to marshal/unmarshal into given memory.
--

sizeofVariant :: Int
sizeofVariant = 16

-- Fill a variant into the given pointer
marshalVariant :: Variant -> Ptr VARIANT -> IO ()
marshalVariant var ptr = do
  -- Clear the structure.
  rawVariantInit ptr

  let write :: COMStorable a => a -> IO ()
      write x = do
        setVT ptr (getVarType x)
        store (castPtr $ getDataPtr ptr) x

  -- Fill the structure in.
  case var of
    -- Non-array types.
    VT_EMPTY       -> setVT ptr c_VT_EMPTY
    VT_NULL        -> setVT ptr c_VT_NULL
    VT_I2        x -> write x
    VT_I4        x -> write x
    VT_R4        x -> write x
    VT_R8        x -> write x
    VT_DATE      x -> write x
    VT_BSTR      x -> write x
    VT_DISPATCH  x -> write x
    VT_ERROR     x -> write x
    VT_BOOL      x -> write x
    VT_UNKNOWN   x -> write x
    VT_I1        x -> write x
    VT_UI1       x -> write x
    VT_UI2       x -> write x
    VT_UI4       x -> write x
    VT_INT       x -> write x
    VT_UINT      x -> write x
    -- FIXME: Add support for marshalling VT_DECIMAL
    VT_DECIMAL   _ -> throwHCOM "Marshalling of variant tag VT_DECIMAL not supported."
    -- Array types.
    VT_I2a       x -> write x
    VT_I4a       x -> write x
    VT_R4a       x -> write x
    VT_R8a       x -> write x
    VT_DATEa     x -> write x
    VT_BSTRa     x -> write x
    VT_DISPATCHa x -> write x
    VT_ERRORa    x -> write x
    VT_BOOLa     x -> write x
    VT_VARIANTa  x -> write x
    VT_UNKNOWNa  x -> write x
    VT_I1a       x -> write x
    VT_UI1a      x -> write x
    VT_UI2a      x -> write x
    VT_UI4a      x -> write x
    VT_INTa      x -> write x
    VT_UINTa     x -> write x

unmarshalVariant :: Ptr VARIANT -> IO Variant
unmarshalVariant ptr = do
  let read ctr = ctr <$> fetch (castPtr $ getDataPtr ptr)

  tag <- getVT ptr
  if tag .&. c_VT_ARRAY == 0
   then case tag of
          x | x == c_VT_EMPTY    -> return VT_EMPTY
          x | x == c_VT_NULL     -> return VT_NULL
          x | x == c_VT_I2       -> read   VT_I2
          x | x == c_VT_I4       -> read   VT_I4
          x | x == c_VT_R4       -> read   VT_R4
          x | x == c_VT_R8       -> read   VT_R8
          x | x == c_VT_DATE     -> read   VT_DATE
          x | x == c_VT_BSTR     -> read   VT_BSTR
          x | x == c_VT_DISPATCH -> read   VT_DISPATCH
          x | x == c_VT_ERROR    -> read   VT_ERROR
          x | x == c_VT_BOOL     -> read   VT_BOOL
          x | x == c_VT_UNKNOWN  -> read   VT_UNKNOWN
          x | x == c_VT_I1       -> read   VT_I1
          x | x == c_VT_UI1      -> read   VT_UI1
          x | x == c_VT_UI2      -> read   VT_UI2
          x | x == c_VT_UI4      -> read   VT_UI4
          x | x == c_VT_INT      -> read   VT_INT
          x | x == c_VT_UINT     -> read   VT_UINT
          x | x == c_VT_DECIMAL  -> unmarshalDecimal ptr
          _ -> unsupportedTagError tag
   else case tag .&. complement c_VT_ARRAY of
          x | x == c_VT_I2       -> read   VT_I2a
          x | x == c_VT_I4       -> read   VT_I4a
          x | x == c_VT_R4       -> read   VT_R4a
          x | x == c_VT_R8       -> read   VT_R8a
          x | x == c_VT_DATE     -> read   VT_DATEa
          x | x == c_VT_BSTR     -> read   VT_BSTRa
          x | x == c_VT_DISPATCH -> read   VT_DISPATCHa
          x | x == c_VT_ERROR    -> read   VT_ERRORa
          x | x == c_VT_BOOL     -> read   VT_BOOLa
          x | x == c_VT_VARIANT  -> read   VT_VARIANTa
          x | x == c_VT_UNKNOWN  -> read   VT_UNKNOWNa
          x | x == c_VT_I1       -> read   VT_I1a
          x | x == c_VT_UI1      -> read   VT_UI1a
          x | x == c_VT_UI2      -> read   VT_UI2a
          x | x == c_VT_UI4      -> read   VT_UI4a
          x | x == c_VT_INT      -> read   VT_INTa
          x | x == c_VT_UINT     -> read   VT_UINTa
          _ -> unsupportedTagError tag
          
unmarshalDecimal :: Ptr VARIANT -> IO Variant
unmarshalDecimal ptr = do
  scale <- read 2 :: IO Word8
  sign  <- read 3 :: IO Word8
  hi    <- read 4 :: IO Word32
  lo    <- read 8 :: IO Word64
  let num = (shiftL (toInteger hi) 64 .|. toInteger lo) % (10 ^ scale)
  return . VT_DECIMAL $ if sign == 0 then num else negate num
  where
    read :: (COMStorable a) => Int -> IO a
    read = fetch . castPtr . plusPtr ptr
    
freeVariant :: Ptr VARIANT -> IO ()
freeVariant ptr = do
  rawVariantClear ptr

------------------------------------------------------------------------
-- Instance of Stackable.
--

instance Stackable Variant where
    argIn x f = do
      allocaBytes' sizeofVariant $ \ptr -> do
        bracket_' (marshalVariant x ptr)
                  (freeVariant ptr)
                  (do
                     -- Variant takes 4 words of the stack.
                     elts <- lift $ peekArray 4 $ castPtr ptr
                     pushStack elts f)

    argInByRef x f = do
      allocaBytes' sizeofVariant $ \ptr -> do
        bracket_' (marshalVariant x ptr)
                  (freeVariant ptr)
                  (argIn ptr f)

    argInOut x f = do
      allocaBytes' sizeofVariant $ \ptr -> do
        bracket_' (marshalVariant x ptr)
                  (freeVariant ptr)
                  (do
                     res <- argIn ptr f
                     var <- lift $ unmarshalVariant ptr
                     return (res, var))

    argOut = argInOut VT_EMPTY

------------------------------------------------------------------------
-- Instance of COMStorable.
--

instance COMStorable Variant where
    getVarType _ = c_VT_VARIANT
    store p x = marshalVariant x $ castPtr p
    fetch p   = unmarshalVariant $ castPtr p
