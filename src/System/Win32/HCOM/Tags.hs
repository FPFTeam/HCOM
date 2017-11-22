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

c_VT_EMPTY            = 0     
c_VT_NULL             = 1     
c_VT_I2               = 2     
c_VT_I4               = 3     
c_VT_R4               = 4     
c_VT_R8               = 5     
c_VT_CY               = 6     
c_VT_DATE             = 7     
c_VT_BSTR             = 8     
c_VT_DISPATCH         = 9     
c_VT_ERROR            = 10    
c_VT_BOOL             = 11    
c_VT_VARIANT          = 12    
c_VT_UNKNOWN          = 13    
c_VT_DECIMAL          = 14    
c_VT_I1               = 16    
c_VT_UI1              = 17    
c_VT_UI2              = 18    
c_VT_UI4              = 19    
c_VT_I8               = 20    
c_VT_UI8              = 21    
c_VT_INT              = 22    
c_VT_UINT             = 23    
c_VT_VOID             = 24    
c_VT_HRESULT          = 25    
c_VT_PTR              = 26    
c_VT_SAFEARRAY        = 27    
c_VT_CARRAY           = 28    
c_VT_USERDEFINED      = 29    
c_VT_LPSTR            = 30    
c_VT_LPWSTR           = 31    
c_VT_RECORD           = 36    
c_VT_INT_PTR          = 37    
c_VT_UINT_PTR         = 38    
c_VT_FILETIME         = 64    
c_VT_BLOB             = 65    
c_VT_STREAM           = 66    
c_VT_STORAGE          = 67    
c_VT_STREAMED_OBJECT  = 68    
c_VT_STORED_OBJECT    = 69    
c_VT_BLOB_OBJECT      = 70    
c_VT_CF               = 71    
c_VT_CLSID            = 72    
c_VT_VERSIONED_STREAM = 73    
c_VT_BSTR_BLOB        = 0xfff 
c_VT_VECTOR           = 0x1000
c_VT_ARRAY            = 0x2000
c_VT_BYREF            = 0x4000
c_VT_RESERVED         = 0x8000
c_VT_ILLEGAL          = 0xffff
c_VT_ILLEGALMASKED    = 0xfff 
c_VT_TYPEMASK         = 0xfff 

c_VT_EMPTY             :: VARTYPE
c_VT_NULL              :: VARTYPE
c_VT_I2                :: VARTYPE
c_VT_I4                :: VARTYPE
c_VT_R4                :: VARTYPE
c_VT_R8                :: VARTYPE
c_VT_CY                :: VARTYPE
c_VT_DATE              :: VARTYPE
c_VT_BSTR              :: VARTYPE
c_VT_DISPATCH          :: VARTYPE
c_VT_ERROR             :: VARTYPE
c_VT_BOOL              :: VARTYPE
c_VT_VARIANT           :: VARTYPE
c_VT_UNKNOWN           :: VARTYPE
c_VT_DECIMAL           :: VARTYPE
c_VT_I1                :: VARTYPE
c_VT_UI1               :: VARTYPE
c_VT_UI2               :: VARTYPE
c_VT_UI4               :: VARTYPE
c_VT_I8                :: VARTYPE
c_VT_UI8               :: VARTYPE
c_VT_INT               :: VARTYPE
c_VT_UINT              :: VARTYPE
c_VT_VOID              :: VARTYPE
c_VT_HRESULT           :: VARTYPE
c_VT_PTR               :: VARTYPE
c_VT_SAFEARRAY         :: VARTYPE
c_VT_CARRAY            :: VARTYPE
c_VT_USERDEFINED       :: VARTYPE
c_VT_LPSTR             :: VARTYPE
c_VT_LPWSTR            :: VARTYPE
c_VT_RECORD            :: VARTYPE
c_VT_INT_PTR           :: VARTYPE
c_VT_UINT_PTR          :: VARTYPE
c_VT_FILETIME          :: VARTYPE
c_VT_BLOB              :: VARTYPE
c_VT_STREAM            :: VARTYPE
c_VT_STORAGE           :: VARTYPE
c_VT_STREAMED_OBJECT   :: VARTYPE
c_VT_STORED_OBJECT     :: VARTYPE
c_VT_BLOB_OBJECT       :: VARTYPE
c_VT_CF                :: VARTYPE
c_VT_CLSID             :: VARTYPE
c_VT_VERSIONED_STREAM  :: VARTYPE
c_VT_BSTR_BLOB         :: VARTYPE
c_VT_VECTOR            :: VARTYPE
c_VT_ARRAY             :: VARTYPE
c_VT_BYREF             :: VARTYPE
c_VT_RESERVED          :: VARTYPE
c_VT_ILLEGAL           :: VARTYPE
c_VT_ILLEGALMASKED     :: VARTYPE
c_VT_TYPEMASK          :: VARTYPE
