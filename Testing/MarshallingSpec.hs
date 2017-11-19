{-# LANGUAGE ScopedTypeVariables #-}
{-# LANGUAGE ViewPatterns #-}
module MarshallingSpec(marshallingSpec) where

import Test.Hspec
import Test.Hspec.QuickCheck
import System.Win32.HCOM
import System.Win32.HCOM.SafeArray

marshallingSpec = safeArraySpec

safeArraySpec = describe "safearray" $ do
  describe "fromList" $ do
    prop "bool" $ \(sa :: [Bool]) ->
      toList(fromList sa) == sa
  describe "marshal" $ do
    prop "bool" $ \((True:) -> sa :: [Bool]) -> do
      msa <- marshalSafeArray $ fromList sa
      sa' <- unmarshalSafeArray msa
      toList sa' `shouldBe` sa
