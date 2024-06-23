
#pragma once

#include"./P_icFind.h"

ic_info("defs")
    #define icFindVal_m(val_xt, b) \
        ic_while_do_x2_return(bg != ed, ic_if_break(b), ++bg, (val_xt*)bg)
    ic_core_dcl int8_p ic_call icFindVal8(cint8_p bg, cint8_p ed, int8_t val) ic_noexc {
        icFindVal_m(int8_t, *bg == val);
    }

    ic_core_dcl int16_p ic_call icFindVal16(cint16_p bg, cint16_p ed, int16_t val) ic_noexc {
        icFindVal_m(int16_t, *bg == val);
    }

    ic_core_dcl int32_p ic_call icFindVal32(cint32_p bg, cint32_p ed, int32_t val) ic_noexc {
        icFindVal_m(int32_t, *bg == val);
    }

    ic_core_dcl int64_p ic_call icFindVal64(cint64_p bg, cint64_p ed, int64_t val) ic_noexc {
        icFindVal_m(int64_t, *bg == val);
    }
    #undef icFindVal_m