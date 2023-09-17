// Copyright © 1998-99 the e-comm group, inc.
//
// CDynamicTypeInfo.h: This class is used to create ITypeInfo
// interfaces on the fly. It wraps around the INTERFACEDATA
// structure. It allocates the memory needed for METHODDATA
// structures on the fly and creates a fake vtable used to
// call methods that have been added.
//
// $Author: Graf $
// $Date: 2/15/99 2:43p $
// $Revision: 1 $
// $Archive: /e-comm group/Components/TestDispatchEx/CDynamicTypeInfo.h $

#ifndef _DYNAMINC_TYPE_INFO_H
#define _DYNAMINC_TYPE_INFO_H


class CDynamicTypeInfo
{
	// Holds the entry points for the dispatch based functions
	// that are added on the fly
	DWORD* m_pFakeVTable;
	// Holds the data used by ITypeInfo to invoke a method
	LPMETHODDATA m_pMethodData;
	// Members for keeping track of the memory allocs
	DWORD m_dwNextIndex;
	DWORD m_dwMethodAlloced;

	// Helper methods

	/***************************************************************************
	* Function:	CDynamicTypeInfo::Grow()
	* Author:	Joe Graf
	* Date:		2/14/99
	* Args:		None
	* Returns:	<HRESULT> Standard COM codes
	* Purpose:	Doubles the current size of the arrays or adds 16 places to them
	***************************************************************************/

	HRESULT Grow(void)
	{
		// Default to no memory available
		HRESULT hr = E_OUTOFMEMORY;
		// Determine the amount of array entries that are needed
		DWORD dwNewSize = m_dwMethodAlloced != 0 ? 2 * m_dwMethodAlloced : 16;
		// Check to see if we have alloced before
		if( m_pFakeVTable != NULL )
		{
			// We are reallocating a chunk of RAM
			m_pFakeVTable = (DWORD*)LocalReAlloc(m_pFakeVTable,LMEM_ZEROINIT,
				dwNewSize * sizeof(DWORD));
			if( m_pFakeVTable != NULL )
			{
				// First ReAlloc worked, so do the second one
				m_pMethodData = (LPMETHODDATA)LocalReAlloc(m_pMethodData,
					LMEM_ZEROINIT,dwNewSize * sizeof(METHODDATA));
				if( m_pMethodData != NULL )
				{
					// Indicate success
					hr = S_OK;
					// Set the new size of the arrays
					m_dwMethodAlloced = dwNewSize;
				}
				else
				{
					// Release and NULL the vtable
					LocalFree(m_pFakeVTable);
					m_pFakeVTable = NULL;
				}
			}
			else
			{
				// Release and NULL the method data
				LocalFree(m_pMethodData);
				m_pMethodData = NULL;
			}
		}
		else
		{
			// First time alloc
			m_pFakeVTable = (DWORD*)LocalAlloc(LMEM_ZEROINIT,
				dwNewSize * sizeof(DWORD));
			if( m_pFakeVTable != NULL )
			{
				// First alloc worked, so do the second one
				m_pMethodData = (LPMETHODDATA)LocalAlloc(LMEM_ZEROINIT,
					dwNewSize * sizeof(METHODDATA));
				if( m_pMethodData != NULL )
				{
					// Indicate success
					hr = S_OK;
					// Set the new size of the arrays
					m_dwMethodAlloced = dwNewSize;
				}
				else
				{
					// Release and NULL the vtable
					LocalFree(m_pFakeVTable);
					m_pFakeVTable = NULL;
				}
			}
		}
	}

	/***************************************************************************
	* Function:	CDynamicTypeInfo::CopyParamData()
	* Author:	Joe Graf
	* Date:		2/14/99
	* Args:		<PARAMDATA*> ppdDest - the destination paramdata array to copy to
	*			<PARAMDATA*> ppdSrc - the source paramdata array to copy
	*			<UINT> nCount - the number of PARAMDATA structures to copy
	* Returns:	<HRESULT> Standard COM codes
	* Purpose:	Copies the requested PARAMDATA structures
	***************************************************************************/

	HRESULT CopyParamData(PARAMDATA** ppdDest,PARAMDATA* ppdSrc,UINT nCount)
	{
		// Default to no memory available
		HRESULT hr = E_OUTOFMEMORY;
		// Attempt to allocate the number of needed paramdata structures
		*ppdDest = (PARAMDATA*)LocalAlloc(LMEM_ZEROINIT,
			nCount * sizeof(PARAMDATA));
		if( *ppdDest != NULL )
		{
			// Loop through copying the each paramdata structure
			for( UINT nIndex = 0; nIndex < nCount; nIndex++ )
			{
				// Copy the name of the parameter
				(*ppdDest)[nIndex].szName = SysAllocString(ppdSrc[nIndex].szName);
				// Copy the type
				(*ppdDest)[nIndex].vt = ppdSrc[nIndex].vt;
			}
		}
		return hr;
	}

public:
	// Default constructor
	CDynamicTypeInfo() : m_dwNextIndex(0), m_dwMethodAlloced(0),
		m_pMethodData(NULL), m_pFakeVTable(NULL) {}

	/***************************************************************************
	* Function:	CDynamicTypeInfo::~CDynamicTypeInfo()
	* Author:	Joe Graf
	* Date:		2/14/99
	* Args:		None
	* Returns:	None
	* Purpose:	Releases any memory allocated
	***************************************************************************/

	virtual ~CDynamicTypeInfo()
	{
		// Free any allocated memory
		if( m_pFakeVTable != NULL )
		{
			LocalFree(m_pFakeVTable);
		}
		if( m_pMethodData != NULL )
		{
			// First iterate through the method data structures cleaning up
			for( DWORD dwIndex = 0; dwIndex < m_dwNextIndex; dwIndex++ )
			{
				// Release the name of the method
				SysFreeString(m_pMethodData[dwIndex].szName);
				// Now loop through the parameters and clean them up
				for( DWORD dwParamIndex = 0;
					dwParamIndex < m_pMethodData[dwIndex].cArgs; dwParamIndex++ )
				{
					// Release the name of the parameter
					SysFreeString(
						m_pMethodData[dwIndex].ppdata[dwParamIndex].szName);
				}
				// Now free the paramdata structures
				LocalFree(m_pMethodData[dwIndex].ppdata);
			}
			LocalFree(m_pMethodData);
		}
	}

// Operations

	/***************************************************************************
	* Function:	CDynamicTypeInfo::AddMember()
	* Author:	Joe Graf
	* Date:		2/14/99
	* Args:		<BSTR> bstrName - the name of the member
	*			<DISPID> dispid - the dispid of the member
	*			<PARAMDATA*> pParamData - the parameter descriptions
	*			<UINT> nParamCount - the number of params for this member
	*			<CALLCONV> cc - the calling convention of the method
	*			<WORD> wFlags - the type of call this is
	*			<VARTYPE> vtReturn - the function return type
	*			<LPVOID> pFunc - the pointer to the function to execute
	* Returns:	<HRESULT> Standard COM codes
	* Purpose:	Adds a new member to the methoddata and vtable arrays
	***************************************************************************/

	HRESULT AddMember(BSTR bstrName,DISPID dispid,PARAMDATA* pParamData,
		UINT nParamCount,CALLCONV cc,WORD wFlags,VARTYPE vtReturn,LPVOID pFunc)
	{
		// Default to OK
		HRESULT hr = S_OK;
		// Determine if more memory is needed or not
		if( m_dwNextIndex >= m_dwMethodAlloced )
		{
			// Double the size of the arrays
			hr = Grow();
		}
		if( SUCCEEDED(hr) )
		{
			// Get a ref to the METHODDATA structure we are modifying
			METHODDATA& md = m_pMethodData[m_dwNextIndex];
			// Copy all of the none alloc needing info
			md.cArgs = nParamCount;
			md.cc = cc;
			md.dispid = dispid;
			md.iMeth = m_dwNextIndex;
			md.vtReturn = vtReturn;
			md.wFlags = wFlags;
			// We don't really care if this works, since we only call
			// by the specfied dispid
			md.szName = SysAllocString(bstrName);
			// We need to copy all of the parameters
			hr = CopyParamData(&md.ppdata,pParamData,nParamCount);
			if( SUCCEEDED(hr) )
			{
				// Set the function pointer in the table
				m_pFakeVTable[m_dwNextIndex] = (DWORD)pFunc;
				// Increment the next index position
				m_dwNextIndex++;
			}
			else
			{
				// Free the name
				SysFreeString(md.szName);
				// Clear out this entry
				ZeroMemory(&md,sizeof(METHODDATA));
			}
		}
		return hr;
	}

	/***************************************************************************
	* Function:	CDynamicTypeInfo::Invoke()
	* Author:	Joe Graf
	* Date:		2/14/99
	* Args:		<DISPID> dispid - the dispid of the entry to invoke
	*			<WORD> wFlags - calling flags
	*			<DISPPARAMS*> pDispParams - the dispparams of the method
	*			<VARIANT*> pvtResult - the variant holding the result
	*			<EXCEPINFO*> pExcepInfo - the exception info pointer
	*			<UINT*> pnArgErr - the number of arguments that had errors
	* Returns:	<HRESULT> Standard COM codes
	* Purpose:	Calls a member of the METHODDATA entries using ITypeInfo and
	*			DispInvoke()
	***************************************************************************/

	HRESULT Invoke(DISPID dispid,WORD wFlags,DISPPARAMS* pDispParams,
		VARIANT* pVarResult,EXCEPINFO* pExcepInfo,UINT* pnArgErr)
	{
		// First thing is to create an INTERFACEDATA structure
		INTERFACEDATA id = { m_pMethodData, m_dwNextIndex };
		ITypeInfo* pITypeInfo = NULL;
		// Now, we need to create an ITypeInfo object
		HRESULT hr = CreateDispTypeInfo(&id,LOCALE_SYSTEM_DEFAULT,&pITypeInfo);
		if( SUCCEEDED(hr) )
		{
			// Now let the automation API call the dispatch for us
			hr = DispInvoke(m_pFakeVTable,pITypeInfo,dispid,wFlags,pDispParams,
				pVarResult,pExcepInfo,pnArgErr);
			// Release the ITypeInfo interface
			pITypeInfo->Release();
		}
		return hr;
	}
};

#endif