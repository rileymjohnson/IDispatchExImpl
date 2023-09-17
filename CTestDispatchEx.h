// Copyright © 1998-99 the e-comm group, inc.
//
// CTestDispatchEx.h: This class derives from the IDispatchEx interface
// and uses the IDispatchExImpl class to expose custom members via the
// TypeInfo support
//
// $Author: Graf $
// $Date: 3/11/99 11:38p $
// $Revision: 3 $
// $Archive: /e-comm group/Components/TestDispatchEx/CTestDispatchEx.h $


#ifndef _TEST_DISPATCH_EX_H
#define _TEST_DISPATCH_EX_H

#include "resource.h"
#include "IDispatchExImpl.h"


class CTestDispatchEx : 
	public IDispatchExImpl<CTestDispatchEx,ITestDispatchEx,
		&IID_ITestDispatchEx,&LIBID_TESTDISPATCHEXLib>,
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CTestDispatchEx,&CLSID_TestDispatchEx>
{
	// Our only property
	long m_lNumber;

public:
	CTestDispatchEx() { m_lNumber = 2; }

BEGIN_COM_MAP(CTestDispatchEx)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IDispatchEx)
	COM_INTERFACE_ENTRY(ITestDispatchEx)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CTestDispatchEx) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_CLASSFACTORY_DISPATCHEX(CTestDispatchEx)

DECLARE_REGISTRY_RESOURCEID(IDR_TestDispatchEx)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ITestDispatchEx
public:
	STDMETHOD(put_Set)(BSTR bstrVarName,VARIANT vtVar);
	STDMETHOD(Get)(BSTR bstrVarName,VARIANT* pvtVar);
	STDMETHOD(get_Number)(VARIANT *pVal);
	STDMETHOD(put_Number)(VARIANT newVal);
	STDMETHOD(Square)(void);
};

#endif
