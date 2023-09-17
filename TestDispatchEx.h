/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Mar 11 23:40:29 1999
 */
/* Compiler settings for D:\ecomm\Components\TestDispatchEx\TestDispatchEx.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
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

#ifndef __TestDispatchEx_h__
#define __TestDispatchEx_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITestDispatchEx_FWD_DEFINED__
#define __ITestDispatchEx_FWD_DEFINED__
typedef interface ITestDispatchEx ITestDispatchEx;
#endif 	/* __ITestDispatchEx_FWD_DEFINED__ */


#ifndef __IDynamicOnly_FWD_DEFINED__
#define __IDynamicOnly_FWD_DEFINED__
typedef interface IDynamicOnly IDynamicOnly;
#endif 	/* __IDynamicOnly_FWD_DEFINED__ */


#ifndef __TestDispatchEx_FWD_DEFINED__
#define __TestDispatchEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class TestDispatchEx TestDispatchEx;
#else
typedef struct TestDispatchEx TestDispatchEx;
#endif /* __cplusplus */

#endif 	/* __TestDispatchEx_FWD_DEFINED__ */


#ifndef __DynamicOnly_FWD_DEFINED__
#define __DynamicOnly_FWD_DEFINED__

#ifdef __cplusplus
typedef class DynamicOnly DynamicOnly;
#else
typedef struct DynamicOnly DynamicOnly;
#endif /* __cplusplus */

#endif 	/* __DynamicOnly_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "dispex.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ITestDispatchEx_INTERFACE_DEFINED__
#define __ITestDispatchEx_INTERFACE_DEFINED__

/* interface ITestDispatchEx */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITestDispatchEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7F6A9B42-C027-11D2-AF24-006008B1252F")
    ITestDispatchEx : public IDispatchEx
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Square( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Number( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Number( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ BSTR bstrVarName,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtVar) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Set( 
            /* [in] */ BSTR bstrVarName,
            /* [in] */ VARIANT vtVar) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITestDispatchExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITestDispatchEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITestDispatchEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDispID )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ DWORD grfdex,
            /* [out] */ DISPID __RPC_FAR *pid);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvokeEx )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ DISPID id,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [in] */ DISPPARAMS __RPC_FAR *pdp,
            /* [out] */ VARIANT __RPC_FAR *pvarRes,
            /* [out] */ EXCEPINFO __RPC_FAR *pei,
            /* [unique][in] */ IServiceProvider __RPC_FAR *pspCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteMemberByName )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ BSTR bstr,
            /* [in] */ DWORD grfdex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteMemberByDispID )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ DISPID id);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMemberProperties )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ DISPID id,
            /* [in] */ DWORD grfdexFetch,
            /* [out] */ DWORD __RPC_FAR *pgrfdex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMemberName )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ DISPID id,
            /* [out] */ BSTR __RPC_FAR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextDispID )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ DWORD grfdex,
            /* [in] */ DISPID id,
            /* [out] */ DISPID __RPC_FAR *pid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNameSpaceParent )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Square )( 
            ITestDispatchEx __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Number )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Number )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Get )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ BSTR bstrVarName,
            /* [retval][out] */ VARIANT __RPC_FAR *pvtVar);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Set )( 
            ITestDispatchEx __RPC_FAR * This,
            /* [in] */ BSTR bstrVarName,
            /* [in] */ VARIANT vtVar);
        
        END_INTERFACE
    } ITestDispatchExVtbl;

    interface ITestDispatchEx
    {
        CONST_VTBL struct ITestDispatchExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITestDispatchEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITestDispatchEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITestDispatchEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITestDispatchEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITestDispatchEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITestDispatchEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITestDispatchEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITestDispatchEx_GetDispID(This,bstrName,grfdex,pid)	\
    (This)->lpVtbl -> GetDispID(This,bstrName,grfdex,pid)

#define ITestDispatchEx_InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller)	\
    (This)->lpVtbl -> InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller)

#define ITestDispatchEx_DeleteMemberByName(This,bstr,grfdex)	\
    (This)->lpVtbl -> DeleteMemberByName(This,bstr,grfdex)

#define ITestDispatchEx_DeleteMemberByDispID(This,id)	\
    (This)->lpVtbl -> DeleteMemberByDispID(This,id)

#define ITestDispatchEx_GetMemberProperties(This,id,grfdexFetch,pgrfdex)	\
    (This)->lpVtbl -> GetMemberProperties(This,id,grfdexFetch,pgrfdex)

#define ITestDispatchEx_GetMemberName(This,id,pbstrName)	\
    (This)->lpVtbl -> GetMemberName(This,id,pbstrName)

#define ITestDispatchEx_GetNextDispID(This,grfdex,id,pid)	\
    (This)->lpVtbl -> GetNextDispID(This,grfdex,id,pid)

#define ITestDispatchEx_GetNameSpaceParent(This,ppunk)	\
    (This)->lpVtbl -> GetNameSpaceParent(This,ppunk)


#define ITestDispatchEx_Square(This)	\
    (This)->lpVtbl -> Square(This)

#define ITestDispatchEx_get_Number(This,pVal)	\
    (This)->lpVtbl -> get_Number(This,pVal)

#define ITestDispatchEx_put_Number(This,newVal)	\
    (This)->lpVtbl -> put_Number(This,newVal)

#define ITestDispatchEx_Get(This,bstrVarName,pvtVar)	\
    (This)->lpVtbl -> Get(This,bstrVarName,pvtVar)

#define ITestDispatchEx_put_Set(This,bstrVarName,vtVar)	\
    (This)->lpVtbl -> put_Set(This,bstrVarName,vtVar)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITestDispatchEx_Square_Proxy( 
    ITestDispatchEx __RPC_FAR * This);


void __RPC_STUB ITestDispatchEx_Square_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITestDispatchEx_get_Number_Proxy( 
    ITestDispatchEx __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB ITestDispatchEx_get_Number_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITestDispatchEx_put_Number_Proxy( 
    ITestDispatchEx __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB ITestDispatchEx_put_Number_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITestDispatchEx_Get_Proxy( 
    ITestDispatchEx __RPC_FAR * This,
    /* [in] */ BSTR bstrVarName,
    /* [retval][out] */ VARIANT __RPC_FAR *pvtVar);


void __RPC_STUB ITestDispatchEx_Get_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITestDispatchEx_put_Set_Proxy( 
    ITestDispatchEx __RPC_FAR * This,
    /* [in] */ BSTR bstrVarName,
    /* [in] */ VARIANT vtVar);


void __RPC_STUB ITestDispatchEx_put_Set_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITestDispatchEx_INTERFACE_DEFINED__ */


#ifndef __IDynamicOnly_INTERFACE_DEFINED__
#define __IDynamicOnly_INTERFACE_DEFINED__

/* interface IDynamicOnly */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDynamicOnly;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F2DE7663-D827-11D2-809B-00500464D4A2")
    IDynamicOnly : public IDispatchEx
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IDynamicOnlyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDynamicOnly __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDynamicOnly __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDynamicOnly __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDispID )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ DWORD grfdex,
            /* [out] */ DISPID __RPC_FAR *pid);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InvokeEx )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ DISPID id,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [in] */ DISPPARAMS __RPC_FAR *pdp,
            /* [out] */ VARIANT __RPC_FAR *pvarRes,
            /* [out] */ EXCEPINFO __RPC_FAR *pei,
            /* [unique][in] */ IServiceProvider __RPC_FAR *pspCaller);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteMemberByName )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ BSTR bstr,
            /* [in] */ DWORD grfdex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteMemberByDispID )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ DISPID id);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMemberProperties )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ DISPID id,
            /* [in] */ DWORD grfdexFetch,
            /* [out] */ DWORD __RPC_FAR *pgrfdex);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMemberName )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ DISPID id,
            /* [out] */ BSTR __RPC_FAR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextDispID )( 
            IDynamicOnly __RPC_FAR * This,
            /* [in] */ DWORD grfdex,
            /* [in] */ DISPID id,
            /* [out] */ DISPID __RPC_FAR *pid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNameSpaceParent )( 
            IDynamicOnly __RPC_FAR * This,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunk);
        
        END_INTERFACE
    } IDynamicOnlyVtbl;

    interface IDynamicOnly
    {
        CONST_VTBL struct IDynamicOnlyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDynamicOnly_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDynamicOnly_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDynamicOnly_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDynamicOnly_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDynamicOnly_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDynamicOnly_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDynamicOnly_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDynamicOnly_GetDispID(This,bstrName,grfdex,pid)	\
    (This)->lpVtbl -> GetDispID(This,bstrName,grfdex,pid)

#define IDynamicOnly_InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller)	\
    (This)->lpVtbl -> InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller)

#define IDynamicOnly_DeleteMemberByName(This,bstr,grfdex)	\
    (This)->lpVtbl -> DeleteMemberByName(This,bstr,grfdex)

#define IDynamicOnly_DeleteMemberByDispID(This,id)	\
    (This)->lpVtbl -> DeleteMemberByDispID(This,id)

#define IDynamicOnly_GetMemberProperties(This,id,grfdexFetch,pgrfdex)	\
    (This)->lpVtbl -> GetMemberProperties(This,id,grfdexFetch,pgrfdex)

#define IDynamicOnly_GetMemberName(This,id,pbstrName)	\
    (This)->lpVtbl -> GetMemberName(This,id,pbstrName)

#define IDynamicOnly_GetNextDispID(This,grfdex,id,pid)	\
    (This)->lpVtbl -> GetNextDispID(This,grfdex,id,pid)

#define IDynamicOnly_GetNameSpaceParent(This,ppunk)	\
    (This)->lpVtbl -> GetNameSpaceParent(This,ppunk)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDynamicOnly_INTERFACE_DEFINED__ */



#ifndef __TESTDISPATCHEXLib_LIBRARY_DEFINED__
#define __TESTDISPATCHEXLib_LIBRARY_DEFINED__

/* library TESTDISPATCHEXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TESTDISPATCHEXLib;

EXTERN_C const CLSID CLSID_TestDispatchEx;

#ifdef __cplusplus

class DECLSPEC_UUID("7F6A9B43-C027-11D2-AF24-006008B1252F")
TestDispatchEx;
#endif

EXTERN_C const CLSID CLSID_DynamicOnly;

#ifdef __cplusplus

class DECLSPEC_UUID("F2DE7664-D827-11D2-809B-00500464D4A2")
DynamicOnly;
#endif
#endif /* __TESTDISPATCHEXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
