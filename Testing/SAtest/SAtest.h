

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Nov 12 16:23:42 2017
 */
/* Compiler settings for SAtest.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SAtest_h__
#define __SAtest_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISATest_FWD_DEFINED__
#define __ISATest_FWD_DEFINED__
typedef interface ISATest ISATest;

#endif 	/* __ISATest_FWD_DEFINED__ */


#ifndef __SATest_FWD_DEFINED__
#define __SATest_FWD_DEFINED__

#ifdef __cplusplus
typedef class SATest SATest;
#else
typedef struct SATest SATest;
#endif /* __cplusplus */

#endif 	/* __SATest_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISATest_INTERFACE_DEFINED__
#define __ISATest_INTERFACE_DEFINED__

/* interface ISATest */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISATest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF45C527-4B2E-4030-83C1-2E99923F4441")
    ISATest : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MySAFunc1( 
            /* [in] */ SAFEARRAY * array) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MySAFunc2( 
            /* [out][in] */ SAFEARRAY * array) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MySAFunc3( 
            /* [out] */ SAFEARRAY * *pArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MySAFunc4( 
            /* [in] */ SAFEARRAY * array,
            /* [out] */ int *pRes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TestBool( 
            /* [out][in] */ SAFEARRAY * array) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TestBSTR( 
            /* [out][in] */ SAFEARRAY * array) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TestUnk( 
            /* [out][in] */ SAFEARRAY * array) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TestVariant( 
            /* [out][in] */ SAFEARRAY * array) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TestV( 
            /* [out][in] */ VARIANT *pVar) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISATestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISATest * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISATest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISATest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISATest * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISATest * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISATest * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISATest * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *MySAFunc1 )( 
            ISATest * This,
            /* [in] */ SAFEARRAY * array);
        
        HRESULT ( STDMETHODCALLTYPE *MySAFunc2 )( 
            ISATest * This,
            /* [out][in] */ SAFEARRAY * array);
        
        HRESULT ( STDMETHODCALLTYPE *MySAFunc3 )( 
            ISATest * This,
            /* [out] */ SAFEARRAY * *pArray);
        
        HRESULT ( STDMETHODCALLTYPE *MySAFunc4 )( 
            ISATest * This,
            /* [in] */ SAFEARRAY * array,
            /* [out] */ int *pRes);
        
        HRESULT ( STDMETHODCALLTYPE *TestBool )( 
            ISATest * This,
            /* [out][in] */ SAFEARRAY * array);
        
        HRESULT ( STDMETHODCALLTYPE *TestBSTR )( 
            ISATest * This,
            /* [out][in] */ SAFEARRAY * array);
        
        HRESULT ( STDMETHODCALLTYPE *TestUnk )( 
            ISATest * This,
            /* [out][in] */ SAFEARRAY * array);
        
        HRESULT ( STDMETHODCALLTYPE *TestVariant )( 
            ISATest * This,
            /* [out][in] */ SAFEARRAY * array);
        
        HRESULT ( STDMETHODCALLTYPE *TestV )( 
            ISATest * This,
            /* [out][in] */ VARIANT *pVar);
        
        END_INTERFACE
    } ISATestVtbl;

    interface ISATest
    {
        CONST_VTBL struct ISATestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISATest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISATest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISATest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISATest_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISATest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISATest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISATest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISATest_MySAFunc1(This,array)	\
    ( (This)->lpVtbl -> MySAFunc1(This,array) ) 

#define ISATest_MySAFunc2(This,array)	\
    ( (This)->lpVtbl -> MySAFunc2(This,array) ) 

#define ISATest_MySAFunc3(This,pArray)	\
    ( (This)->lpVtbl -> MySAFunc3(This,pArray) ) 

#define ISATest_MySAFunc4(This,array,pRes)	\
    ( (This)->lpVtbl -> MySAFunc4(This,array,pRes) ) 

#define ISATest_TestBool(This,array)	\
    ( (This)->lpVtbl -> TestBool(This,array) ) 

#define ISATest_TestBSTR(This,array)	\
    ( (This)->lpVtbl -> TestBSTR(This,array) ) 

#define ISATest_TestUnk(This,array)	\
    ( (This)->lpVtbl -> TestUnk(This,array) ) 

#define ISATest_TestVariant(This,array)	\
    ( (This)->lpVtbl -> TestVariant(This,array) ) 

#define ISATest_TestV(This,pVar)	\
    ( (This)->lpVtbl -> TestV(This,pVar) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISATest_INTERFACE_DEFINED__ */



#ifndef __SAtestLib_LIBRARY_DEFINED__
#define __SAtestLib_LIBRARY_DEFINED__

/* library SAtestLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SAtestLib;

EXTERN_C const CLSID CLSID_SATest;

#ifdef __cplusplus

class DECLSPEC_UUID("50C1BE3B-1298-4D57-A781-2212EBFFD961")
SATest;
#endif
#endif /* __SAtestLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


