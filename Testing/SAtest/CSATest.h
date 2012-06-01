// CSATest.h : Declaration of the CSATest

#pragma once
#include "resource.h"       // main symbols

#include "SAtest.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CSATest

class ATL_NO_VTABLE CSATest :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSATest, &CLSID_SATest>,
	public ISupportErrorInfo,
	public IDispatchImpl<ISATest, &IID_ISATest, &LIBID_SAtestLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSATest()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SATEST1)


BEGIN_COM_MAP(CSATest)
	COM_INTERFACE_ENTRY(ISATest)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

    virtual HRESULT STDMETHODCALLTYPE MySAFunc1( 
        /* [in] */ SAFEARRAY * array);

    virtual HRESULT STDMETHODCALLTYPE MySAFunc2( 
        /* [out][in] */ SAFEARRAY * array);

    virtual HRESULT STDMETHODCALLTYPE MySAFunc3( 
        /* [out] */ SAFEARRAY * *pArray);

    virtual HRESULT STDMETHODCALLTYPE MySAFunc4( 
        /* [in] */ SAFEARRAY * array,
        /* [out] */ int *pRes);

    virtual HRESULT STDMETHODCALLTYPE TestBool( 
        /* [out][in] */ SAFEARRAY * array);

    virtual HRESULT STDMETHODCALLTYPE TestBSTR( 
        /* [out][in] */ SAFEARRAY * array);

    virtual HRESULT STDMETHODCALLTYPE TestUnk( 
        /* [out][in] */ SAFEARRAY * array);

    virtual HRESULT STDMETHODCALLTYPE TestVariant( 
        /* [out][in] */ SAFEARRAY * array);

    virtual HRESULT STDMETHODCALLTYPE TestV( 
        /* [out][in] */ VARIANT *pVar);
};

OBJECT_ENTRY_AUTO(__uuidof(SATest), CSATest)
