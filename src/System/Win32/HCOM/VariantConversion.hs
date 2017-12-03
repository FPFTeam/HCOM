-- This file is licensed under the New BSD License
{-# LANGUAGE FlexibleInstances, TypeSynonymInstances #-}

--
-- VariantConversion.hs:
--
-- Defines classes to conver to and from Variants.
--

module System.Win32.HCOM.VariantConversion
( ToVariant(..)
, FromVariant(..)
, vtArgIn
, vtArgInByRef
, vtvtArgIn
, vtArgInOut
, vtArgOut
) where

import Control.Arrow
import qualified Data.ByteString.Char8 as B
import Data.Time
import Data.Ratio
import Foreign

import System.Win32.HCOM.BSTR()
import System.Win32.HCOM.COMPtr
import System.Win32.HCOM.ErrorBase
import System.Win32.HCOM.SafeArray
import System.Win32.HCOM.Variant
import System.Win32.HCOM.Stack

------------------------------------------------------------------------
-- | Type class to simplify variant construction.
--

class ToVariant a where
    vt     :: a -> Variant

instance ToVariant Variant                        where vt = id
instance ToVariant Int16                          where vt = VT_I2
instance ToVariant Int32                          where vt = VT_I4
instance ToVariant Int64                          where vt = VT_I8
instance ToVariant Float                          where vt = VT_R4
instance ToVariant Double                         where vt = VT_R8
instance ToVariant UTCTime                        where vt = VT_DATE
instance ToVariant Day                            where vt = VT_DATE . flip UTCTime 0 
instance ToVariant String                         where vt = VT_BSTR . B.pack
instance ToVariant B.ByteString                   where vt = VT_BSTR
instance ToVariant HResult                        where vt = VT_ERROR
instance ToVariant Bool                           where vt = VT_BOOL
instance ToVariant (COMPtr i)                     where vt = VT_UNKNOWN . qiChecked
instance ToVariant Int8                           where vt = VT_I1
instance ToVariant Word8                          where vt = VT_UI1
instance ToVariant Word16                         where vt = VT_UI2
instance ToVariant Word32                         where vt = VT_UI4
instance ToVariant Word64                         where vt = VT_UI8
instance ToVariant Int                            where vt = VT_INT
instance ToVariant Word                           where vt = VT_UINT
instance ToVariant (SafeArray Int16)              where vt = VT_I2a
instance ToVariant (SafeArray Int32)              where vt = VT_I4a
instance ToVariant (SafeArray Int64)              where vt = VT_I8a
instance ToVariant (SafeArray Float)              where vt = VT_R4a
instance ToVariant (SafeArray Double)             where vt = VT_R8a
instance ToVariant (SafeArray UTCTime)            where vt = VT_DATEa
instance ToVariant (SafeArray B.ByteString)       where vt = VT_BSTRa
instance ToVariant (SafeArray (COMPtr IDispatch)) where vt = VT_DISPATCHa
instance ToVariant (SafeArray HResult)            where vt = VT_ERRORa
instance ToVariant (SafeArray Bool)               where vt = VT_BOOLa
instance ToVariant (SafeArray Variant)            where vt = VT_VARIANTa
instance ToVariant (SafeArray (COMPtr IUnknown))  where vt = VT_UNKNOWNa
instance ToVariant (SafeArray Int8)               where vt = VT_I1a
instance ToVariant (SafeArray Word8)              where vt = VT_UI1a
instance ToVariant (SafeArray Word16)             where vt = VT_UI2a
instance ToVariant (SafeArray Word32)             where vt = VT_UI4a
instance ToVariant (SafeArray Word64)             where vt = VT_UI8a
instance ToVariant (SafeArray Int)                where vt = VT_INTa
instance ToVariant (SafeArray Word)               where vt = VT_UINTa

-- We need to add individual instances for lists rather than [a] to avoid clash
-- with String. The trick used in Show doesn't work here as we don't support
-- nested lists or raw characters.
instance ToVariant [Int16]                        where vt = VT_I2a       . fromList1D
instance ToVariant [Int32]                        where vt = VT_I4a       . fromList1D
instance ToVariant [Int64]                        where vt = VT_I8a       . fromList1D
instance ToVariant [Float]                        where vt = VT_R4a       . fromList1D
instance ToVariant [Double]                       where vt = VT_R8a       . fromList1D
instance ToVariant [UTCTime]                      where vt = VT_DATEa     . fromList1D
instance ToVariant [Day]                          where vt = VT_DATEa     . fromList1D . map (flip UTCTime 0)
instance ToVariant [String]                       where vt = VT_BSTRa     . fromList1D . map B.pack
instance ToVariant [B.ByteString]                 where vt = VT_BSTRa     . fromList1D
instance ToVariant [HResult]                      where vt = VT_ERRORa    . fromList1D
instance ToVariant [Bool]                         where vt = VT_BOOLa     . fromList1D
instance ToVariant [Variant]                      where vt = VT_VARIANTa  . fromList1D
instance ToVariant [COMPtr a]                     where vt = VT_UNKNOWNa  . fromList1D . map qiChecked
instance ToVariant [Int8]                         where vt = VT_I1a       . fromList1D
instance ToVariant [Word8]                        where vt = VT_UI1a      . fromList1D
instance ToVariant [Word16]                       where vt = VT_UI2a      . fromList1D
instance ToVariant [Word32]                       where vt = VT_UI4a      . fromList1D
instance ToVariant [Word64]                       where vt = VT_UI8a      . fromList1D
instance ToVariant [Int]                          where vt = VT_INTa      . fromList1D
instance ToVariant [Word]                         where vt = VT_UINTa     . fromList1D

------------------------------------------------------------------------
-- | Type class to simplify variant extraction.
--

class FromVariant a where
    unVT     :: Variant -> a

-- Extract scalar values.
instance FromVariant Variant                        where unVT = id
instance FromVariant Int16                          where unVT (VT_I2        x) =              x; unVT _ = unVTErr
instance FromVariant Int32                          where unVT (VT_I4        x) =              x; unVT _ = unVTErr
instance FromVariant Int64                          where unVT (VT_I8        x) =              x; unVT _ = unVTErr
instance FromVariant Float                          where unVT (VT_R4        x) =              x;
                                                          unVT (VT_DECIMAL   x) = fromRational x; unVT _ = unVTErr
instance FromVariant Double                         where unVT (VT_R8        x) =              x;
                                                          unVT (VT_DECIMAL   x) = fromRational x; unVT _ = unVTErr
instance FromVariant UTCTime                        where unVT (VT_DATE      x) =              x; unVT _ = unVTErr
instance FromVariant Day                            where unVT (VT_DATE      x) = utctDay      x; unVT _ = unVTErr
instance FromVariant String                         where unVT (VT_BSTR      x) = B.unpack     x; unVT _ = unVTErr
instance FromVariant B.ByteString                   where unVT (VT_BSTR      x) =              x; unVT _ = unVTErr
instance Interface i => FromVariant (COMPtr i)      where unVT (VT_DISPATCH  x) = qiChecked    x;
                                                          unVT (VT_UNKNOWN   x) = qiChecked    x; unVT _ = unVTErr
instance FromVariant HResult                        where unVT (VT_ERROR     x) =              x; unVT _ = unVTErr
instance FromVariant Bool                           where unVT (VT_BOOL      x) =              x; unVT _ = unVTErr
instance FromVariant Int8                           where unVT (VT_I1        x) =              x; unVT _ = unVTErr
instance FromVariant Word8                          where unVT (VT_UI1       x) =              x; unVT _ = unVTErr
instance FromVariant Word16                         where unVT (VT_UI2       x) =              x; unVT _ = unVTErr
instance FromVariant Word32                         where unVT (VT_UI4       x) =              x; unVT _ = unVTErr
instance FromVariant Word64                         where unVT (VT_UI8       x) =              x; unVT _ = unVTErr
instance FromVariant Int                            where unVT (VT_INT       x) =              x;
                                                          unVT (VT_I2        x) = fromIntegral x;
                                                          unVT (VT_I4        x) = fromIntegral x;
                                                          unVT (VT_I8        x) = fromIntegral x;
                                                          unVT (VT_I1        x) = fromIntegral x;
                                                          unVT (VT_UI1       x) = fromIntegral x;
                                                          unVT (VT_UI2       x) = fromIntegral x;
                                                          unVT (VT_UI4       x) = fromIntegral x;
                                                          unVT (VT_DECIMAL   x) | denominator x == 1 = fromIntegral . numerator $ x;
                                                          unVT _ = unVTErr
instance FromVariant Word                           where unVT (VT_UINT      x) = x
                                                          unVT (VT_UI1       x) = fromIntegral x;
                                                          unVT (VT_UI2       x) = fromIntegral x;
                                                          unVT (VT_UI4       x) = fromIntegral x;
                                                          unVT (VT_UI8       x) = fromIntegral x; unVT _ = unVTErr
instance FromVariant Integer                        where unVT (VT_INT       x) = fromIntegral x;
                                                          unVT (VT_I2        x) = fromIntegral x;
                                                          unVT (VT_I4        x) = fromIntegral x;
                                                          unVT (VT_I8        x) = fromIntegral x;
                                                          unVT (VT_I1        x) = fromIntegral x;
                                                          unVT (VT_UI1       x) = fromIntegral x;
                                                          unVT (VT_UI2       x) = fromIntegral x;
                                                          unVT (VT_UI4       x) = fromIntegral x;
                                                          unVT (VT_UI8       x) = fromIntegral x;
                                                          unVT (VT_DECIMAL   x) | denominator x == 1 = fromIntegral . numerator $ x;
                                                          unVT _ = unVTErr

-- Extract simple safearrays.
instance FromVariant (SafeArray Int16)              where unVT (VT_I2a       x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Int32)              where unVT (VT_I4a       x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Int64)              where unVT (VT_I8a       x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Float)              where unVT (VT_R4a       x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Double)             where unVT (VT_R8a       x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray UTCTime)            where unVT (VT_DATEa     x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray B.ByteString)       where unVT (VT_BSTRa     x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray (COMPtr IDispatch)) where unVT (VT_DISPATCHa x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray HResult)            where unVT (VT_ERRORa    x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Bool)               where unVT (VT_BOOLa     x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Variant)            where unVT (VT_VARIANTa  x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray (COMPtr IUnknown))  where unVT (VT_UNKNOWNa  x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Int8)               where unVT (VT_I1a       x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Word8)              where unVT (VT_UI1a      x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Word16)             where unVT (VT_UI2a      x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Word32)             where unVT (VT_UI4a      x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Word64)             where unVT (VT_UI8a      x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Int)                where unVT (VT_INTa      x) = x; unVT _ = unVTErr
instance FromVariant (SafeArray Word)               where unVT (VT_UINTa     x) = x; unVT _ = unVTErr

-- Extract lists of values.
instance FromVariant [Int16]                        where unVT (VT_I2a       x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Int32]                        where unVT (VT_I4a       x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Int64]                        where unVT (VT_I8a       x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Float]                        where unVT (VT_R4a       x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Double]                       where unVT (VT_R8a       x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [UTCTime]                      where unVT (VT_DATEa     x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Day]                          where unVT (VT_DATEa     x) = map utctDay  . toList1D     $ x; unVT x = unVTVa x
instance FromVariant [String]                       where unVT (VT_BSTRa     x) = map B.unpack . toList1D     $ x; unVT x = unVTVa x
instance FromVariant [B.ByteString]                 where unVT (VT_BSTRa     x) = toList1D                      x; unVT x = unVTVa x
instance Interface i => FromVariant [COMPtr i]      where unVT (VT_DISPATCHa x) = map qiChecked . toList1D    $ x
                                                          unVT (VT_UNKNOWNa  x) = map qiChecked . toList1D    $ x; unVT x = unVTVa x
instance FromVariant [HResult]                      where unVT (VT_ERRORa    x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Bool]                         where unVT (VT_BOOLa     x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Variant]                      where unVT (VT_VARIANTa  x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Int8]                         where unVT (VT_I1a       x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Word8]                        where unVT (VT_UI1a      x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Word16]                       where unVT (VT_UI2a      x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Word32]                       where unVT (VT_UI4a      x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Word64]                       where unVT (VT_UI8a      x) = toList1D                      x; unVT x = unVTVa x
instance FromVariant [Int]                          where unVT (VT_INTa      x) = toList1D                      x
                                                          unVT (VT_I2a       x) = map fromIntegral . toList1D $ x
                                                          unVT (VT_I4a       x) = map fromIntegral . toList1D $ x
                                                          unVT (VT_I8a       x) = map fromIntegral . toList1D $ x
                                                          unVT (VT_I1a       x) = map fromIntegral . toList1D $ x
                                                          unVT (VT_UI1a      x) = map fromIntegral . toList1D $ x
                                                          unVT (VT_UI2a      x) = map fromIntegral . toList1D $ x;
                                                          unVT (VT_UI4a      x) = map fromIntegral . toList1D $ x; unVT x = unVTVa x
instance FromVariant [Word]                         where unVT (VT_UINTa     x) = toList1D x
                                                          unVT (VT_UI1a      x) = map fromIntegral . toList1D $ x
                                                          unVT (VT_UI2a      x) = map fromIntegral . toList1D $ x
                                                          unVT (VT_UI4a      x) = map fromIntegral . toList1D $ x;
                                                          unVT (VT_UI8a      x) = map fromIntegral . toList1D $ x; unVT x = unVTVa x

-- TODO: Report incorrect type of *list* rather than member
unVTVa :: (FromVariant a) => Variant -> [a]
unVTVa (VT_VARIANTa x) = map unVT $ toList1D x
unVTVa _ = unVTErr

-- TODO: Report expected and given type
unVTErr :: a
unVTErr = throwHCOM "Variant does not contain the expected type."

vtArgIn :: (ToVariant a) => a -> Stack b b
vtArgIn = argIn . vt

vtArgInByRef :: (ToVariant a) => a -> Stack b b
vtArgInByRef = argInByRef . vt

vtvtArgIn :: (ToVariant a) => [a] -> Stack b b
vtvtArgIn = argIn . vt . map vt

vtArgInOut :: (ToVariant a, FromVariant a) => a -> Stack b (b, a)
vtArgInOut x = mapSecondStack unVT <<< argInOut (vt x)

vtArgOut   :: (FromVariant a) => Stack b (b, a)
vtArgOut = mapSecondStack unVT <<< argOut

mapSecondStack   :: (a -> b) -> Stack (c, a) (c, b)
mapSecondStack = fmap . (id ***)
