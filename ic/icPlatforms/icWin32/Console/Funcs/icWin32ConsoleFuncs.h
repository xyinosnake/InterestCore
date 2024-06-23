
#pragma once

#include"../../Common/Macros/icWin32CommonMacros.h"
#include"../../icWin32Headers.h"

ic_info("declarations")
    ic_win32_dcl void ic_call icWin32RelinkPosixStdHandles() ic_noexc;
    ic_win32_dcl BOOL ic_call icWin32AllocConsoleW(LPCWSTR lpszTitle ic_dfv(NULL)) ic_noexc;
    ic_win32_dcl BOOL ic_call icWin32AllocConsoleA(LPCSTR  lpszTitle ic_dfv(NULL)) ic_noexc;
    ic_win32_dcl void ic_call icWin32WaitAttachConsole(DWORD dwProcessId, DWORD dwWaitMilliseconds ic_dfv(10)) ic_noexc;