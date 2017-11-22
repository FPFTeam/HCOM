-- This file is licensed under the New BSD License
--
-- IDictionary.hs:
--
-- Interface for IDictionary
--

{-# LANGUAGE EmptyDataDecls #-}

module System.Win32.HCOM.Gen.IDictionary where

import Control.Category ((>>>))
import Data.Word
import System.Win32.HCOM


data IDictionary
instance Interface IDictionary where
    iidOf _ = GUID 0x42c642c1 0x97e1 0x11cf 0x978f 0x00 0xa0 0x24 0x63 0xe0 0x6f

-- FIXME: Plenty missing!

dict_Put :: (ToVariant k, ToVariant v) => k -> v -> COMPtr IDictionary -> IO ()
dict_Put k v dict = vcall dict "dict_Put" 8 $ checkHR >>> vtArgInByRef k >>> vtArgInByRef v

dict_Get :: (ToVariant k, FromVariant r) => k -> COMPtr IDictionary -> IO r
dict_Get k dict = vcall dict "dict_Get" 9 $ checkHR >>> vtArgInByRef k >>> vtArgOut

dict_Count :: COMPtr IDictionary -> IO Word32
dict_Count dict = vcall dict "dict_Count" 11 $ checkHR >>> argOut

dict_Exists :: (ToVariant k) => k -> COMPtr IDictionary -> IO Bool
dict_Exists k dict = vcall dict "dict_Exists" 12 $ checkHR >>> vtArgInByRef k >>> argOut

dict_Keys :: COMPtr IDictionary -> IO [Variant]
dict_Keys dict = fmap (toList1D . unVT) $ vcall dict "dict_Keys" 15 $ checkHR >>> argOut
