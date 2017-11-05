-- This file is licensed under the New BSD License
--
-- Stack.hs:
--
-- Build up the arguments on the stack for a COM call.
--
-- All this code is internal use only.
--

module System.Win32.HCOM.Stack
( Stackable(..) -- Things that can be put on a stack
, Stack         -- A stack
, (#<)          -- Stack evaluation
  -- For implementing stackable
, StackM
, pushStack
, liftNest
, with'
, alloca'
, allocaBytes'
, bracket'
, bracket_'
, finally'
, withForeignPtr'
) where

import Control.Arrow
import Control.Exception
import Control.Monad.Reader

import Foreign

------------------------------------------------------------------------
-- Parameter construction
--

-- When we do a COM invocation, we need to build up an actual set of
-- assembly-level concrete values on the stack. Since everything on
-- the COM stack is at least Word32-aligned, our core stack is of type
-- [Word32].
--
-- We'll do all our stack-building inside the I/O monad, to allow us
-- to manipulate low-level chunks of memory when serialising
-- structures.
--
-- Attempt #1:
--
-- We want to construct a stack, so let's build up the stack with a
-- WriterT monad transformer to hold the built stack:
--
-- type Stack = WriterT [Word32] IO ()
--
-- Attempt #2:
--
-- Hang on, we not only want to build up the stack, but also tear it
-- down. The way to do this is to make an operation X which, when
-- given another operation Y, performs the set-up of X first, runs Y,
-- and then the performs the teardown of X:
--
-- type Stack = WriterT [Word32] IO a -> WriterT [Word32] IO a
--
-- Attempt #3:
--
-- This doesn't work - the core invocation happens at the /innermost/
-- level, not outside, so we actually want to use a ReaderT, not a
-- WriterT, to make the stack available to the COM call, which is the
-- most deeply-nested operation!
--
-- type Stack = ReaderT [Word32] IO a -> ReaderT [Word32] IO a
--
-- Attempt #4:
--
-- This is ok, but doesn't actually allow us to return values. We can
-- make our Stack take a value, and instead of just pass it on, we'll
-- modify it.
--
-- type Stack a b = ReaderT [Word32] IO a -> ReaderT [Word32] IO b
--

type StackM = ReaderT [Word32] IO

type Stack a b = StackM a -> StackM b

-- Stack is an instance of Category, something we use quite a bit.

-- Now we can define the type class for a single parameter. Each
-- parameter can be used in an 'in', 'in by ref', 'out' or 'in-out'
-- context:

-- We add new results to the right, so that they accumulate in the
-- correct order for left-to-right reading of our stack arguments.

class Stackable a where
    -- The interface we want people to use.
    argIn       :: a -> Stack b b
    argInByRef  :: a -> Stack b b
    argInOut    :: a -> Stack b (b ,a)
    argOut      ::      Stack b (b, a)

-- Evaluate a stack.
infix 0 #<
(#<) :: ([Word32] -> IO a) -> Stack a b -> IO b
fn #< stackOp =
    let innerOp = ask >>= (lift . fn)
     in runReaderT (stackOp innerOp) []

-- Put stuff on a stack, then execute the next thing.
pushStack :: [Word32] -> StackM a -> StackM a
pushStack xs = local (xs ++)

------------------------------------------------------------------------
-- Lift various operations into StackM

-- Define a helper to lift IO-based nesting operations into our
-- StackM.
liftNest :: ((a -> IO b) -> IO c) -> ((a -> StackM b) -> StackM c)
liftNest toLift innerOp = do
  env <- ask
  let innerOp' x = runReaderT (innerOp x) env
  lift (toLift innerOp')

-- And then lift some of the most common nesters we use.

with' :: Storable a => a -> (Ptr a -> StackM b) -> StackM b
with' = liftNest . with

alloca' :: Storable a => (Ptr a -> StackM b) -> StackM b
alloca' = liftNest alloca

allocaBytes' :: Int -> (Ptr a -> StackM b) -> StackM b
allocaBytes' = liftNest . allocaBytes

bracket' :: IO a -> (a -> IO b) -> (a -> StackM c) -> StackM c
bracket' a b c = liftNest (\c' -> bracket a b c') c

bracket_' :: IO a -> IO b -> StackM c -> StackM c
bracket_' a b c = liftNest (\c' -> bracket_ a b (c' ())) (const c)

finally' :: StackM a -> IO b -> StackM a
finally' a b = liftNest (\a' -> finally (a' ()) b) (const a)

withForeignPtr' :: ForeignPtr a -> (Ptr a -> StackM b) -> StackM b
withForeignPtr' = liftNest . withForeignPtr

------------------------------------------------------------------------
-- Marshalling of Word/Int types.
--

-- The nice thing about these types are that they are:
-- a) Storable
-- b) Castable to Word32.
-- This makes it easy to write boilerplate for Stackable.

-- NB: Our serialisation using 'fromIntegral' is rather dodgy, but
-- works ok for little-endian systems.

ai :: Integral a => a -> StackM b -> StackM b
ai x f = pushStack [fromIntegral x] f

aibr :: (Stackable a, Storable a) => a -> StackM b -> StackM b
aibr x f = with' x $ \ptr -> argIn ptr f

aio :: (Stackable a, Storable a) => a -> StackM b -> StackM (b, a)
aio x f = with' x $ \ptr -> do
            res <- argIn ptr f
            out <- lift $ peek ptr
            return (res, out)

ao :: (Stackable a, Storable a) => StackM b -> StackM (b, a)
ao f = alloca' $ \ptr -> do
         res <- argIn ptr f
         out <- lift $ peek ptr
         return (res, out)

instance Stackable Word32   where argIn = ai; argInByRef = aibr; argInOut = aio; argOut = ao
instance Stackable Int32    where argIn = ai; argInByRef = aibr; argInOut = aio; argOut = ao
instance Stackable Word16   where argIn = ai; argInByRef = aibr; argInOut = aio; argOut = ao
instance Stackable Int16    where argIn = ai; argInByRef = aibr; argInOut = aio; argOut = ao
instance Stackable Word8    where argIn = ai; argInByRef = aibr; argInOut = aio; argOut = ao
instance Stackable Int8     where argIn = ai; argInByRef = aibr; argInOut = aio; argOut = ao

------------------------------------------------------------------------
-- Marshalling of pointers.
--

-- We can extend the above to cope with pointers. For out parameters,
-- it's polite to initialise the out 'target' with a null pointer.

instance Stackable (Ptr a)  where
    argIn x    = ai (fromIntegral $ x `minusPtr` nullPtr :: Word32)
    argInByRef = aibr
    argInOut   = aio
    argOut     = aio nullPtr

------------------------------------------------------------------------
-- Marshalling of floating point types.
--

floatToRep :: Float -> IO [Word32]
floatToRep f = with f $ \p -> do
    let wp = castPtr p
    rep <- peek wp
    return [rep]

instance Stackable Float  where
    argIn x f  = do rep <- lift $ floatToRep x ; pushStack rep f
    argInByRef = aibr
    argInOut   = aio
    argOut     = ao

doubleToRep :: Double -> IO [Word32]
doubleToRep f = with f $ \p -> do
    let wp = castPtr p
    lo <- peek wp
    hi <- peekElemOff wp 1
    return [lo, hi]

instance Stackable Double  where
    argIn  x f = do rep <- lift $ doubleToRep x ; pushStack rep f
    argInByRef = aibr
    argInOut   = aio
    argOut     = ao

------------------------------------------------------------------------
-- Marshalling of other primitive types.
--

-- Add Bool.
unBool :: Bool -> Word16
unBool x = if x then -1 else 0

mkBool :: (a, Word16) -> (a, Bool)
mkBool = second (/= 0)

instance Stackable Bool where
    argIn      x   =            ai   (unBool x)
    argInByRef x   =            aibr (unBool x)
    argInOut   x f = mkBool <$> aio  (unBool x) f
    argOut       f = mkBool <$> ao              f
