-- This file is licensed under the New BSD License
{-# LANGUAGE EmptyDataDecls #-}

--
-- ISATest.hs:
--
-- Interface for ISATest
--

module ISATest where

import Control.Category
import Data.Int
import System.Win32.HCOM
import Foreign

data ISATest
instance Interface ISATest where
    iidOf _ = GUID 0xAF45C527 0x4B2E 0x4030 0x83C1 0x2E 0x99 0x92 0x3F 0x44 0x41

clsid_MySATest = GUID 0x50C1BE3B 0x1298 0x4D57 0xA781 0x22 0x12 0xEB 0xFF 0xD9 0x61
clsid_Scripting_Dictionary = GUID 0xEE09B103 0x97E0 0x11CF 0x978F 0x00 0xA0 0x24 0x63 0xE0 0x6F

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

isatestDouble :: COMPtr ISATest -> Double -> IO Double
isatestDouble ptr v = vcall ptr "isatest_doubleValue" 16 $ checkHR >>> argIn v >>> argOut

isatestInt :: COMPtr ISATest -> Int -> IO Int
isatestInt ptr v = vcall ptr "isatest_intValue" 18 $ checkHR >>> argIn v >>> argOut

isatestInt32 :: COMPtr ISATest -> Int32 -> IO Int32
isatestInt32 ptr v = vcall ptr "isatest_intValue" 18 $ checkHR >>> argIn v >>> argOut

isatestInt64 :: COMPtr ISATest -> Int64 -> IO Int64
isatestInt64 ptr v = vcall ptr "isatest_intValue" 18 $ checkHR >>> argIn v >>> argOut

isatestFloat :: COMPtr ISATest -> Float -> IO Float
isatestFloat ptr v = vcall ptr "isatest_floatValue" 17 $ checkHR >>> argIn v >>> argOut

isatestLong :: COMPtr ISATest -> Int -> IO Int
isatestLong ptr v = vcall ptr "isatest_longValue" 19 $ checkHR >>> argIn v >>> argOut

isatestLongLong :: COMPtr ISATest -> Int -> IO Int
isatestLongLong ptr v = vcall ptr "isatest_longlongValue" 20 $ checkHR >>> argIn v >>> argOut
