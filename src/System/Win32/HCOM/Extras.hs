-- This file is licensed under the New BSD License
{-# OPTIONS_GHC -fno-warn-orphans #-}
{-# LANGUAGE OverloadedStrings #-}

--
-- Extras.hs:
--
-- Random helpers built on top of everything else.
--

module System.Win32.HCOM.Extras() where

import Control.Monad.Reader
import Data.String
import Foreign.Ptr
import System.IO.Unsafe

import System.Win32.HCOM.BSTR()
import System.Win32.HCOM.ErrorBase
import System.Win32.HCOM.ErrorUtils
import System.Win32.HCOM.GUID
import System.Win32.HCOM.RawFunctions
import System.Win32.HCOM.Stack

------------------------------------------------------------------------
-- Cheeky unsafe instance to get the CLSID for a string.
--

-- To use from GHCI, ':set -XOverloadedStrings'

instance IsString GUID where
    fromString str = unsafePerformIO $ do
      -- FIXME: Playing with Stackable here is a bit ugly... our stack
      -- entries are Word32s. Should probably be changed back to how
      -- it was!
      flip runReaderT [] $ argIn str $ do
        [strPtrAsNum] <- ask
        lift $ do
          let strPtr = nullPtr `plusPtr` fromIntegral strPtrAsNum
          (res, hr) <- withGUIDOutPtr $ rawCLSIDFromProgID strPtr
          checkHResult (HResult hr)
          return res
