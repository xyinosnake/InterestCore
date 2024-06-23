
#pragma once

#include"../../../../icCore/icCore.h"
#include"../../icWin32Headers.h"

ic_info("declarations")
    ic_dcl_f(IC_WIN32_MSG_PROC, ic_win32_call, LRESULT)(HWND hWnd, void* pWndData, WPARAM wParam, LPARAM lParam) ic_noexc;
    ic_alias(IC_WIN32_MSG_FUNC, IC_WIN32_MSG_PROC);
    ic_alias(ic_win32_msg_f, IC_WIN32_MSG_FUNC);

ic_info("alias - For Win32 short style")
    ic_alias(MSGPROC, IC_WIN32_MSG_PROC);
    ic_alias(MSGFUNC, IC_WIN32_MSG_FUNC);

ic_info("win32 func def")
    #define ic_win32_def_msg_f(funcName, hWnd, pWndData, wParam, lParam) LRESULT ic_win32_call funcName(HWND hWnd, void* pWndData, WPARAM wParam, LPARAM lParam) ic_noexc