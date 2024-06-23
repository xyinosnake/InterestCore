
#pragma once

#include"../Macros/icCoreCommonMacros.h"

ic_info("headers")
    #ifdef __cplusplus
        #include<cstdint>
    #else
        #include<stdint.h>
    #endif
    #include"./ic_def_t.h"

ic_info("ch8_t & ch16_t & ch32_t")
    #ifndef __cplusplus
    ic_info("C Mode")
        ic_def_t(ch8_t,  cch8_t,  ch8_p,  cch8_p,  char);
        ic_def_t(ch16_t, cch16_t, ch16_p, cch16_p, wchar_t);
        ic_def_t(ch32_t, cch32_t, ch32_p, cch32_p, int32_t);
    #else
    ic_info("C++ Mode")
        ic_def_t(ch8_t,  cch8_t,  ch8_p,  cch8_p,  char);
        ic_def_t(ch16_t, cch16_t, ch16_p, cch16_p, wchar_t);
        ic_def_t(ch32_t, cch32_t, ch32_p, cch32_p, char32_t);
    #endif

ic_info("nch_t & wch_t")
    ic_def_t(nch_t, cnch_t, nch_p, cnch_p, ch8_t);
    ic_def_t(wch_t, cwch_t, wch_p, cwch_p, wchar_t);
    ic_def_t(ach_t, cach_t, ach_p, cach_p, ch8_t); //Windows专有
