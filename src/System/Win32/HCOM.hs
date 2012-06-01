-- This file is licensed under the New BSD License
--
-- HCOM.hs:
--
-- Top-level interface to HCOM
--

module System.Win32.HCOM
  -- COM types
( GUID(..)
, IID
, CLSID
  -- COM interfaces and pointers
, Interface(..)
, IUnknown
, IDispatch
, COMPtr()
, nullCOMPtr
  -- Variants
, Variant(..)
  -- Variant conversion
, ToVariant(..)
, FromVariant(..)
, vtArgIn
, vtArgInByRef
, vtvtArgIn
, vtArgInOut
, vtArgOut
  -- Safearrays
, SafeArray(..)
, newSafeArray
, newSafeArrayM
, fromList
, toList
, fromList2D
, toList2D
, (!)
  -- COM functions
, module System.Win32.HCOM.Functions
, queryInterface
, qi
, qiChecked
  -- COM call construction (used to implement interfaces)
, Stackable(..)
, Stack
, vcall
  -- Error handling
, module System.Win32.HCOM.ErrorBase
, module System.Win32.HCOM.ErrorUtils
  -- Helpers
, (~>)
) where

import System.Win32.HCOM.BSTR()
import System.Win32.HCOM.COMCall()
import System.Win32.HCOM.ErrorUtils
import System.Win32.HCOM.COMPtr
import System.Win32.HCOM.ErrorBase
import System.Win32.HCOM.Extras()
import System.Win32.HCOM.Functions
import System.Win32.HCOM.GUID
import System.Win32.HCOM.SafeArray
import System.Win32.HCOM.Stack
import System.Win32.HCOM.Variant
import System.Win32.HCOM.VariantConversion

-- Like '->' in OO languages.
(~>) :: COMPtr a -> (COMPtr a -> b) -> b
obj ~> call = call obj
