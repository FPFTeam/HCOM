-- This file is licensed under the New BSD License
{-# LANGUAGE TypeSynonymInstances, FlexibleInstances #-}
--
-- SafeArray.hs:
--
-- Defines the Haskell equivalent of 'SAFEARRAY'.
--

-- Very short exports list, as everything else is done through the
-- Stackable instance.
module System.Win32.HCOM.SafeArray
( -- Our 'Storable' interface.
  COMStorable(..)
  -- SafeArrays hold COMStorable items.
, SafeArray(..)
, newSafeArray
, newSafeArrayM
, fromList
, toList
, fromList2D
, toList2D
, (!)
) where

import Control.Applicative
import Control.Monad.Identity
import Control.Monad.Trans
import Data.Time
import Data.List
import Foreign

import System.Win32.HCOM.ErrorBase
import System.Win32.HCOM.RawFunctions
import System.Win32.HCOM.Stack
import System.Win32.HCOM.Tags

------------------------------------------------------------------------
-- Type class for things which can be placed in a SafeArray.
--

-- 'COMStorable' values are those that can be stored in a SafeArray. We
-- need to know their variant tag, and how to read and write them. We
-- don't use 'Storable' directly, since we don't wish to create
-- Storable instances with COM-specific serialisation.

-- It would be nice to unify this code with the Stackable instances.
-- However, the conventions are rather different between the stack and
-- storage in packed, variable-element-size structures like
-- SAFEARRAYs.

-- For example, Variants are always accessed by reference on the
-- stack, but can be stored as values in a SafeArray. Shorts are
-- packed in a SafeArray, but not on the stack.

-- So, we don't actually bother unifying our SAFEARRAY and stack
-- serialisation type classes. The actual serialisation
-- implementations for the different types are generally shared behind
-- the scenes.

class COMStorable a where
    getVarType :: a -> VARTYPE
    store :: Ptr a -> a -> IO ()
    fetch :: Ptr a -> IO a

-- We support all the types needed to support the VT_ARRAY types in
-- our Variant implementation.

instance COMStorable Int16      where getVarType _ = c_VT_I2;   store = poke; fetch = peek
instance COMStorable Int32      where getVarType _ = c_VT_I4;   store = poke; fetch = peek
instance COMStorable Float      where getVarType _ = c_VT_R4;   store = poke; fetch = peek
instance COMStorable Double     where getVarType _ = c_VT_R8;   store = poke; fetch = peek
instance COMStorable Int8       where getVarType _ = c_VT_I1;   store = poke; fetch = peek
instance COMStorable Word8      where getVarType _ = c_VT_UI1;  store = poke; fetch = peek
instance COMStorable Word16     where getVarType _ = c_VT_UI2;  store = poke; fetch = peek
instance COMStorable Word32     where getVarType _ = c_VT_UI4;  store = poke; fetch = peek
instance COMStorable Word64     where getVarType _ = c_VT_UI8;  store = poke; fetch = peek
instance COMStorable Int64      where getVarType _ = c_VT_I8;   store = poke; fetch = peek
instance COMStorable Int        where getVarType _ = c_VT_INT;  store = poke; fetch = peek
instance COMStorable Word       where getVarType _ = c_VT_UINT; store = poke; fetch = peek

instance COMStorable Bool where
    getVarType _ = c_VT_BOOL
    store p x    = poke (castPtr p) (if x then -1 else 0 :: Int16)
    fetch p      = (/= (0 :: Int16)) <$> peek (castPtr p)

instance COMStorable HResult where
    getVarType _         = c_VT_ERROR
    store p (HResult hr) = poke (castPtr p) hr
    fetch p              = HResult <$> fetch (castPtr p)

-- A bit more work is required to support dates...

excelEpoch :: Day
excelEpoch = fromGregorian 1899 12 30

-- Ignore leap seconds, I'm afraid!
dayLength :: DiffTime
dayLength = secondsToDiffTime $ 60 * 60 * 24

diffToDbl :: DiffTime -> Double
diffToDbl = fromRational . toRational

instance COMStorable UTCTime where
    getVarType _ = c_VT_DATE
    store p t = poke (castPtr p :: Ptr Double) $ dayNum + dayFract
        where
          dayNum   = fromIntegral $ utctDay t `diffDays` excelEpoch
          dayFract = diffToDbl (utctDayTime t) / diffToDbl dayLength
    fetch p = do
      t <- peek (castPtr p :: Ptr Double)
      let (dayNum, dayFract) = properFraction t
          utcDays  = addDays dayNum excelEpoch
          utcFract = secondsToDiffTime $ round $
                     dayFract * diffToDbl dayLength
      return $ UTCTime utcDays utcFract

-- Currently unsupported types that can go in a VARIANT are:
-- * VT_CY
-- * VT_DECIMAL
-- * VT_RECORD

-- The instances for BSTRs, CCOMPtr IUnknown/IDispatch and Variant are
-- in the appropriate files.

------------------------------------------------------------------------
-- SafeArray data definitions.
--

type SAIndex = Int

-- (Lower bound, upper bound)
type SABound = (SAIndex, SAIndex)

data SafeArray a = SafeArray
    {
     -- A set of dimensional bounds, specified least-significant
     -- first. In C terms, the bounds are specified in right-to-left
     -- order. This is consistent with SafeArrayCreate and
     -- SafeArrayGetElement, but not with the ordering inside the
     -- SAFEARRAY structure itself. Nice.
     saBounds :: [SABound],
     -- The data, in a flattened format.
     saData :: [a]
    } deriving (Show, Eq, Ord)

------------------------------------------------------------------------
-- SafeArray accessor functions.
--

-- Create a safe array from the provided bounds and function,
-- monadically. (Supplying a monad gives us plenty of flexibility).
newSafeArrayM :: Monad m => [SABound] -> ([SAIndex] -> m a) -> m (SafeArray a)
newSafeArrayM bounds f = do
  elts <- mapM f (genIndices bounds)
  return $ SafeArray bounds elts
      where
        genIndices [] = [[]]
        genIndices ((lbound, ubound) : xs) =
            [(y:ys) | y <- [lbound..ubound], ys <- genIndices xs]

-- Now the non-monadic version.
newSafeArray :: [SABound] -> ([SAIndex] -> a) -> SafeArray a
newSafeArray bounds f = runIdentity $ newSafeArrayM bounds (return . f)

-- A simple 1d SafeArray creator.
fromList :: [a] -> SafeArray a
fromList elts = SafeArray [(0, length elts - 1)] elts

-- A conversion to a list.
toList :: SafeArray a -> [a]
toList (SafeArray [_] elts) = elts
toList _                    = throwHCOM "Can't convert a multi-dimensional Safe Array to a list."

-- A simple 2d SafeArray creator.
fromList2D :: [[a]] -> SafeArray a
fromList2D elts =
    if not $ all (\x -> length x == length (head elts)) elts
     then throwHCOM "All sub-lists must be of the same length."
     else SafeArray [ (0, length (head elts) - 1)
                    , (0, length elts        - 1)]
                    (concat elts)

-- Convert a 2d SafeArray to nested lists.
toList2D :: SafeArray a -> [[a]]
toList2D (SafeArray [(l, u), _] elts) =
  let len = u - l + 1
   in unfoldr (\x -> if null x
                      then Nothing
                      else Just $ splitAt len x) elts
toList2D _ = throwHCOM "'toList2D' only works on 2D Safe Arrays!"

-- Get element from an arbitrarily-dimensioned safe array
(!) :: SafeArray a -> [SAIndex] -> a
sa ! indices = saData sa !! offset where
    -- Fold relies on our indices being ordered least-sig to most-sig.
    (offset, _) = foldl' f (0, 1) $ zip indices (saBounds sa)
    -- We move from an /index/ into the /size/ element n-dimensional
    -- array into the same in the n+1-dimensional array.
    f (offset, size) (idx, (lbound, ubound)) =
        (offset + size * idx', size * count)
            where
              -- Generate a zero-based index.
              idx' = if idx > ubound || idx < lbound
                     then throwHCOM "Index out of bounds"
                     else idx - lbound
              -- Number of elements in this dimension.
              count = ubound - lbound + 1

------------------------------------------------------------------------
-- SAFEARRAY field accessors.
--

saGetDims :: Ptr SAFEARRAY -> IO Word16
saGetDims sa = peekByteOff sa 0

saGetEltSize :: Ptr SAFEARRAY -> IO Word32
saGetEltSize sa = peekByteOff sa 4

saGetData :: Ptr SAFEARRAY -> IO (Ptr a)
saGetData sa = peekByteOff sa 12

saGetBounds :: Ptr SAFEARRAY -> Ptr Word32
saGetBounds sa = castPtr $ sa `plusPtr` 16

numElts :: [SABound] -> Int
numElts sa = product $ map (\(l, u) ->  u - l + 1) sa

------------------------------------------------------------------------
-- Functions to marshal/unmarshal into given memory.
--

-- The marshalling functions generate pointers to SAFEARRAYs. We don't
-- populate a pre-allocated piece of memory as the size of the
-- allocation depends on the number of dimensions, and the allocation
-- is handled by the Windows API anyway.

marshalSafeArray :: COMStorable a => SafeArray a -> IO (Ptr SAFEARRAY)
marshalSafeArray sa = do
  -- Sanity-check that number of elements matches bounds.
  let numElts1 = numElts $ saBounds sa
      numElts2 = length  $ saData   sa
  when (numElts1 /= numElts2) $
       throwHCOM "Trying to marshal bad-sized SafeArray."

  -- Allocate the bounds (each bound is #elts and lower bound - 2
  -- 32-bit words).
  allocaArray (2 * length (saBounds sa)) $ \boundsPtr -> do
      -- Fill the bounds in.
      let boundsList = concatMap (\(l, u) ->
                                      [fromIntegral $ u - l + 1,
                                       fromIntegral $ l])
                                 (saBounds sa)
      pokeArray boundsPtr boundsList

      -- Create the SAFEARRAY
      saPtr <- rawSafeArrayCreate (getVarType $ head $ saData sa)
                                  (fromIntegral $ length $ saBounds sa)
                                  boundsPtr

      -- Get start of data, and size of elements in bytes.
      pvData  <- saGetData saPtr
      eltSize <- fromIntegral <$> saGetEltSize saPtr

      -- And write!
      let eltWriter i d = store (pvData `plusPtr` (i * eltSize)) d
      zipWithM_ eltWriter [0..] (saData sa)

      return saPtr

unmarshalSafeArray :: COMStorable a => Ptr SAFEARRAY -> IO (SafeArray a)
unmarshalSafeArray saPtr = do
  -- Extract the bounds.
  cDims <- fromIntegral <$> saGetDims saPtr
  boundsList <- peekArray (cDims * 2) $ saGetBounds saPtr
  let deBound (count : lb : rest) =
          (fromIntegral lb, fromIntegral $ lb + count - 1) : deBound rest
      deBound [_] = []
      deBound []  = []
  -- Nuttily, the SAFEARRAY structure stores the bounds in the reverse
  -- order compared to those used by SafeArrayCreate!
  let bounds = reverse $ deBound boundsList

  -- Extract contents
  pvData <- saGetData saPtr
  let eltCount = numElts bounds
  eltSize <- fromIntegral <$> saGetEltSize saPtr
  let eltReader i = fetch $ pvData `plusPtr` (i * eltSize)
  vals <- mapM eltReader [0..eltCount-1]

  return $ SafeArray { saBounds = bounds
                     , saData   = vals
                     }

freeSafeArray :: Ptr SAFEARRAY -> IO ()
freeSafeArray ptr = do
  rawSafeArrayDestroy ptr

------------------------------------------------------------------------
-- Instance of Stackable.
--

instance COMStorable a => Stackable (SafeArray a) where
    argIn x f = do
      bracket' (marshalSafeArray x)
               (freeSafeArray)
               (\ptr -> argIn ptr f)

    argInByRef x f = do
      bracket' (marshalSafeArray x)
               (freeSafeArray)
               (\ptr -> argInByRef ptr f)

    argInOut x f = do
      alloca' $ \ptr -> do
        bracket_' (marshalSafeArray x >>= poke ptr)
                  (freeSafeArray      =<< peek ptr)
                  (do
                     res <- argIn ptr f
                     sa  <- lift $ unmarshalSafeArray =<< peek ptr
                     return (res, sa))

    argOut f = do
      with' nullPtr $ \ptr -> do
        finally' (do
                    res <- argIn ptr f
                    sa  <- lift $ unmarshalSafeArray =<< peek ptr
                    return (res, sa))
                 (freeSafeArray =<< peek ptr)

------------------------------------------------------------------------
-- Safearrays are themselves storable, so we can place them inside
-- Variants.
--

instance COMStorable a => COMStorable (SafeArray a) where
    getVarType x = getVarType (getEltType x) .|. c_VT_ARRAY where
        getEltType :: SafeArray a -> a
        getEltType = undefined
    store p x = marshalSafeArray x >>= poke (castPtr p)
    fetch p   = unmarshalSafeArray =<< peek (castPtr p)
