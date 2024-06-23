
#pragma once

#include"../../Common/Macros/icWin32CommonMacros.h"
#include"../../icWin32Headers.h"

ic_info("declarations")
    ic_win32_dcl HICON ic_call icWin32ExtractIconW(LPCWSTR pszPath, int size, int iIndex ic_dfv(0)) ic_noexc;
    ic_win32_dcl HICON ic_call icWin32ExtractIconA(LPCSTR  pszPath, int size, int iIndex ic_dfv(0)) ic_noexc;
    ic_win32_dcl HICON ic_call icWin32ExtractLinkMiniIcon(int size) ic_noexc;
    ic_win32_dcl BOOL  ic_call icWin32GetIconSize(HICON hIcon, SIZE* sz, INT* bitsPerPixel ic_dfv(NULL)) ic_noexc;