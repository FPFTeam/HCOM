-- This file is licensed under the New BSD License
module SafeArraySpec (safeArraySpec) where

import qualified Data.ByteString.Char8 as B
import Data.Char
import Data.Time
import Foreign
import System.Win32.HCOM

import Test.Hspec
import ISATest

-- Test that passing the array to a COM function which'll then index
-- in is equivalent to looking it up ourselves.
testLookup ptr sa =
  (ptr ~> isatest_4 sa) `shouldReturn` sa ! [3, 4]

-- Compare the before and after SA from a call to isatest_2: The
-- indices and elements should be the same, except the second element,
-- which gets overwritten with 180.
compare2 sa sa' = do
  saBounds sa `shouldBe` saBounds sa'
  length data2 `shouldBe` length data1
  data2 `shouldBe` zipWith f data1 [1..]
  where
    boundsEqual = saBounds sa == saBounds sa'
    data1 = saData sa
    data2 = saData sa'
    f x i = if i == 2
              then 180
              else x

safeArraySpec = {- replicateM_ 10 $ -} beforeAll (coCreate clsid_MySATest) $ do
  it "test lookups" $ \ptr -> do
    testLookup ptr $ SafeArray [(2,4), (3, 4)] [1..6]
    testLookup ptr $ SafeArray [(1,4), (1, 4)] [1..16]
    testLookup ptr $ SafeArray [(0,3), (4, 5)] [1..8]
    testLookup ptr $ SafeArray [(1,4), (4, 5)] [1..8]
    testLookup ptr $ SafeArray [(1,4), (3, 4)] [1..8]
    testLookup ptr $ SafeArray [(1,4), (3, 4)] [1..8]

  -- isatest_[1..3] (used in these tests) test both different
  -- primitive types, and different parameter-passing mechanisms.
  it "testIn" $ \ptr ->
    -- We don't really test much for in parameters, I'm afraid. The COM
    -- server implementation should do the testing, really!
    ptr ~> isatest_1 (SafeArray [(2,4), (3, 4)] [1..6]) -- (SafeArray [(1, 3)] [10, 20, 30])
                `shouldReturn` ()
  it "testInOut" $ \ptr -> do
    let sa = SafeArray [(1, 3)] [100, 200, 300]
    sa' <- ptr ~> isatest_2 sa
    compare2 sa sa'
  it "testOut" $ \ptr -> do
    sa <- ptr ~> isatest_3
    let str = map (chr . fromIntegral) $ saData sa
    str `shouldBe` "foo!1"
  it "testBoundsPreservation" $ \ptr -> do
    let sa = SafeArray [(1, 3), (5,6)] [100, 200, 300, 1000, 2000, 3000]
    sa' <- ptr ~> isatest_2 sa
    compare2 sa sa'
  it "testBool" $ \ptr -> do
    let sa = fromList [True, False, True]
    sa' <- ptr ~> isatest_bool sa
    sa' `shouldBe` sa
  it "testBSTR" $ \ptr -> do
    let sa = fromList ["FOO", "BAR", "Bazzle", ""]
    sa' <- ptr ~> isatest_bstr sa
    sa' `shouldBe` sa
  it "testObj"  $ \ptr -> do
    tmpPtr1 <- coCreate clsid_Scripting_Dictionary
    tmpPtr2 <- snd <$> queryInterface ptr
    let sa = fromList [tmpPtr1, tmpPtr2, nullCOMPtr, tmpPtr1]
    sa' <- ptr ~> isatest_obj sa
    sa' `shouldBe` sa
  it "test Var"  $ \ptr -> do
    tmpPtr <- snd <$> queryInterface ptr
    let sa = fromList [vt (42 :: Int16),
                       vt True,
                       vt "Hello!",
                       vt (tmpPtr :: COMPtr IUnknown)]
    sa' <- ptr ~> isatest_var sa
    sa' `shouldBe` sa
  it "test SafeArray in variant" $ \ptr -> do
    let v = vt $ fromList $ fmap B.pack ["Foo", "Bar", "Barney"]
    v' <- ptr ~> isatest_v v
    v' `shouldBe` v
  it "test SafeArray in variant (2)" $ \ptr -> do
    tmpPtr <- snd <$> queryInterface ptr
    let v = vt $ fromList [vt "Foo",
                           vt False,
                           vt (tmpPtr :: COMPtr IDispatch),
                           vt (1234.567 :: Float),
                           vt (UTCTime (fromGregorian 1979 4 17) (6 * 60 * 60)),
                           VT_NULL,
                           vt (987.432 :: Double)]
    v' <- ptr ~> isatest_v v
    v' `shouldBe` v
