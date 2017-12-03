module Test where

import System.IO
import System.Win32.HCOM
import Test.Hspec

import ISATest
import MarshallingSpec
import SafeArraySpec

main = do
  hSetBuffering stdout NoBuffering
  hSetBuffering stderr NoBuffering
  coRun $ hspec $ do
    describe "vcall" callSpec
    describe "safearray marshall" marshallingSpec
    describe "safearray call" safeArraySpec

callSpec = beforeAll (coCreate clsid_MySATest) $ do
  describe "typed" $ do
    it "[in]int, [out]int" $ \ptr -> isatestInt ptr 10  `shouldReturn` 11
    it "[in]int32, [out]int32" $ \ptr -> isatestInt32 ptr 10  `shouldReturn` 11
    it "[in]int64, [out]int64" $ \ptr -> isatestInt64 ptr 10  `shouldReturn` 11
    it "[in]long, [out]long" $ \ptr -> isatestLong ptr 10  `shouldReturn` 11
    it "[in]long long, [out]long long" $ \ptr -> isatestLongLong ptr 10  `shouldReturn` 11
    it "[in]double, [out]double" $ \ptr -> isatestDouble ptr 10.5  `shouldReturn` 11.5
    it "[in]float, [out]float" $ \ptr -> isatestFloat ptr 10.5  `shouldReturn` 11.5
  describe "variant" $ do
    it "[in]bool, [out]bool" $ callVariant $ vt (False::Bool)
    it "[in]int, [out]int" $ callVariant $ vt (10::Int)
    it "[in]double, [out]double" $ callVariant $ vt (10::Double)
    it "[in]float, [out]float" $ callVariant $ vt (10::Float)

    where
      callVariant arg ptr = do
        res <- ptr ~> isatest_v arg
        res `shouldBe` arg
