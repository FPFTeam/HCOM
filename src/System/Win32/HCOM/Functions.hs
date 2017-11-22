-- This file is licensed under the New BSD License
{-# LANGUAGE ScopedTypeVariables #-}

--
-- Functions.hs:
--
-- Wrappers for Win32 COM functions which aren't associated with
-- marshaling, and thus which you might want to call directly.
--

module System.Win32.HCOM.Functions
  -- COINIT constants
( c_COINIT_APARTMENTTHREADED
, c_COINIT_MULTITHREADED
, c_COINIT_DISABLE_OLE1DDE
, c_COINIT_SPEED_OVER_MEMORY
  -- COM init/shutdown functions
, coInitializeEx
, coUninitialize
, coRun
  -- CLSCTX constants
, c_CLSCTX_INPROC_SERVER
, c_CLSCTX_INPROC_HANDLER
, c_CLSCTX_LOCAL_SERVER
, c_CLSCTX_INPROC_SERVER16
, c_CLSCTX_REMOTE_SERVER
, c_CLSCTX_INPROC_HANDLER16
, c_CLSCTX_RESERVED1
, c_CLSCTX_RESERVED2
, c_CLSCTX_RESERVED3
, c_CLSCTX_RESERVED4
, c_CLSCTX_NO_CODE_DOWNLOAD
, c_CLSCTX_RESERVED5
, c_CLSCTX_NO_CUSTOM_MARSHAL
, c_CLSCTX_ENABLE_CODE_DOWNLOAD
, c_CLSCTX_NO_FAILURE_LOG
, c_CLSCTX_DISABLE_AAA
, c_CLSCTX_ENABLE_AAA
, c_CLSCTX_FROM_DEFAULT_CONTEXT
, c_CLSCTX_ACTIVATE_32_BIT_SERVER
, c_CLSCTX_ACTIVATE_64_BIT_SERVER
, c_CLSCTX_ENABLE_CLOAKING
, c_CLSCTX_PS_DLL
, c_CLSCTX_INPROC
, c_CLSCTX_ALL
, c_CLSCTX_SERVER
  -- Object creation.
, coCreateInstance
, coCreate
, coCreateGuid
) where

import Foreign
import System.Mem

import System.Win32.HCOM.ErrorUtils
import System.Win32.HCOM.COMPtr
import System.Win32.HCOM.GUID
import System.Win32.HCOM.ErrorBase
import System.Win32.HCOM.RawFunctions

------------------------------------------------------------------------
-- COM initialization/shutdown
--

c_COINIT_APARTMENTTHREADED  :: DWORD -- Apartment model
c_COINIT_MULTITHREADED      :: DWORD -- OLE calls objects on any thread.
c_COINIT_DISABLE_OLE1DDE    :: DWORD -- Don't use DDE for Ole1 support.
c_COINIT_SPEED_OVER_MEMORY  :: DWORD -- Trade memory for speed.
c_COINIT_APARTMENTTHREADED  = 0x2 :: DWORD -- Apartment model
c_COINIT_MULTITHREADED      = 0x0 :: DWORD -- OLE calls objects on any thread.
c_COINIT_DISABLE_OLE1DDE    = 0x4 :: DWORD -- Don't use DDE for Ole1 support.
c_COINIT_SPEED_OVER_MEMORY  = 0x8 :: DWORD -- Trade memory for speed.

coInitializeEx :: DWORD -> IO HResult
coInitializeEx = fmap HResult . rawCoInitializeEx nullPtr

coUninitialize :: IO ()
coUninitialize = rawCoUninitialize

-- A wrapper that performs coInit and coUninit for you.
coRun :: IO a -> IO a
coRun f = do
  -- Generally best to initialise with multithreading enabled.
  checkHResult =<< coInitializeEx c_COINIT_MULTITHREADED
  -- Do stuff!
  res <- f
  -- If we're going to shut down COM, we should try to release all COM
  -- objects first. These are held in ForeignPtrs, so try to finalize
  -- them by triggering a GC.
  performGC
  -- FIXME: The GC may (and does) happen asynchronously. This means
  -- that we may still keep using COM after coUninit. Explosions may
  -- ensue. Darn. The alternative is to keep a 'live object count' and
  -- put a wait-with-timeout here.
  --
  -- So, we disable this for the moment. :(
  -- coUninitialize
  return res

------------------------------------------------------------------------
-- Object creation
--
c_CLSCTX_INPROC_SERVER            :: DWORD
c_CLSCTX_INPROC_HANDLER           :: DWORD
c_CLSCTX_LOCAL_SERVER             :: DWORD
c_CLSCTX_INPROC_SERVER16          :: DWORD
c_CLSCTX_REMOTE_SERVER            :: DWORD
c_CLSCTX_INPROC_HANDLER16         :: DWORD
c_CLSCTX_RESERVED1                :: DWORD
c_CLSCTX_RESERVED2                :: DWORD
c_CLSCTX_RESERVED3                :: DWORD
c_CLSCTX_RESERVED4                :: DWORD
c_CLSCTX_NO_CODE_DOWNLOAD         :: DWORD
c_CLSCTX_RESERVED5                :: DWORD
c_CLSCTX_NO_CUSTOM_MARSHAL        :: DWORD
c_CLSCTX_ENABLE_CODE_DOWNLOAD     :: DWORD
c_CLSCTX_NO_FAILURE_LOG           :: DWORD
c_CLSCTX_DISABLE_AAA              :: DWORD
c_CLSCTX_ENABLE_AAA               :: DWORD
c_CLSCTX_FROM_DEFAULT_CONTEXT     :: DWORD
c_CLSCTX_ACTIVATE_32_BIT_SERVER   :: DWORD
c_CLSCTX_ACTIVATE_64_BIT_SERVER   :: DWORD
c_CLSCTX_ENABLE_CLOAKING          :: DWORD
c_CLSCTX_PS_DLL                   :: DWORD

c_CLSCTX_INPROC_SERVER            = 0x1        :: DWORD
c_CLSCTX_INPROC_HANDLER           = 0x2        :: DWORD
c_CLSCTX_LOCAL_SERVER             = 0x4        :: DWORD
c_CLSCTX_INPROC_SERVER16          = 0x8        :: DWORD
c_CLSCTX_REMOTE_SERVER            = 0x10       :: DWORD
c_CLSCTX_INPROC_HANDLER16         = 0x20       :: DWORD
c_CLSCTX_RESERVED1                = 0x40       :: DWORD
c_CLSCTX_RESERVED2                = 0x80       :: DWORD
c_CLSCTX_RESERVED3                = 0x100      :: DWORD
c_CLSCTX_RESERVED4                = 0x200      :: DWORD
c_CLSCTX_NO_CODE_DOWNLOAD         = 0x400      :: DWORD
c_CLSCTX_RESERVED5                = 0x800      :: DWORD
c_CLSCTX_NO_CUSTOM_MARSHAL        = 0x1000     :: DWORD
c_CLSCTX_ENABLE_CODE_DOWNLOAD     = 0x2000     :: DWORD
c_CLSCTX_NO_FAILURE_LOG           = 0x4000     :: DWORD
c_CLSCTX_DISABLE_AAA              = 0x8000     :: DWORD
c_CLSCTX_ENABLE_AAA               = 0x10000    :: DWORD
c_CLSCTX_FROM_DEFAULT_CONTEXT     = 0x20000    :: DWORD
c_CLSCTX_ACTIVATE_32_BIT_SERVER   = 0x40000    :: DWORD
c_CLSCTX_ACTIVATE_64_BIT_SERVER   = 0x80000    :: DWORD
c_CLSCTX_ENABLE_CLOAKING          = 0x100000   :: DWORD
c_CLSCTX_PS_DLL                   = 0x80000000 :: DWORD

c_CLSCTX_INPROC :: DWORD
c_CLSCTX_INPROC = c_CLSCTX_INPROC_SERVER .|.
                  c_CLSCTX_INPROC_HANDLER :: DWORD

c_CLSCTX_ALL :: DWORD
c_CLSCTX_ALL = c_CLSCTX_INPROC_SERVER  .|.
               c_CLSCTX_INPROC_HANDLER .|.
               c_CLSCTX_LOCAL_SERVER   .|.
               c_CLSCTX_REMOTE_SERVER  :: DWORD

c_CLSCTX_SERVER :: DWORD
c_CLSCTX_SERVER = c_CLSCTX_INPROC_SERVER .|.
                  c_CLSCTX_LOCAL_SERVER  .|.
                  c_CLSCTX_REMOTE_SERVER :: DWORD

-- We use scoped type variables here for the 'i', so we use 'forall'.
coCreateInstance :: forall i . Interface i =>
                    CLSID -> COMPtr IUnknown -> DWORD -> IO (HResult, COMPtr i)
coCreateInstance clsid pUnkOuter dwClsContext = do
  let riid = iidOf (undefined :: COMPtr i)
  withGUIDPtr clsid $ \clsidPtr ->
      withGUIDPtr riid $ \iidPtr ->
          mkOutParam $ \resPtr ->
              withRawCOMPtr pUnkOuter $ \rawPUnkOuter ->
                  HResult <$> rawCoCreateInstance clsidPtr
                                                  rawPUnkOuter
                                                  dwClsContext
                                                  iidPtr
                                                  (castPtr resPtr)

-- Simplified helper function for the common creation case.
coCreate :: Interface i => CLSID -> IO (COMPtr i)
coCreate clsid = do
  (hr, obj) <- coCreateInstance clsid nullCOMPtr c_CLSCTX_INPROC
  checkHResult hr
  return obj

coCreateGuid :: IO GUID
coCreateGuid = do
  (res, hr) <- withGUIDOutPtr $ rawCoCreateGuid
  checkHResult (HResult hr)
  return res
