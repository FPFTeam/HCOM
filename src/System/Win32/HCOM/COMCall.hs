-- This file is licensed under the New BSD License
{-# LANGUAGE ForeignFunctionInterface #-}

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

import Control.Applicative
import Control.Category hiding ((.), id)
import Control.Monad
import Foreign

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

type F0  = IO Word32
type F1  = Word32 -> F0
type F2  = Word32 -> F1
type F3  = Word32 -> F2
type F4  = Word32 -> F3
type F5  = Word32 -> F4
type F6  = Word32 -> F5
type F7  = Word32 -> F6
type F8  = Word32 -> F7
type F9  = Word32 -> F8
type F10 = Word32 -> F9
type F11 = Word32 -> F10
type F12 = Word32 -> F11
type F13 = Word32 -> F12
type F14 = Word32 -> F13
type F15 = Word32 -> F14
type F16 = Word32 -> F15
type F17 = Word32 -> F16
type F18 = Word32 -> F17
type F19 = Word32 -> F18
type F20 = Word32 -> F19
type F21 = Word32 -> F20
type F22 = Word32 -> F21
type F23 = Word32 -> F22
type F24 = Word32 -> F23
type F25 = Word32 -> F24
type F26 = Word32 -> F25

foreign import stdcall "thunk" thunk0  :: F0
foreign import stdcall "thunk" thunk1  :: F1
foreign import stdcall "thunk" thunk2  :: F2
foreign import stdcall "thunk" thunk3  :: F3
foreign import stdcall "thunk" thunk4  :: F4
foreign import stdcall "thunk" thunk5  :: F5
foreign import stdcall "thunk" thunk6  :: F6
foreign import stdcall "thunk" thunk7  :: F7
foreign import stdcall "thunk" thunk8  :: F8
foreign import stdcall "thunk" thunk9  :: F9
foreign import stdcall "thunk" thunk10 :: F10
foreign import stdcall "thunk" thunk11 :: F11
foreign import stdcall "thunk" thunk12 :: F12
foreign import stdcall "thunk" thunk13 :: F13
foreign import stdcall "thunk" thunk14 :: F14
foreign import stdcall "thunk" thunk15 :: F15
foreign import stdcall "thunk" thunk16 :: F16
foreign import stdcall "thunk" thunk17 :: F17
foreign import stdcall "thunk" thunk18 :: F18
foreign import stdcall "thunk" thunk19 :: F19
foreign import stdcall "thunk" thunk20 :: F20
foreign import stdcall "thunk" thunk21 :: F21
foreign import stdcall "thunk" thunk22 :: F22
foreign import stdcall "thunk" thunk23 :: F23
foreign import stdcall "thunk" thunk24 :: F24
foreign import stdcall "thunk" thunk25 :: F25
foreign import stdcall "thunk" thunk26 :: F26

callThunk :: [Word32] -> IO Word32

callThunk []                                                    = thunk0
callThunk [a]                                                   = thunk1  a
callThunk [a,b]                                                 = thunk2  a b
callThunk [a,b,c]                                               = thunk3  a b c
callThunk [a,b,c,d]                                             = thunk4  a b c d
callThunk [a,b,c,d,e]                                           = thunk5  a b c d e
callThunk [a,b,c,d,e,f]                                         = thunk6  a b c d e f
callThunk [a,b,c,d,e,f,g]                                       = thunk7  a b c d e f g
callThunk [a,b,c,d,e,f,g,h]                                     = thunk8  a b c d e f g h
callThunk [a,b,c,d,e,f,g,h,i]                                   = thunk9  a b c d e f g h i
callThunk [a,b,c,d,e,f,g,h,i,j]                                 = thunk10 a b c d e f g h i j
callThunk [a,b,c,d,e,f,g,h,i,j,k]                               = thunk11 a b c d e f g h i j k
callThunk [a,b,c,d,e,f,g,h,i,j,k,l]                             = thunk12 a b c d e f g h i j k l
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m]                           = thunk13 a b c d e f g h i j k l m
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n]                         = thunk14 a b c d e f g h i j k l m n
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o]                       = thunk15 a b c d e f g h i j k l m n o
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p]                     = thunk16 a b c d e f g h i j k l m n o p
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q]                   = thunk17 a b c d e f g h i j k l m n o p q
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r]                 = thunk18 a b c d e f g h i j k l m n o p q r
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s]               = thunk19 a b c d e f g h i j k l m n o p q r s
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t]             = thunk20 a b c d e f g h i j k l m n o p q r s t
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u]           = thunk21 a b c d e f g h i j k l m n o p q r s t u
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v]         = thunk22 a b c d e f g h i j k l m n o p q r s t u v
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w]       = thunk23 a b c d e f g h i j k l m n o p q r s t u v w
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x]     = thunk24 a b c d e f g h i j k l m n o p q r s t u v w x
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y]   = thunk25 a b c d e f g h i j k l m n o p q r s t u v w x y
callThunk [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z] = thunk26 a b c d e f g h i j k l m n o p q r s t u v w x y z
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
  -- Cast our parameter list into a set of Word32s we can construct a
  -- stack from, and then invoke the function.
  let fullArgs = argIn fn >>> argIn obj >>> args
  -- Our thunk should be wrapped up to put the HResult into a
  -- pseudo-list format we can then flatten.
      thunk = liftM ((,) ()) . callThunk
  -- Finally, do the invocation and flatten the result into a plain tuple.
  flatten <$> (thunk #< fullArgs)
