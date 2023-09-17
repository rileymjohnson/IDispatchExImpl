// Copyright © 1998-99 the e-comm group, inc.
//
// CTestDispatchEx.cpp: This class derives from the IDispatchEx interface
// and uses the IDispatchExImpl class to expose custom members via the
// TypeInfo support
//
// $Author: Graf $
// $Date: 3/11/99 11:38p $
// $Revision: 3 $
// $Archive: /e-comm group/Components/TestDispatchEx/CTestDispatchEx.cpp $


#include "stdafx.h"
#include "TestDispatchEx.h"
#include "CTestDispatchEx.h"

STDMETHODIMP CTestDispatchEx::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ITestDispatchEx,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

/***************************************************************************
* Function:	CTestDispatchEx::Square()
* Author:	Joe Graf
* Date:		2/12/99
* Args:		None
* Returns:	<HRESULT> Standard COM codes
* Purpose:	Squares the Number property
***************************************************************************/

STDMETHODIMP CTestDispatchEx::Square(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	// Square the number
	m_lNumber *= m_lNumber;
	return S_OK;
}

/***************************************************************************
* Function:	CTestDispatchEx::get_Number()
* Author:	Joe Graf
* Date:		2/12/99
* Args:		<VARIANT*> pvtVal - the variant to hold the result
* Returns:	<HRESULT> Standard COM codes
* Purpose:	Gets the Number property
***************************************************************************/

STDMETHODIMP CTestDispatchEx::get_Number(VARIANT* pvtVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	CComVariant vtTemp(m_lNumber);
	// Copy the method into a variant and copy that into the result
	return VariantCopy(pvtVal,&vtTemp);
}

/***************************************************************************
* Function:	CTestDispatchEx::put_Number()
* Author:	Joe Graf
* Date:		2/12/99
* Args:		<VARIANT> vtVal - the new number to assign
* Returns:	<HRESULT> Standard COM codes
* Purpose:	Sets the Number property
***************************************************************************/

STDMETHODIMP CTestDispatchEx::put_Number(VARIANT vtVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	// Copy the new value
	m_lNumber = vtVal.lVal;
	return S_OK;
}

/***************************************************************************
* Function:	CTestDispatchEx::Get()
* Author:	Joe Graf
* Date:		2/12/99
* Args:		<BSTR> bstrVarName - the name of the property to look up
*			<VARIANT*> pvtVar - the variant to hold the property
* Returns:	<HRESULT> Standard COM codes
* Purpose:	Gets a property by name
***************************************************************************/

STDMETHODIMP CTestDispatchEx::Get(BSTR bstrVarName,VARIANT* pvtVar)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	// Just forward the call onto the IDispatchEx implementation
	return __this::Get(bstrVarName,pvtVar);
}

/***************************************************************************
* Function:	CTestDispatchEx::Get()
* Author:	Joe Graf
* Date:		2/12/99
* Args:		<BSTR> bstrVarName - the name of the property to look up
*			<VARIANT> vtVar - the new value to assign
* Returns:	<HRESULT> Standard COM codes
* Purpose:	Sets a property by name
***************************************************************************/

STDMETHODIMP CTestDispatchEx::put_Set(BSTR bstrVarName,VARIANT vtVar)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	// Just forward the call onto the IDispatchEx implementation
	return __this::Set(bstrVarName,vtVar);
}
