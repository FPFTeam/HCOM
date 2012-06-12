-- This file is licensed under the New BSD License
{-# LANGUAGE OverloadedStrings #-}

--
-- GUID.hs:
--
-- Defines the Haskell equivalent of 'GUID'.
--

module System.Win32.HCOM.GUID
( -- Types
  GUID(..)
, IID
, CLSID
  -- Marshalling
, withGUIDPtr
, withGUIDOutPtr
) where

import Control.Exception
import Control.Monad.Reader
import Foreign
import Text.Printf

import System.Win32.HCOM.RawFunctions
import System.Win32.HCOM.Stack

------------------------------------------------------------------------
-- GUID data definitions and marshalling.
--

-- | We try to match the Windows representation as closely as possible.
data GUID = GUID Word32
                 Word16 Word16 Word16
                 Word8 Word8 Word8 Word8 Word8 Word8
            deriving (Eq, Ord)

-- Some type synonyms.
type IID   = GUID
type CLSID = GUID

sizeofGUID :: Int
sizeofGUID = 16

-- FIXME: Use Foreign.Marhal.Array!

marshalGUID :: GUID -> Ptr RawGUID -> IO ()
marshalGUID (GUID a x y z m n o p q r) ptr = do
  pokeElemOff (castPtr ptr :: Ptr Word32) 0 a

  -- z is byteswapped.
  let z' = (z `shiftR` 8) .|. (z `shiftL` 8)

  pokeArray (castPtr $ ptr `plusPtr` 4  :: Ptr Word16)
            [x, y, z']
  pokeArray (castPtr $ ptr `plusPtr` 10 :: Ptr Word8)
            [m,  n,  o,  p,  q,  r ]

unmarshalGUID :: Ptr RawGUID -> IO GUID
unmarshalGUID ptr = do
  a <- peekElemOff (castPtr ptr :: Ptr Word32) 0

  [x, y, z] <-
      peekArray 3 (castPtr $ ptr `plusPtr` 4  :: Ptr Word16)
  [m,  n,  o,  p,  q,  r ] <-
      peekArray 6 (castPtr $ ptr `plusPtr` 10 :: Ptr Word8)

  -- z still byte-swapped.
  let z' = (z `shiftR` 8) .|. (z `shiftL` 8)

  return $ GUID a x y z' m n o p q r

freeGUID :: Ptr RawGUID -> IO ()
freeGUID _ = return ()

instance Show GUID where
    show (GUID a x y z m n o p q r) =
        printf "{%08X-%04X-%04X-%04X-%02X%02X%02X%02X%02X%02X}"
               a x y z m n o p q r

------------------------------------------------------------------------
-- Function to serialize GUIDs for use in Functions.hs.
--

-- FIXME: Unpleasantly large overlap with the Stackable instance.

withGUIDPtr :: GUID -> (Ptr RawGUID -> IO a) -> IO a
withGUIDPtr guid f = do
  allocaBytes sizeofGUID $ \ptr -> do
                        bracket_ (marshalGUID guid ptr)
                                 (freeGUID ptr)
                                 (f ptr)

withGUIDOutPtr :: (Ptr RawGUID -> IO a) -> IO (GUID, a)
withGUIDOutPtr f = do
  allocaBytes sizeofGUID $ \ptr -> do
                     finally (do
                                res <- f ptr
                                guid <- unmarshalGUID ptr
                                return (guid, res))
                             (freeGUID ptr)

------------------------------------------------------------------------
-- Instance of Stackable.
--

instance Stackable GUID where
    argIn x f = do
      allocaBytes' sizeofGUID $ \ptr -> do
         bracket_' (marshalGUID x ptr)
                   (freeGUID      ptr)
                   (do
                      -- GUID takes 4 words of the stack.
                      elts <- lift $ peekArray 4 $ castPtr ptr
                      pushStack elts f)

    argInByRef x f = do
      allocaBytes' sizeofGUID $ \ptr -> do
         bracket_' (marshalGUID x ptr)
                   (freeGUID      ptr)
                   (argIn ptr f)

    argInOut x f = do
      allocaBytes' sizeofGUID $ \ptr -> do
         bracket_' (marshalGUID x ptr)
                   (freeGUID      ptr)
                   (do
                      res <- argIn ptr f
                      var <- lift $ unmarshalGUID ptr
                      return (res, var))

    argOut f = do
      allocaBytes' sizeofGUID $ \ptr -> do
         finally' (do
                     res <- argIn ptr f
                     var <- lift $ unmarshalGUID ptr
                     return (res, var))
                   (freeGUID ptr)
