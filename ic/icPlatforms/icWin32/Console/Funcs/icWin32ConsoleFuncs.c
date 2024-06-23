#ifndef IC_WIN32_CONSOLE_FUNCS
#define IC_WIN32_CONSOLE_FUNCS

#include"./icWin32ConsoleFuncs.h"

ic_info("definitions")
    ic_win32_dcl void ic_call icWin32RelinkPosixStdHandles() ic_noexc {
        FILE* noUse; //控制台屏幕IO    
        freopen_s(&noUse, "CONOUT$", "w", stdout);
        freopen_s(&noUse, "CONIN$",  "r", stdin);
        freopen_s(&noUse, "CONERR$", "w", stderr);
    }

    #define icWin32AllocConsole_m(SetConsoleTitle_m) \
        BOOL b = AllocConsole(); \
        ic_if_do_x2(b, ic_if_do(lpszTitle, \
            SetConsoleTitle_m(lpszTitle)), icWin32RelinkPosixStdHandles()); \
        return b

    ic_win32_dcl BOOL ic_call icWin32AllocConsoleW(LPCWSTR lpszTitle) ic_noexc {
        icWin32AllocConsole_m(SetConsoleTitleW); //分配控制台, 设置标题并重新链接Posix标准句柄
    }

    ic_win32_dcl BOOL ic_call icWin32AllocConsoleA(LPCSTR lpszTitle) ic_noexc {
        icWin32AllocConsole_m(SetConsoleTitleA); //分配控制台, 设置标题并重新链接Posix标准句柄
    }

    ic_win32_dcl void ic_call icWin32WaitAttachConsole(DWORD dwProcessId, DWORD dwWaitMilliseconds) ic_noexc {
        ic_while_do(!AttachConsole(dwProcessId), Sleep(dwWaitMilliseconds));            
    }
#endif