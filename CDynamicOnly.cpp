// Copyright © 1998-99 the e-comm group, inc.
//
// CDynamicOnly.cpp: This class shows a pure dynamic object with no
// methods or properties until they are added by script code.
//
// $Author: Graf $
// $Date: 3/12/99 11:27a $
// $Revision: 1 $
// $Archive: /e-comm group/Components/TestDispatchEx/CDynamicOnly.cpp $


#include "stdafx.h"
#include "TestDispatchEx.h"
#include "CDynamicOnly.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CDynamicOnly::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IDynamicOnly,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
