-- This file is licensed under the New BSD License
{-# LANGUAGE ForeignFunctionInterface #-}
{-# LANGUAGE EmptyDataDecls #-}

--
-- RawFunctions.hs:
--
-- Declaration of all the functions we use from the Win32/COM API,
-- plus the associated types. These are the raw functions, which will
-- either be used for marshalling of parameters, or exposed in a
-- Haskell-friendly form through Functions.hs.
--

module System.Win32.HCOM.RawFunctions
  -- Types
( DWORD
, HRESULT
, OLECHAR
, LPVOID
, LPUNKNOWN
, RawGUID
, VARIANT
, SAFEARRAY
  -- Functions
, rawCoInitializeEx
, rawCoUninitialize
, rawCoCreateInstance
, rawSysAllocStringLen
, rawSysFreeString
, rawSysStringLen
, rawVariantInit
, rawVariantClear
, rawSafeArrayCreate
, rawSafeArrayDestroy
, rawSafeArrayGetElemSize
, rawSafeArrayGetDim
, rawSafeArrayGetLBound
, rawSafeArrayGetUBound
, rawSafeArrayAccessData
, rawSafeArrayUnaccessData
, rawGetErrorInfo
, rawLoadTypeLibEx
, rawFormatMessageA
, rawLocalFree
, rawCLSIDFromProgID
, rawCoCreateGuid
) where

import Foreign

import System.Win32.HCOM.Tags

------------------------------------------------------------------------
-- Win32 types

-- "Double word"
type DWORD     = Word32

-- Result type
type HRESULT   = Word32

-- An element of a BSTR
type OLECHAR   = Word16

-- Untyped pointer
type LPVOID    = Ptr ()

-- Pointer to IUnknown
type LPUNKNOWN = LPVOID

-- Artificial data structures created so that we can have
-- appropriately-types Ptrs:

data RawGUID -- We use 'GUID' externally.
data VARIANT
data SAFEARRAY

------------------------------------------------------------------------
-- Win32 functions
--

foreign import stdcall "CoInitializeEx"    rawCoInitializeEx    :: LPVOID -> DWORD -> IO HRESULT
foreign import stdcall "CoUninitialize"    rawCoUninitialize    :: IO ()
foreign import stdcall "CoCreateInstance"  rawCoCreateInstance  :: Ptr RawGUID -> LPUNKNOWN -> DWORD -> Ptr RawGUID -> LPVOID -> IO HRESULT
foreign import stdcall "SysAllocStringLen" rawSysAllocStringLen :: Ptr OLECHAR -> DWORD -> IO (Ptr OLECHAR)
foreign import stdcall "SysFreeString"     rawSysFreeString     :: Ptr OLECHAR ->          IO HRESULT
foreign import stdcall "SysStringLen"      rawSysStringLen      :: Ptr OLECHAR ->          IO DWORD
foreign import stdcall "VariantInit"       rawVariantInit       :: Ptr VARIANT -> IO ()
foreign import stdcall "VariantClear"      rawVariantClear      :: Ptr VARIANT -> IO ()
foreign import stdcall "GetErrorInfo"      rawGetErrorInfo      :: DWORD -> Ptr LPVOID -> IO HRESULT
foreign import stdcall "LoadTypeLibEx"     rawLoadTypeLibEx     :: Ptr OLECHAR -> DWORD -> Ptr (Ptr ()) -> IO HRESULT
foreign import stdcall "FormatMessageA"    rawFormatMessageA    :: DWORD -> LPVOID -> DWORD -> DWORD -> Ptr (Ptr Word8) -> DWORD -> LPVOID -> IO DWORD
foreign import stdcall "LocalFree"         rawLocalFree         :: LPVOID -> IO LPVOID
foreign import stdcall "CLSIDFromProgID"   rawCLSIDFromProgID   :: Ptr OLECHAR -> Ptr RawGUID -> IO HRESULT
foreign import stdcall "CoCreateGuid"      rawCoCreateGuid      :: Ptr RawGUID -> IO HRESULT
foreign import stdcall "SafeArrayCreate"   rawSafeArrayCreate   :: VARTYPE -> DWORD -> Ptr DWORD -> IO (Ptr SAFEARRAY)
foreign import stdcall "SafeArrayDestroy"  rawSafeArrayDestroy  :: Ptr SAFEARRAY -> IO ()
foreign import stdcall "SafeArrayGetDim"   rawSafeArrayGetDim   :: Ptr SAFEARRAY -> IO Word32
foreign import stdcall "SafeArrayGetLBound"rawSafeArrayGetLBound:: Ptr SAFEARRAY -> Word32 -> Ptr Word32 -> IO HRESULT -- Note that dims are indexed from 1
foreign import stdcall "SafeArrayGetUBound"rawSafeArrayGetUBound:: Ptr SAFEARRAY -> Word32 -> Ptr Word32 -> IO HRESULT -- Note that dims are indexed from 1
foreign import stdcall "SafeArrayGetElemsize" rawSafeArrayGetElemSize :: Ptr SAFEARRAY -> IO Word32
foreign import stdcall "SafeArrayAccessData"  rawSafeArrayAccessData  :: Ptr SAFEARRAY -> Ptr (Ptr a) -> IO HRESULT
foreign import stdcall "SafeArrayUnaccessData"  rawSafeArrayUnaccessData  :: Ptr SAFEARRAY -> IO HRESULT

