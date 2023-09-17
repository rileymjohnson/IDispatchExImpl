// Copyright © 1998-99 the e-comm group, inc.
//
// CDynamicOnly.h: This class shows a pure dynamic object with no
// methods or properties until they are added by script code.
//
// $Author: Graf $
// $Date: 3/12/99 11:27a $
// $Revision: 1 $
// $Archive: /e-comm group/Components/TestDispatchEx/CDynamicOnly.h $


#ifndef _DYNAMIC_ONLY_H
#define _DYNAMIC_ONLY_H

#include "resource.h"
#define IDISPATCHEX_NO_TYPEINFO
#include "IDispatchExImpl.h"

class CDynamicOnly : 
	public IDispatchExImpl<CDynamicOnly,IDynamicOnly,
		&IID_IDynamicOnly,&LIBID_TESTDISPATCHEXLib>,
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CDynamicOnly,&CLSID_DynamicOnly>
{
public:
	CDynamicOnly() {}
BEGIN_COM_MAP(CDynamicOnly)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IDispatchEx)
	COM_INTERFACE_ENTRY(IDynamicOnly)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(CDynamicOnly) 
DECLARE_CLASSFACTORY_DISPATCHEX(CDynamicOnly)

DECLARE_REGISTRY_RESOURCEID(IDR_DynamicOnly)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IDynamicOnly
public:
};

#endif
