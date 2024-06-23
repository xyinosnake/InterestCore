
#pragma once

#include"./P_icCompareS.h"

ic_info("definitions")
    #define icSameStrSize_m(ch_xt, toLower_xf) \
        ic_if_return(sz1 != sz2, false);\
        const ch_xt* sz1Ed = s1 + sz1;\
        while (s1 != sz1Ed) {\
            ic_if_return(toLower_xf(*s1) != toLower_xf(*s2), false);\
            ic_inc_x2(s1, s2);\
        }\
        return true
    ic_core_dcl bool ic_call icSameStrSizeCI8(cch8_p s1, size_t sz1, cch8_p s2, size_t sz2) ic_noexc {
        icSameStrSize_m(ch8_t, icToLower8);
    }

    ic_core_dcl bool ic_call icSameStrSizeCI16(cch16_p s1, size_t sz1, cch16_p s2, size_t sz2) ic_noexc {
        icSameStrSize_m(ch16_t, icToLower16);
    }

    ic_core_dcl bool ic_call icSameStrSizeCI32(cch32_p s1, size_t sz1, cch32_p s2, size_t sz2) ic_noexc {
        icSameStrSize_m(ch32_t, icToLower32);
    }
    #undef icSameStrSize_m

    ic_core_dcl ch8_p ic_call icStrToLower8(ch8_p dst, cch8_p bg, cch8_p ed) ic_noexc {
        ic_while_do_return(bg != ed, *dst++ = icToLower8(*bg++), dst);
    }

    ic_core_dcl ch16_p ic_call icStrToLower16(ch16_p dst, cch16_p bg, cch16_p ed) ic_noexc {
        ic_while_do_return(bg != ed, *dst++ = icToLower16(*bg++), dst);
    }

    ic_core_dcl ch32_p ic_call icStrToLower32(ch32_p dst, cch32_p bg, cch32_p ed) ic_noexc {
        ic_while_do_return(bg != ed, *dst++ = icToLower32(*bg++), dst);
    }

    ic_core_dcl ch8_p ic_call icStrToUpper8(ch8_p dst, cch8_p bg, cch8_p ed) ic_noexc {
        ic_while_do_return(bg != ed, *dst++ = icToUpper8(*bg++), dst);
    }

    ic_core_dcl ch16_p ic_call icStrToUpper16(ch16_p dst, cch16_p bg, cch16_p ed) ic_noexc {
        ic_while_do_return(bg != ed, *dst++ = icToUpper16(*bg++), dst);
    }

    ic_core_dcl ch32_p ic_call icStrToUpper32(ch32_p dst, cch32_p bg, cch32_p ed) ic_noexc {
        ic_while_do_return(bg != ed, *dst++ = icToUpper32(*bg++), dst);
    }
