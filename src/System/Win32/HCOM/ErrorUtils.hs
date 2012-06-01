-- This file is licensed under the New BSD License
{-# LANGUAGE EmptyDataDecls #-}

--
-- ErrorUtils.hs:
--
-- Utility functions for error handling.
--

module System.Win32.HCOM.ErrorUtils
( getErrorInfo
, checkHResult
, checkHR
) where

import Control.Exception
import Control.Monad.Trans
import Control.Monad
import Foreign

import System.Win32.HCOM.BSTR()
import System.Win32.HCOM.COMCall
import System.Win32.HCOM.COMPtr
import System.Win32.HCOM.GUID
import System.Win32.HCOM.RawFunctions
import System.Win32.HCOM.ErrorBase

------------------------------------------------------------------------
-- IErrorInfo interface definition
--

data IErrorInfo
instance Interface IErrorInfo where
    iidOf _ = GUID 0x1CF2B120 0x547D 0x101B 0x8E65 0x08 0x00 0x2B 0x2B 0xD1 0x19

errorInfo_GetGUID        :: COMPtr IErrorInfo -> IO (HRESULT, GUID)
errorInfo_GetGUID        ei = vcall ei "errorInfo_GetGUID"        3 $ argOut

errorInfo_GetSource      :: COMPtr IErrorInfo -> IO (HRESULT, String)
errorInfo_GetSource      ei = vcall ei "errorInfo_GetSource"      4 $ argOut

errorInfo_GetDescription :: COMPtr IErrorInfo -> IO (HRESULT, String)
errorInfo_GetDescription ei = vcall ei "errorInfo_GetDescription" 5 $ argOut

errorInfo_GetHelpFile    :: COMPtr IErrorInfo -> IO (HRESULT, String)
errorInfo_GetHelpFile    ei = vcall ei "errorInfo_GetHelpFile"    6 $ argOut

errorInfo_GetHelpContext :: COMPtr IErrorInfo -> IO (HRESULT, Word32)
errorInfo_GetHelpContext ei = vcall ei "errorInfo_GetHelpContext" 7 $ argOut

------------------------------------------------------------------------
-- Haskell-friendly interface
--

getErrorInfo :: IO (Maybe ErrorInfo)
getErrorInfo = do
  (_, comPtr) <- mkOutParam $ \resPtr -> rawGetErrorInfo 0 resPtr
  if (comPtr /= nullCOMPtr)
   then do
         (_, guid)     <- errorInfo_GetGUID        comPtr
         (_, src)      <- errorInfo_GetSource      comPtr
         (_, desc)     <- errorInfo_GetDescription comPtr
         (_, helpFile) <- errorInfo_GetHelpFile    comPtr
         (_, helpCtx)  <- errorInfo_GetHelpContext comPtr
         return $ Just $ ErrorInfo guid src desc helpFile helpCtx
   else return Nothing

------------------------------------------------------------------------
-- Exception-raising wrapper
--

checkHRInner :: HRESULT -> IO ()
checkHRInner hr = do
  let hr' = HResult hr
  when (failed hr') $ do
               ei <- getErrorInfo
               throwIO . COMException [] $ COMError hr' ei

checkHR :: Stack ((), HRESULT) ()
checkHR = (>>= (lift . checkHRInner . snd)) where

checkHResult :: HResult -> IO ()
checkHResult (HResult hr) = checkHRInner hr
