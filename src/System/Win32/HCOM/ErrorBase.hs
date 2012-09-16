-- This file is licensed under the New BSD License
{-# LANGUAGE DeriveDataTypeable, CPP #-}

--
-- ErrorBase.hs:
--
-- Base structures and functions for error handling.
--

module System.Win32.HCOM.ErrorBase
( HResult(..)
, e_FAIL
, failed
, succeeded
, ErrorInfo(..)
, COMError(..)
, COMException(..)
, throwHCOM
, inContext
) where

#if ! MIN_VERSION_base(4,6,0)
import Prelude hiding (catch)
#endif
import Control.Exception
import Control.Applicative
import Data.Char
import Data.Typeable
import Foreign hiding (unsafePerformIO)
import Text.Printf
import System.IO.Unsafe (unsafePerformIO)

import System.Win32.HCOM.RawFunctions
import System.Win32.HCOM.GUID

------------------------------------------------------------------------
-- HResult data type.
--

newtype HResult = HResult HRESULT
    deriving (Typeable, Eq, Ord)

instance Show HResult where
    show (HResult hr) = printf "0x%08x: %s"
                               hr
                               (unsafePerformIO $ stringForErrNo hr)

------------------------------------------------------------------------
-- Helper functions
--

e_FAIL :: HResult
e_FAIL = HResult 0x80004005

failed :: HResult -> Bool
failed (HResult x) = x .&. 0x80000000 /= 0

succeeded :: HResult -> Bool
succeeded = not . failed

------------------------------------------------------------------------
-- Error message extraction.
--

c_FORMAT_MESSAGE_ALLOCATE_BUFFER = 0x00000100 :: DWORD
c_FORMAT_MESSAGE_FROM_SYSTEM     = 0x00001000 :: DWORD
c_FORMAT_MESSAGE_IGNORE_INSERTS  = 0x00000200 :: DWORD

stringForErrNo :: HRESULT -> IO String
stringForErrNo hr = do
  bracket (alloca $ \strPtrDest ->
               do
                 i <- rawFormatMessageA (c_FORMAT_MESSAGE_ALLOCATE_BUFFER .|.
                                         c_FORMAT_MESSAGE_FROM_SYSTEM     .|.
                                         c_FORMAT_MESSAGE_IGNORE_INSERTS)
                                        nullPtr hr 0 strPtrDest 0 nullPtr
                 if i /= 0
                  then peek strPtrDest
                  else return nullPtr)
          (rawLocalFree . castPtr)
          (\strPtr -> if strPtr /= nullPtr
                      then map (chr . fromIntegral) <$> peekArray0 0 strPtr
                      else return "<Unknown error code>")

------------------------------------------------------------------------
-- ErrorInfo structure.
--

data ErrorInfo = ErrorInfo
    { eiGUID     :: GUID
    , eiSource   :: String
    , eiDesc     :: String
    , eiHelpFile :: String
    , eiHelpCtx  :: Word32
    } deriving (Typeable, Eq, Ord)

-- Gets to the nub of what people want to see in practice!
instance Show ErrorInfo where
    show ei = eiSource ei ++ ": " ++ eiDesc ei

------------------------------------------------------------------------
-- COM error value
--

data COMError
    = COMError  HResult (Maybe ErrorInfo)
    | HCOMError String
    deriving (Typeable, Eq, Ord)

instance Show COMError where
    show (COMError hr (Just ei)) = show hr ++ ' ' : show ei
    show (COMError hr Nothing)   = show hr
    show (HCOMError msg)         = msg

------------------------------------------------------------------------
-- COM exception value
--

data COMException = COMException [String] COMError
                  deriving (Typeable, Eq, Ord)

instance Exception COMException

instance Show COMException where
    show (COMException context err) =
        "COM Exception: " ++ show err ++
        concatMap ("\nin " ++) (reverse context)

------------------------------------------------------------------------
-- Utility functions
--

throwHCOM :: String -> a
throwHCOM = throw . COMException [] . HCOMError

inContext :: String -> IO a -> IO a
inContext ctx action =
    action `catch`
               \(COMException ctxs err) -> throw $ COMException (ctx:ctxs) err
