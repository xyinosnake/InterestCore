
#pragma once

#include"../Macros/icWin32CommonMacros.h"
#include"../../icWin32Headers.h"

ic_info("declarations")
    ic_dcl_struct(IC_WIN32_IUNKNOWN_VTBL);

ic_info("definitions")
    struct IC_WIN32_IUNKNOWN_VTBL {
        BEGIN_INTERFACE
        HRESULT(STDMETHODCALLTYPE* QueryInterface)(IUnknown* pThis, REFIID riid, void** ppvObject);
        ULONG  (STDMETHODCALLTYPE* AddRef        )(IUnknown* pThis);
        ULONG  (STDMETHODCALLTYPE* Release       )(IUnknown* pThis);
        END_INTERFACE
    };