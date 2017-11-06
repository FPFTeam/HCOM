module System.Win32.HCOM.ErrorUtils where
import System.Win32.HCOM.RawFunctions

checkHRInner :: HRESULT -> IO ()
