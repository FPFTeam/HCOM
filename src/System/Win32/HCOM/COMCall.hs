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
import GHC.Prim
import GHC.Types

import System.Win32.HCOM.Flatten
import System.Win32.HCOM.RawFunctions(HRESULT)
import System.Win32.HCOM.Stack

------------------------------------------------------------------------
-- 'vararg' invocation of 'thunk'.
--

-- 'thunk' is our universal COM call entry point. It's simply a
-- vararg-style function whose first parameter is the address of the
-- function to call through to. This makes it simple to call any
-- stdcall function at any address.

-- See Thunk.s for the (very simple) implementation.

-- On the other hand, FFI doesn't support varargs. Instead, we create
-- a whole set of different thunk functions, all calling the same
-- underlying function, but with different type signatures!

-- We then have a function which takes a list of parameters, and
-- invokes the appropriate version of the thunk function based on the
-- number of parameters.

-- This kind of thing tempts me to use Template Haskell, but I don't
-- think it's /quite/ worth it yet.

-- FIXME: It could be argued that for a large number of arguments, we
-- should have a separate thunk which just copies an area of memory
-- onto the stack. We would then allocate an area, dump the list into
-- it, and call that function instead.

type F0  = IO  Word
type F1  = Ptr Void -> F0
type F2  = Ptr Void -> F1
type F3  = Ptr Void -> F2
type F4  = Ptr Void -> F3
type F5  = Ptr Void -> F4
type F6  = Ptr Void -> F5
type F7  = Ptr Void -> F6
type F8  = Ptr Void -> F7
type F9  = Ptr Void -> F8
type F10 = Ptr Void -> F9
type F11 = Ptr Void -> F10
type F12 = Ptr Void -> F11
type F13 = Ptr Void -> F12
type F14 = Ptr Void -> F13
type F15 = Ptr Void -> F14
type F16 = Ptr Void -> F15
type F17 = Ptr Void -> F16
type F18 = Ptr Void -> F17
type F19 = Ptr Void -> F18
type F20 = Ptr Void -> F19
type F21 = Ptr Void -> F20
type F22 = Ptr Void -> F21
type F23 = Ptr Void -> F22
type F24 = Ptr Void -> F23
type F25 = Ptr Void -> F24
type F26 = Ptr Void -> F25

foreign import stdcall "dynamic" thunk1  :: FunPtr F1  -> F1
foreign import stdcall "dynamic" thunk2  :: FunPtr F2  -> F2
foreign import stdcall "dynamic" thunk3  :: FunPtr F3  -> F3
foreign import stdcall "dynamic" thunk4  :: FunPtr F4  -> F4
foreign import stdcall "dynamic" thunk5  :: FunPtr F5  -> F5
foreign import stdcall "dynamic" thunk6  :: FunPtr F6  -> F6
foreign import stdcall "dynamic" thunk7  :: FunPtr F7  -> F7
foreign import stdcall "dynamic" thunk8  :: FunPtr F8  -> F8
foreign import stdcall "dynamic" thunk9  :: FunPtr F9  -> F9
foreign import stdcall "dynamic" thunk10 :: FunPtr F10 -> F10
foreign import stdcall "dynamic" thunk11 :: FunPtr F11 -> F11
foreign import stdcall "dynamic" thunk12 :: FunPtr F12 -> F12
foreign import stdcall "dynamic" thunk13 :: FunPtr F13 -> F13
foreign import stdcall "dynamic" thunk14 :: FunPtr F14 -> F14
foreign import stdcall "dynamic" thunk15 :: FunPtr F15 -> F15
foreign import stdcall "dynamic" thunk16 :: FunPtr F16 -> F16
foreign import stdcall "dynamic" thunk17 :: FunPtr F17 -> F17
foreign import stdcall "dynamic" thunk18 :: FunPtr F18 -> F18
foreign import stdcall "dynamic" thunk19 :: FunPtr F19 -> F19
foreign import stdcall "dynamic" thunk20 :: FunPtr F20 -> F20
foreign import stdcall "dynamic" thunk21 :: FunPtr F21 -> F21
foreign import stdcall "dynamic" thunk22 :: FunPtr F22 -> F22
foreign import stdcall "dynamic" thunk23 :: FunPtr F23 -> F23
foreign import stdcall "dynamic" thunk24 :: FunPtr F24 -> F24
foreign import stdcall "dynamic" thunk25 :: FunPtr F25 -> F25
foreign import stdcall "dynamic" thunk26 :: FunPtr F26 -> F26

callThunk :: [Ptr Void] -> IO Word
callThunk [funptr, a]                                                   = thunk1  (castPtrToFunPtr $ castPtr funptr) a
callThunk [funptr, a,b]                                                 = thunk2  (castPtrToFunPtr $ castPtr funptr) a b
callThunk [funptr, a,b,c]                                               = thunk3  (castPtrToFunPtr $ castPtr funptr) a b c
callThunk [funptr, a,b,c,d]                                             = thunk4  (castPtrToFunPtr $ castPtr funptr) a b c d
callThunk [funptr, a,b,c,d,e]                                           = thunk5  (castPtrToFunPtr $ castPtr funptr) a b c d e
callThunk [funptr, a,b,c,d,e,f]                                         = thunk6  (castPtrToFunPtr $ castPtr funptr) a b c d e f
callThunk [funptr, a,b,c,d,e,f,g]                                       = thunk7  (castPtrToFunPtr $ castPtr funptr) a b c d e f g
callThunk [funptr, a,b,c,d,e,f,g,h]                                     = thunk8  (castPtrToFunPtr $ castPtr funptr) a b c d e f g h
callThunk [funptr, a,b,c,d,e,f,g,h,i]                                   = thunk9  (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i
callThunk [funptr, a,b,c,d,e,f,g,h,i,j]                                 = thunk10 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k]                               = thunk11 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l]                             = thunk12 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m]                           = thunk13 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n]                         = thunk14 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o]                       = thunk15 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p]                     = thunk16 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q]                   = thunk17 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r]                 = thunk18 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q r
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s]               = thunk19 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q r s
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t]             = thunk20 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q r s t
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u]           = thunk21 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q r s t u
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v]         = thunk22 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q r s t u v
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w]       = thunk23 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q r s t u v w
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x]     = thunk24 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q r s t u v w x
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y]   = thunk25 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q r s t u v w x y
callThunk [funptr, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z] = thunk26 (castPtrToFunPtr $ castPtr funptr) a b c d e f g h i j k l m n o p q r s t u v w x y z
callThunk _ = error "Internal error in vcall: Too many arguments."

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
      thunk = fmap ((,) ()) . fmap fromIntegral . callThunk . map word2ptr
  -- Finally, do the invocation and flatten the result into a plain tuple.
  flatten <$> (thunk #< fullArgs)

word2ptr :: Word -> Ptr Void
word2ptr (W# w)= Ptr (int2Addr# (word2Int# w))
