
#define IC_CORE_IMPORT
#define IC_IMPORT
#define IC_WIN32_IMPORT
#include"./ic.h"

#pragma comment(lib, "C:/InterestCore/lib/ic.lib")
#pragma comment(lib, "C:/InterestCore/lib/icCore.lib")
#pragma comment(lib, "C:/InterestCore/lib/icWin32.lib")

#if 0
template<typename CHAR_xt, typename...Args>
int xys_win32_box_printf(HWND hWnd, const CHAR_xt* lpCaption, UINT uType, const CHAR_xt* lpFormat, Args...args)
{
    int iSize = xys_c_scprintf_g(lpFormat, args...) + 1;
    CHAR_xt* buf = new CHAR_xt[iSize];
    xys_msvc_sprintf_s_g(buf, iSize, lpFormat, args...);
    int r = xys_win32_MessageBoxG(hWnd, buf, lpCaption, uType);
    delete[]buf;
    return r;
}
#endif

ic_win32_dcl BOOL ic_call icWin32AllocConsoleW(LPCWSTR lpszTitle) ic_noexc;
ic_win32_dcl BOOL ic_call icWin32AllocConsoleA(LPCSTR  lpszTitle) ic_noexc;

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

int main() {
    //icClearConsoleScreen();
    icInit(ic_itf_default_v | ic_itf_console_buffer_v);
    //printf(icICInfo2() "\r\n");
    icHello(ic_hf_default_v);
    icCoreHello(ic_hf_default_v);
    icWin32Hello(ic_hf_default_v);
#if 0
#ifdef IC_OS_WINDOWS
    icWin32Hello();
#else
    icUnixHello();
#endif
#endif
    //printf("%s", icCmdFgClr(255, 0, 0)"红色\r\n");
    //printf("%s", icCmdFgClr(0, 255, 0)"绿色\r\n");
    //printf("%s", icCmdFgClr(0, 0, 255)"蓝色\r\n");
    //printf("%s", icCmdClrReset());
    icUninit();
    //system("pause");
}