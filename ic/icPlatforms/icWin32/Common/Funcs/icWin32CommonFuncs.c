
#ifndef IC_WIN32_COMMON_FUNCS
#define IC_WIN32_COMMON_FUNCS

#include"./icWin32CommonFuncs.h"
#include"../../../../icCore/MicroPlatforms/Win32/icCoreMicroWin32.h"
#include"../Structs/icWin32CommonStructs.h"

ic_info("definitions")
    ic_win32_dcl void ic_call icWin32Hello(ic_hello_flags_e flags) ic_noexc {
        bool bColored = (icGetBit(icGetInitFlags(), ic_itf_console_color_v) != 0);
        ic_if_do(icGetBit(flags, ic_hf_ic_info_v), icInfoBase(bColored));
        if (icGetBit(flags, ic_hf_current_info_v)) {
            cch8_p name, dep;
            ic_if_else_do_x2(bColored,  
                name = icWin32NameColored(), dep = icWin32DepColored(),
                name = icWin32Name(),        dep = icWin32Dep());
            icHelloBase(bColored, name, dep);
        }
        if (icGetBit(flags, ic_hf_dependences_info_v)) {
            icCoreHello(ic_hf_current_info_v);
        }
        fflush(stdout);
    }

    ic_win32_dcl HINSTANCE ic_call icWin32GetInstance() ic_noexc {
        return GetModuleHandleW(NULL);
    }

    ic_win32_dcl SIZE ic_call icWin32GetScreenCxy() ic_noexc {
        SIZE cxy = {
            GetSystemMetrics(SM_CXSCREEN),
            GetSystemMetrics(SM_CYSCREEN)
        };  
        return cxy;
    }

    ic_win32_dcl BOOL ic_call icWin32Enable(ic_init_flags_e flags) ic_noexc {
        BOOL b = icMicroWin32CoreEnable(flags);
        ic_if_return(!b, b);
        uint32_t* pGlobalFlags = icGetInitFlagsPtr();
        ic_init_if(uint32_t v = ic_itf_process_heap_v, icGetBit(flags, v) && !icGetBit(*pGlobalFlags, v)) {
            b = icWin32EnableProcessHeap(TRUE);
            ic_if_return(!b, b);
            icSetBits(*pGlobalFlags, v);
        }
        return b;
    }

    ic_win32_dcl BOOL ic_call icWin32Disable(ic_init_flags_e flags) ic_noexc {
        BOOL b = icMicroWin32CoreDisable(flags);
        ic_if_return(!b, b);
        uint32_t* pGlobalFlags = icGetInitFlagsPtr();
        ic_init_if(uint32_t v = ic_itf_process_heap_v, icGetBit(flags, v) && icGetBit(*pGlobalFlags, v)) {
            b = icWin32EnableProcessHeap(FALSE);
            ic_if_return(!b, b);
            icClearBits(*pGlobalFlags, v);
        }
        return b;
    }

    ic_win32_dcl void ic_call icWin32CheckReleaseIUnknown(IUnknown** ppI) ic_noexc {
        ic_init_if_do(IUnknown* pI = *ppI, pI, (*(IC_WIN32_IUNKNOWN_VTBL**)pI)->Release(pI));
    }

    ic_win32_dcl void ic_call icWin32CheckReleaseSetNullIUnknown(IUnknown** ppI) ic_noexc {
        ic_init_if_do_x2(IUnknown* pI = *ppI, pI, (*(IC_WIN32_IUNKNOWN_VTBL**)pI)->Release(pI), *ppI = NULL);
    }

    #define icWin32MessageBoxPrintf_m(ch_xt, vsnprintf_xf, MessageBox_xf) \
            int     r = 0; \
            va_list vl; \
            va_start(vl, lpFm); \
                size_t cap = vsnprintf_xf(NULL, 0, lpFm, vl) + 1; \
                ch_xt* buf = (ch_xt*)icPosixAlloc(sizeof(ch_xt) * cap); \
                ic_if_goto(!buf, posEnd); \
                vsnprintf_xf(buf, cap, lpFm, vl); \
                r = MessageBox_xf(hWnd, buf, lpCaption, uType); \
                icPosixDealloc(buf); \
        posEnd: \
            va_end(vl); \
            return r
    ic_win32_dcl int ic_call icWin32MessageBoxPrintfA(HWND hWnd, LPCSTR lpCaption, UINT uType, LPCSTR lpFm, ...) ic_noexc {
        icWin32MessageBoxPrintf_m(nch_t, vsnprintf, MessageBoxA);
    }

    ic_win32_dcl int ic_call icWin32MessageBoxPrintfW(HWND hWnd, LPCWSTR lpCaption, UINT uType, LPCWSTR lpFm, ...) ic_noexc {
        icWin32MessageBoxPrintf_m(wch_t, vsnwprintf, MessageBoxW);
    }
    #undef icWin32MessageBoxPrintf_m
#endif