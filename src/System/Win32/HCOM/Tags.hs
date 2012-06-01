-- This file is licensed under the New BSD License
--
-- Tags.hs:
--
-- Defines the data type tags used by VARIANTs and SAFEARRAYs.
--

module System.Win32.HCOM.Tags
( VARTYPE
, c_VT_EMPTY
, c_VT_NULL
, c_VT_I2
, c_VT_I4
, c_VT_R4
, c_VT_R8
, c_VT_CY
, c_VT_DATE
, c_VT_BSTR
, c_VT_DISPATCH
, c_VT_ERROR
, c_VT_BOOL
, c_VT_VARIANT
, c_VT_UNKNOWN
, c_VT_DECIMAL
, c_VT_I1
, c_VT_UI1
, c_VT_UI2
, c_VT_UI4
, c_VT_I8
, c_VT_UI8
, c_VT_INT
, c_VT_UINT
, c_VT_VOID
, c_VT_HRESULT
, c_VT_PTR
, c_VT_SAFEARRAY
, c_VT_CARRAY
, c_VT_USERDEFINED
, c_VT_LPSTR
, c_VT_LPWSTR
, c_VT_RECORD
, c_VT_INT_PTR
, c_VT_UINT_PTR
, c_VT_FILETIME
, c_VT_BLOB
, c_VT_STREAM
, c_VT_STORAGE
, c_VT_STREAMED_OBJECT
, c_VT_STORED_OBJECT
, c_VT_BLOB_OBJECT
, c_VT_CF
, c_VT_CLSID
, c_VT_VERSIONED_STREAM
, c_VT_BSTR_BLOB
, c_VT_VECTOR
, c_VT_ARRAY
, c_VT_BYREF
, c_VT_RESERVED
, c_VT_ILLEGAL
, c_VT_ILLEGALMASKED
, c_VT_TYPEMASK
) where

import Foreign

type VARTYPE = Word16

c_VT_EMPTY            = 0      :: VARTYPE
c_VT_NULL             = 1      :: VARTYPE
c_VT_I2               = 2      :: VARTYPE
c_VT_I4               = 3      :: VARTYPE
c_VT_R4               = 4      :: VARTYPE
c_VT_R8               = 5      :: VARTYPE
c_VT_CY               = 6      :: VARTYPE
c_VT_DATE             = 7      :: VARTYPE
c_VT_BSTR             = 8      :: VARTYPE
c_VT_DISPATCH         = 9      :: VARTYPE
c_VT_ERROR            = 10     :: VARTYPE
c_VT_BOOL             = 11     :: VARTYPE
c_VT_VARIANT          = 12     :: VARTYPE
c_VT_UNKNOWN          = 13     :: VARTYPE
c_VT_DECIMAL          = 14     :: VARTYPE
c_VT_I1               = 16     :: VARTYPE
c_VT_UI1              = 17     :: VARTYPE
c_VT_UI2              = 18     :: VARTYPE
c_VT_UI4              = 19     :: VARTYPE
c_VT_I8               = 20     :: VARTYPE
c_VT_UI8              = 21     :: VARTYPE
c_VT_INT              = 22     :: VARTYPE
c_VT_UINT             = 23     :: VARTYPE
c_VT_VOID             = 24     :: VARTYPE
c_VT_HRESULT          = 25     :: VARTYPE
c_VT_PTR              = 26     :: VARTYPE
c_VT_SAFEARRAY        = 27     :: VARTYPE
c_VT_CARRAY           = 28     :: VARTYPE
c_VT_USERDEFINED      = 29     :: VARTYPE
c_VT_LPSTR            = 30     :: VARTYPE
c_VT_LPWSTR           = 31     :: VARTYPE
c_VT_RECORD           = 36     :: VARTYPE
c_VT_INT_PTR          = 37     :: VARTYPE
c_VT_UINT_PTR         = 38     :: VARTYPE
c_VT_FILETIME         = 64     :: VARTYPE
c_VT_BLOB             = 65     :: VARTYPE
c_VT_STREAM           = 66     :: VARTYPE
c_VT_STORAGE          = 67     :: VARTYPE
c_VT_STREAMED_OBJECT  = 68     :: VARTYPE
c_VT_STORED_OBJECT    = 69     :: VARTYPE
c_VT_BLOB_OBJECT      = 70     :: VARTYPE
c_VT_CF               = 71     :: VARTYPE
c_VT_CLSID            = 72     :: VARTYPE
c_VT_VERSIONED_STREAM = 73     :: VARTYPE
c_VT_BSTR_BLOB        = 0xfff  :: VARTYPE
c_VT_VECTOR           = 0x1000 :: VARTYPE
c_VT_ARRAY            = 0x2000 :: VARTYPE
c_VT_BYREF            = 0x4000 :: VARTYPE
c_VT_RESERVED         = 0x8000 :: VARTYPE
c_VT_ILLEGAL          = 0xffff :: VARTYPE
c_VT_ILLEGALMASKED    = 0xfff  :: VARTYPE
c_VT_TYPEMASK         = 0xfff  :: VARTYPE
