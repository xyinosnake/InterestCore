
#pragma once

#include"../../Common/icWin32Common.h"

ic_info("declarations")
    ic_win32_dcl size_t ic_call icWin32StrAToStrW(WCHAR* dst, const  CHAR* strAString, size_t length, UINT codePage ic_dfv(CP_ACP)) ic_noexc;
    ic_win32_dcl size_t ic_call icWin32StrWToStrA( CHAR* dst, const WCHAR* strWString, size_t length, UINT codePage ic_dfv(CP_ACP)) ic_noexc;
    ic_win32_dcl CHAR*  ic_call icWin32WToAMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap, const WCHAR* s, size_t sLen, UINT codePage, const IC_ALLOC* pAlloc) ic_noexc;
    ic_win32_dcl WCHAR* ic_call icWin32AToWMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap, const  CHAR* s, size_t sLen, UINT codePage, const IC_ALLOC* pAlloc) ic_noexc;
    ic_win32_dcl DWORD  ic_call icWin32GetFullPathDirW(WCHAR* lpBuffer, DWORD nBufferLength, const WCHAR* lpFileName) ic_noexc;
    ic_win32_dcl DWORD  ic_call icWin32GetFullPathDirA( CHAR* lpBuffer, DWORD nBufferLength, const  CHAR* lpFileName) ic_noexc;
    ic_inl       WCHAR* ic_call icWin32CStrAToWMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap, const  CHAR* csA, UINT codePage, const IC_ALLOC* pAlloc) ic_noexc;
    ic_inl       CHAR*  ic_call icWin32CStrWToAMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap, const WCHAR* csW, UINT codePage, const IC_ALLOC* pAlloc) ic_noexc;

ic_info("inline definitions")
    ic_inl WCHAR* ic_call icWin32CStrAToWMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap, const  CHAR* csA, UINT codePage, const IC_ALLOC* pAlloc) ic_noexc {
        WCHAR* pData = icWin32AToWMixedP3(pMixedP3, btStaticCap, csA, icStrLenA(csA), codePage, pAlloc);
        ic_if_do(pData, *pData = (WCHAR)'\0');
        return pData;
    }

    ic_inl CHAR* ic_call icWin32CStrWToAMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap, const WCHAR* csW, UINT codePage, const IC_ALLOC* pAlloc) ic_noexc {
        CHAR* pData = icWin32WToAMixedP3(pMixedP3, btStaticCap, csW, icStrLenW(csW), codePage, pAlloc);
        ic_if_do(pData, *pData = (CHAR)'\0');
        return pData;
    }
