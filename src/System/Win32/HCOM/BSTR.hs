-- This file is licensed under the New BSD License
-- For 'instance Stackable String':
{-# LANGUAGE TypeSynonymInstances, FlexibleInstances #-}
-- Ditto.
{-# OPTIONS_GHC -fno-warn-orphans #-}

--
-- BSTR.hs:
--
-- Defines how we marshal strings to and from BSTRs.
--

-- Only export instances.
module System.Win32.HCOM.BSTR() where

import Control.Applicative
import Control.Monad.Trans
import qualified Data.ByteString.Char8    as B
import qualified Data.ByteString.Internal as BI
import Data.Char
import Foreign

import System.Win32.HCOM.RawFunctions
import System.Win32.HCOM.SafeArray
import System.Win32.HCOM.Stack
import System.Win32.HCOM.Tags

------------------------------------------------------------------------
-- BSTR raw marshalling.
--

-- Unlike the marshaling of structures such as as BSTRs and VARIANTs,
-- we're not filling in already-allocated memory, but doing the
-- allocations ourselves and returning a pointer, as the allocation
-- size is dynamic and should be handled by the Win32 API.

-- FIXME: Check return values!

type BSTR = Ptr OLECHAR

marshalBSTR :: String -> IO BSTR
marshalBSTR str = do
  let len = length str
  ptr <- rawSysAllocStringLen nullPtr $ fromIntegral len
  pokeArray ptr $ map (fromIntegral . ord) str
  pokeElemOff ptr len 0
  return ptr

unmarshalBSTR :: BSTR -> IO String
unmarshalBSTR ptr = do
  len <- fromIntegral <$> rawSysStringLen ptr
  if len == 0
   then return ""
   else map (chr . fromIntegral) <$> peekArray (fromIntegral len) ptr

freeBSTR :: BSTR -> IO ()
freeBSTR ptr = void $ rawSysFreeString ptr

marshalBSTR_BS :: B.ByteString -> IO BSTR
marshalBSTR_BS str = do
  let len = B.length str
  ptr <- rawSysAllocStringLen nullPtr $ fromIntegral len
  mapM_ (\i -> pokeElemOff ptr i $ fromIntegral $ ord $ str `B.index` i) [0..len-1]
  pokeElemOff ptr len 0
  return ptr

unmarshalBSTR_BS :: BSTR -> IO B.ByteString
unmarshalBSTR_BS ptr = do
  len <- fromIntegral <$> rawSysStringLen ptr
  if len == 0
   then return B.empty
   else BI.create len (\destPtr -> mapM_ (mv ptr destPtr) [0..len-1])
       where
         mv src dst i = peekElemOff src i >>= pokeElemOff dst i . fromIntegral

------------------------------------------------------------------------
-- Instance of Stackable.
--

instance Stackable String where
    argIn x f = do
      bracket' (marshalBSTR x)
               (freeBSTR)
               (\ptr -> argIn ptr f)

    argInByRef x f = do
      bracket' (marshalBSTR x)
               (freeBSTR)
               (\ptr -> argInByRef ptr f)

    argInOut x f = do
      alloca' $ \ptr -> do
        bracket_' (marshalBSTR x >>= poke ptr)
                  (freeBSTR      =<< peek ptr)
                  (do
                     res <- argIn ptr f
                     str <- lift $ unmarshalBSTR =<< peek ptr
                     return (res, str))

    argOut f = do
      with' nullPtr $ \ptr -> do
        finally' (do
                    res  <- argIn ptr f
                    str  <- lift $ unmarshalBSTR =<< peek ptr
                    return (res, str))
                 (freeBSTR =<< peek ptr)

instance Stackable B.ByteString where
    argIn x f = do
      bracket' (marshalBSTR_BS x)
               (freeBSTR)
               (\ptr -> argIn ptr f)

    argInByRef x f = do
      bracket' (marshalBSTR_BS x)
               (freeBSTR)
               (\ptr -> argInByRef ptr f)

    argInOut x f = do
      alloca' $ \ptr -> do
        bracket_' (marshalBSTR_BS x >>= poke ptr)
                  (freeBSTR         =<< peek ptr)
                  (do
                     res  <- argIn ptr f
                     str  <- lift $ unmarshalBSTR_BS =<< peek ptr
                     return (res, str))

    argOut f = do
      with' nullPtr $ \ptr -> do
        finally' (do
                    res  <- argIn ptr f
                    str  <- lift $ unmarshalBSTR_BS =<< peek ptr
                    return (res, str))
                 (freeBSTR =<< peek ptr)

------------------------------------------------------------------------
-- Instance of COMStorable
--

instance COMStorable String where
    getVarType _ = c_VT_BSTR
    store p x    = marshalBSTR x >>= poke (castPtr p)
    fetch p      = unmarshalBSTR =<< peek (castPtr p)

instance COMStorable B.ByteString where
    getVarType _ = c_VT_BSTR
    store p x    = marshalBSTR_BS x >>= poke (castPtr p)
    fetch p      = unmarshalBSTR_BS =<< peek (castPtr p)
