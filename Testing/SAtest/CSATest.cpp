// CSATest.cpp : Implementation of CSATest

#include "stdafx.h"
#include "CSATest.h"


// CSATest

STDMETHODIMP CSATest::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ISATest
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

// ISATest

HRESULT STDMETHODCALLTYPE CSATest::MySAFunc1(SAFEARRAY * array)
{
    // Contents are ints.

    ::OutputDebugString(_T("Called MySAFunc1"));
    
    return S_OK;
}

HRESULT STDMETHODCALLTYPE CSATest::MySAFunc2(SAFEARRAY * array)
{
    // Contents are shorts.

    ::OutputDebugString(_T("Called MySAFunc2"));

    if (array == NULL) {
        return E_INVALIDARG;
    }

    short *ptr = static_cast<short *>(array->pvData);

    ptr[1] = 180;

    return S_OK;
}

HRESULT STDMETHODCALLTYPE CSATest::MySAFunc3(SAFEARRAY * *pArray)
{
    // Contents are unsigned chars.

    ::OutputDebugString(_T("Called MySAFunc3"));

    if (pArray == NULL || *pArray != NULL) {
        return E_INVALIDARG;
    }

    SAFEARRAYBOUND bounds = {5, 42};

    *pArray = ::SafeArrayCreate(VT_UI1, 1, &bounds);

    if (*pArray == NULL) {
        return E_FAIL;
    }

    char *ptr = static_cast<char *>((*pArray)->pvData);

    ::strncpy(ptr, "foo!1", 5);

    return S_OK;
}

HRESULT STDMETHODCALLTYPE CSATest::MySAFunc4(SAFEARRAY * array, int *pRes)
{
    // Contents are ints.

    ::OutputDebugString(_T("Called MySAFunc4"));

    if (array == NULL || pRes == NULL) {
        return E_INVALIDARG;
    }

    long indices[2];

    // Least-significant has lowest index.
    indices[0] = 3;
    indices[1] = 4;
    if (FAILED(::SafeArrayGetElement(array, indices, pRes))) {
        return E_FAIL;
    }

    return S_OK;
}

HRESULT STDMETHODCALLTYPE CSATest::TestBool(SAFEARRAY * array)
{
    // Contents are BOOLs
    ::OutputDebugString(_T("Called TestBool"));

    return S_OK;
}

HRESULT STDMETHODCALLTYPE CSATest::TestBSTR(SAFEARRAY * array)
{
    // Contents are BSTRs
    ::OutputDebugString(_T("Called TestBSTR"));

    return S_OK;
}

HRESULT STDMETHODCALLTYPE CSATest::TestUnk(SAFEARRAY * array)
{
    // Contents are objects
    ::OutputDebugString(_T("Called TestUnk"));

    CComPtr<IUnknown> pUnk;

    long index = 1;

    if (FAILED(::SafeArrayGetElement(array, &index, &pUnk))) {
        return E_FAIL;
    }

    if (pUnk == NULL) {
        return E_FAIL;
    }

    return S_OK;

}

HRESULT STDMETHODCALLTYPE CSATest::TestVariant(SAFEARRAY *array)
{
    // Contents are variants
    ::OutputDebugString(_T("Called TestVariant"));

    return S_OK;
}

HRESULT STDMETHODCALLTYPE CSATest::TestV(VARIANT *pVar)
{
    // Contents of variant could be anything.
    ::OutputDebugString(_T("Called TestV"));

    return S_OK;
}
