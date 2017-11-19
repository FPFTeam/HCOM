-- This file is licensed under the New BSD License
{-# LANGUAGE ForeignFunctionInterface #-}
{-# LANGUAGE MagicHash #-}

--
-- COMCall.hs:
--
-- Actually invoke a COM method!
--
-- All this code is internal use only.
--

module System.Win32.HCOM.COMCall
( Stackable(..) -- Things that can be put on a stack.
, Stack         -- A stack
, rawVCall      -- Invoke a COM function.
) where

import Control.Category hiding ((.), id)
import Data.Void
import Foreign
import GHC.Exts

import System.Win32.HCOM.Flatten
import System.Win32.HCOM.RawFunctions(HRESULT)
import System.Win32.HCOM.Stack

------------------------------------------------------------------------
-- 'vararg' invocation of 'thunk'.
--

-- COM methods are function pointers. To avoid the need for a foreign
-- import "dynamic" declaration for each COM method bound, this module
-- defines a family of call functions. A call function takes a function
-- pointer, a first argument corresponding to the COM object self reference,
-- and 0 or more arguments for the COM method being called.
-- The call function takes care of performing the invocation according
-- to the system calling convention.

-- We then have a dispatch function which takes a list of parameters, and
-- invokes the appropriate version of the thunk function based on the
-- number of parameters.

-- The main source of complexity is the fast calling convention used in
-- x64 architectures, which uses up to 4 integer registers and up to 4
-- floating point registers, so the call functions must keep track of
-- the numeric type of the arguments, up to 4 floating point arguments
-- (pointers qualify as integral).

-- FIXME: It could be argued that for a large number of arguments, we
-- should have a separate thunk which just copies an area of memory
-- onto the stack. We would then allocate an area, dump the list into
-- it, and call that function instead.

-- FIXME: Complete the family of call functions up to at least 10 arguments
--        using Template Haskell.

type I0  = IO  Word32
type I                         = Word   -> I0
type D                         = Double -> I0
type II                        = Word   -> I
type ID                        = Word   -> D
type DI                        = Double -> I
type DD                        = Double -> D
type III                       = Word   -> II
type IID                       = Word   -> ID
type IDI                       = Word   -> DI
type IDD                       = Word   -> DD

foreign import stdcall "dynamic" _I      :: FunPtr I     -> I
foreign import stdcall "dynamic" _II     :: FunPtr II    -> II
foreign import stdcall "dynamic" _ID     :: FunPtr ID    -> ID
foreign import stdcall "dynamic" _III    :: FunPtr III   -> III
foreign import stdcall "dynamic" _IID    :: FunPtr IID   -> IID
foreign import stdcall "dynamic" _IDI    :: FunPtr IDI   -> IDI
foreign import stdcall "dynamic" _IDD    :: FunPtr IDD   -> IDD

{-# INLINE callThunk #-}
callThunk :: [SE] -> IO HRESULT
callThunk [I funptr, I a]                                                   = _I      (word2ptr funptr) a
callThunk [I funptr, I a, I b]                                              = _II     (word2ptr funptr) a b
callThunk [I funptr, I a, D b]                                              = _ID     (word2ptr funptr) a b
callThunk [I funptr, I a, I b, I c]                                         = _III    (word2ptr funptr) a b c
callThunk [I funptr, I a, I b, D c]                                         = _IID    (word2ptr funptr) a b c
callThunk [I funptr, I a, D b, I c]                                         = _IDI    (word2ptr funptr) a b c
callThunk [I funptr, I a, D b, D c]                                         = _IDD    (word2ptr funptr) a b c
callThunk _ = error "Internal error in vcall: Too many arguments. Use Template Haskell to generate all the possibilities."

------------------------------------------------------------------------
-- COM function invocation.
--

-- Virtual function table is an array of function pointers.
type VTblPtr = Ptr (Ptr ())

-- Given an object, a vtable index, and a list of params... call it!
-- This is the raw version, as it uses a plain Ptr for the object.
-- The wrapped version lives in COMPtr.
rawVCall :: Flatten b c => Ptr a -> Int -> Stack ((), HRESULT) b -> IO c
rawVCall obj idx args = do
  -- The start of the object is the vtbl pointer. Dereference it.
  vtbl <- peek (castPtr obj :: Ptr VTblPtr)
  -- Index into it to get the appropriate function.
  fn   <- peekElemOff vtbl idx
  -- Cast our parameter list into a set of Voids we can construct a
  -- stack from, and then invoke the function.
  let fullArgs = argIn fn >>> argIn obj >>> args
  -- Our thunk should be wrapped up to put the HResult into a
  -- pseudo-list format we can then flatten.
      thunk = fmap ((,) ()) . fmap fromIntegral . callThunk
  -- Finally, do the invocation and flatten the result into a plain tuple.
  res <- flatten <$> (thunk #< fullArgs)
  return res

word2ptr :: Word   -> FunPtr a
word2ptr (W# w)= castPtrToFunPtr $ Ptr (int2Addr# (word2Int# w))
