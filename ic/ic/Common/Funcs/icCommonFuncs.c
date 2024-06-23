
#pragma once

#include"./icCommonFuncs.h"

ic_info("definitions")
    ic_dcl void ic_call icHello(ic_hello_flags_e flags) ic_noexc {
        bool bColored = (icGetBit(icGetInitFlags(), ic_itf_console_color_v) != 0);
        ic_if_do(icGetBit(flags, ic_hf_ic_info_v), icInfoBase(bColored));
        if (icGetBit(flags, ic_hf_current_info_v)) {
            cch8_p name, dep;
            ic_if_else_do_x2(bColored,
                name = icNameColored(), dep = icDepColored(),
                name = icName(),        dep = icDep());
            icHelloBase(bColored, name, dep);
        }
        if (icGetBit(flags, ic_hf_dependences_info_v)) {
		    icCoreHello(ic_hf_current_info_v);
            #if defined(IC_OS_WINDOWS)
                icWin32Hello(ic_hf_current_info_v);
            #elif defined(IC_OS_UNIX_LIKE)
                icUnixHello(ic_hf_current_info_v);
            #endif
	    }
	    fflush(stdout);
    }

    ic_dcl bool ic_call icInit(ic_init_flags_e flags) ic_noexc {
        return icEnable(flags);
    }

    ic_dcl bool ic_call icUninit() ic_noexc {
        return icDisable((ic_init_flags_e)icGetInitFlags());
    }

    ic_dcl bool ic_call icEnable(ic_init_flags_e flags) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return icWin32Enable(flags) == TRUE;
    #elif defined(IC_OS_UNIX_LIKE)
        icSetBits(*icGetInitFlagsPtr(), icGetBits(flags, ic_itf_default_v));
        return true;
    #else
        return false;
    #endif
    }

    ic_dcl bool ic_call icDisable(ic_init_flags_e flags) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return icWin32Disable(flags) == TRUE;
    #elif defined(IC_OS_UNIX_LIKE)
        icClearBits(*icGetInitFlagsPtr(), icGetBits(flags, ic_itf_default_v));
        return true;
    #else
        return false;
    #endif
    }

    ic_hide ic_thread_own uint32_t g_icThreadFlags = 0;
    ic_dcl bool ic_call icEnableThread(ic_init_thread_flags_e flags) ic_noexc {
        uint32_p pGlobalFlags = &g_icThreadFlags;
        uint32_t v;
        ic_init_if(v = ic_ittf_thread_heap_v, icGetBit(flags, v) && !icGetBit(*pGlobalFlags, v)) {
        #if defined(IC_OS_WINDOWS)
            BOOL b = icWin32EnableThreadHeap(TRUE);
            ic_if_return(!b, false);
        #endif
            icSetBits(*pGlobalFlags, v);
        }
        return true;
    }

    ic_dcl bool ic_call icDisableThread(ic_init_thread_flags_e flags) ic_noexc {
        uint32_t* pGlobalFlags = &g_icThreadFlags;
        uint32_t  v;
        ic_init_if(v = ic_ittf_thread_heap_v, icGetBit(flags, v) && icGetBit(*pGlobalFlags, v)) {
        #if defined(IC_OS_WINDOWS)
            BOOL b = icWin32EnableThreadHeap(FALSE);
            ic_if_return(!b, false);
        #endif
            icClearBits(*pGlobalFlags, v);
        }
        return true;
    }
