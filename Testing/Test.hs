module Test where

import Test.Hspec
import SafeArraySpec
import MarshallingSpec

main = hspec $ do
  safeArraySpec
  marshallingSpec
