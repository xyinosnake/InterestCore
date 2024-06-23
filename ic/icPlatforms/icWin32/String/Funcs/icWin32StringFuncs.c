
#ifndef IC_WIN32_STRING_FUNCS
#define IC_WIN32_STRING_FUNCS

#include"./icWin32StringFuncs.h"

ic_win32_dcl size_t ic_call icWin32StrAToStrW(WCHAR* dst, const CHAR* strAString, size_t length, UINT codePage) ic_noexc {
    ic_if_return(!length, length); //MB_ERR_INVALID_CHARS在该函数可用，但为了形式统一，不使用该参数。
    length = (size_t)MultiByteToWideChar(codePage, 0, strAString, (int)(length), dst, dst ? 0x7FFFFFFF : 0);
    ic_if_do(length == 0, length = IC_WIN32_STR_FMT_ERR);
    return length;
}

ic_win32_dcl size_t ic_call icWin32StrWToStrA(CHAR* dst, const WCHAR* strWString, size_t length, UINT codePage) ic_noexc {
    ic_if_return(!length, length); //实测使用MB_ERR_INVALID_CHARS会产生问题。
    length = (size_t)WideCharToMultiByte(codePage, 0, strWString, (int)(length), dst, dst ? 0x7FFFFFFF : 0, NULL, NULL);
    ic_if_do(length == 0, length = IC_WIN32_STR_FMT_ERR);
    return length;
}

#define icWin32SToSMixedP3_m(CHAR_XT, icWin32StrXToStrX_xf) \
    size_t lenNeed = icWin32StrXToStrX_xf(NULL, s, sLen, codePage); \
    ic_if_return(lenNeed == IC_WIN32_STR_FMT_ERR, NULL); \
    CHAR_XT* pData = (CHAR_XT*)icCreateMixedP3(pMixedP3, btStaticCap, sizeof(CHAR_XT) * lenNeed, sizeof(CHAR_XT), pAlloc); \
    ic_if_do(pData, icWin32StrXToStrX_xf(pData, s, sLen, codePage)); \
    return pData

ic_win32_dcl CHAR* ic_call icWin32WToAMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap, 
    const WCHAR* s, size_t sLen, UINT codePage, const IC_ALLOC* pAlloc) ic_noexc {
    icWin32SToSMixedP3_m(CHAR, icWin32StrWToStrA);
}

ic_win32_dcl WCHAR* ic_call icWin32AToWMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap,
    const CHAR* s, size_t sLen, UINT codePage, const IC_ALLOC* pAlloc) ic_noexc {
    icWin32SToSMixedP3_m(WCHAR, icWin32StrAToStrW);
}
#undef icWin32SToSMixedP3_m

#define icWin32GetFullPathDir_m(CHAR_XT, GetFullPathName_xf, icStrLen_xf) \
    ic_stv_x2(CHAR_XT*, pszFilePart, lpEndBuffer); \
	DWORD dw = GetFullPathName_xf(lpFileName, nBufferLength, lpBuffer, &pszFilePart); \
    ic_if_goto(nBufferLength < dw, posEnd); \
    ic_if_do_x3(pszFilePart, lpEndBuffer = lpBuffer + icStrLen_xf(lpBuffer) - icStrLen_xf(pszFilePart),  \
        *lpEndBuffer = 0, dw = (DWORD)(lpEndBuffer - lpBuffer)); \
    ic_label_return(posEnd, dw)

ic_win32_dcl DWORD ic_call icWin32GetFullPathDirW(WCHAR* lpBuffer, DWORD nBufferLength, const WCHAR* lpFileName) ic_noexc {
    icWin32GetFullPathDir_m(WCHAR, GetFullPathNameW, icStrLenW);
}

ic_win32_dcl DWORD ic_call icWin32GetFullPathDirA(CHAR* lpBuffer, DWORD nBufferLength, const CHAR* lpFileName) ic_noexc {
    icWin32GetFullPathDir_m(CHAR, GetFullPathNameA, icStrLenA);
}
#undef icWin32GetFullPathDir_m

#endif