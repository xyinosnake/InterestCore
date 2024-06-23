
#pragma once

#include"../Macros/icWin32CommonMacros.h"
#include"../../../../icCore/Common/Funcs/icCoreCommonFuncs.h"
#include"../../icWin32Headers.h"

ic_info("icWin32Name & icWin32Dep")
    #define icWin32Name()        "icWin32"
    #define icWin32NameColored() icCmdFgClr(255, 128, 255) icWin32Name() icCmdClrReset()
    #define icWin32Dep()         icWin32Name() "(" icCoreDep() ")"
    #define icWin32DepColored()  icWin32NameColored() icCmdFgClr(64, 255, 64) "(" icCoreDepColored() icCmdFgClr(64, 255, 64) ")" icCmdClrReset()

ic_info("declarations")
    ic_win32_dcl void      ic_call icWin32Hello(ic_hello_flags_e flags ic_dfv(ic_hf_default_v)) ic_noexc;
    ic_win32_dcl HINSTANCE ic_call icWin32GetInstance() ic_noexc;
    ic_win32_dcl SIZE      ic_call icWin32GetScreenCxy() ic_noexc;
    ic_win32_dcl BOOL      ic_call icWin32Enable(ic_init_flags_e flags) ic_noexc;
    ic_win32_dcl BOOL      ic_call icWin32Disable(ic_init_flags_e flags) ic_noexc;
    ic_win32_dcl void      ic_call icWin32CheckReleaseIUnknown(IUnknown** ppI) ic_noexc;
    ic_win32_dcl void      ic_call icWin32CheckReleaseSetNullIUnknown(IUnknown** ppI) ic_noexc;
    #define                        icWin32CheckRelease(pRefCOM)         icWin32CheckReleaseIUnknown((IUnknown**)&pRefCOM)
    #define                        icWin32CheckReleaseSetNull(pRefCOM)  icWin32CheckReleaseSetNullIUnknown((IUnknown**)&pRefCOM)
    ic_win32_dcl int       ic_call icWin32MessageBoxPrintfA(HWND hWnd, LPCSTR  lpCaption, UINT uType, LPCSTR  lpFm, ...) ic_noexc;
    ic_win32_dcl int       ic_call icWin32MessageBoxPrintfW(HWND hWnd, LPCWSTR lpCaption, UINT uType, LPCWSTR lpFm, ...) ic_noexc;
    #define                        icWin32MBPrintfA                     icWin32MessageBoxPrintfA
    #define                        icWin32MBPrintfW                     icWin32MessageBoxPrintfW