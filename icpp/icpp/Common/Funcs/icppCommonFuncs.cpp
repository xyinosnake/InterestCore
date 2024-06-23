
#ifndef ICPP_COMMON_FUNCS
#define ICPP_COMMON_FUNCS

#include"./icppCommonFuncs.h"

ic_info("definitions")
    icpp_dcl void ic_call icppHello(ic_hello_flags_e flags) ic_noexc {
        bool bColored = (icGetBit(icGetInitFlags(), ic_itf_console_color_v) != 0);
        ic_if_do(icGetBit(flags, ic_hf_ic_info_v), icInfoBase(bColored));
	    if (icGetBit(flags, ic_hf_current_info_v)) {
            cch8_p name, dep;
            ic_if_else_do_x2(bColored,  
                name = icppNameColored(), dep = icppDepColored(),
                name = icppName(),        dep = icppDep());
            icHelloBase(bColored, name, dep);
        }
        if (icGetBit(flags, ic_hf_dependences_info_v)) {
		    icCoreHello(ic_hf_current_info_v);
            #if defined(IC_OS_WINDOWS)
                icWin32Hello(ic_hf_current_info_v);
            #elif defined(IC_OS_UNIX_LIKE)
                icUnixHello(ic_hf_current_info_v);
            #endif
            icHello(ic_hf_current_info_v);
	    }
	    fflush(stdout);
    }
#endif