
#ifndef IC_UNIX_COMMON_FUNCS
#define IC_UNIX_COMMON_FUNCS

#include"./icUnixCommonFuncs.h"

ic_info("definitions")
    ic_unix_dcl void ic_call icUnixHello(ic_hello_flags_e flags) ic_noexc {
        bool bColored = (icGetBit(icGetInitFlags(), ic_itf_console_color_v) != 0);
        ic_if_do(icGetBit(flags, ic_hf_ic_info_v), icInfoBase(bColored));
	    if (icGetBit(flags, ic_hf_current_info_v)) {
            cch8_p name, dep;
            ic_if_else_do_x2(bColored,  
                name = icUnixNameColored(), dep = icUnixDepColored(),
                name = icUnixName(),        dep = icUnixDep());
            icHelloBase(bColored, name, dep);
        }
        if (icGetBit(flags, ic_hf_dependences_info_v)) {
            icCoreHello(ic_hf_current_info_v);
        }
        fflush(stdout);
    }
#endif