-- This file is licensed under the New BSD License
{-# LANGUAGE EmptyDataDecls #-}

--
-- ISATest.hs:
--
-- Interface for ISATest
--

module ISATest where

import Control.Category
import System.Win32.HCOM
import Foreign

data ISATest
instance Interface ISATest where
    iidOf _ = GUID 0xAF45C527 0x4B2E 0x4030 0x83C1 0x2E 0x99 0x92 0x3F 0x44 0x41

isatest_1 :: SafeArray Int32 -> COMPtr ISATest -> IO ()
isatest_1 sa ptr = do
  vcall ptr "isatest_1" 7 $ checkHR >>> argIn sa

isatest_2 :: SafeArray Int16 -> COMPtr ISATest -> IO (SafeArray Int16)
isatest_2 sa ptr = do
  vcall ptr "isatest_2" 8 $ checkHR >>> argInOut sa

isatest_3 :: COMPtr ISATest -> IO (SafeArray Word8)
isatest_3 ptr = do
  vcall ptr "isatest_3" 9 $ checkHR >>> argOut

isatest_4 :: SafeArray Int32 -> COMPtr ISATest -> IO Int32
isatest_4 sa ptr = do
  vcall ptr "isatest_4" 10 $ checkHR >>> argIn sa >>> argOut

isatest_bool :: SafeArray Bool -> COMPtr ISATest -> IO (SafeArray Bool)
isatest_bool sa ptr = do
  vcall ptr "isatest_bool" 11 $ checkHR >>> argInOut sa

isatest_bstr :: SafeArray String -> COMPtr ISATest -> IO (SafeArray String)
isatest_bstr sa ptr = do
  vcall ptr "isatest_bstr" 12 $ checkHR >>> argInOut sa

isatest_obj :: SafeArray (COMPtr IUnknown) -> COMPtr ISATest -> IO (SafeArray (COMPtr IUnknown))
isatest_obj sa ptr = do
  vcall ptr "isatest_obj" 13 $ checkHR >>> argInOut sa

isatest_var :: SafeArray Variant -> COMPtr ISATest -> IO (SafeArray Variant)
isatest_var sa ptr = do
  vcall ptr "isatest_var" 14 $ checkHR >>> argInOut sa

isatest_v :: Variant -> COMPtr ISATest -> IO Variant
isatest_v v ptr = do
  vcall ptr "isatest_v" 15 $ checkHR >>> argInOut v
