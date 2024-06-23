
#pragma once

#include"./P_icSkipS.h"

ic_info("definitions")

#define icSkipXX_m(ch_xt, b) \
    while (bg != ed) {\
        ic_if_break(b);\
        ++bg;\
    }\
    return (ch_xt*)bg

    ic_core_dcl ch8_p ic_call icSkipSpaces8(cch8_p bg, cch8_p ed) ic_noexc {
        icSkipXX_m(ch8_t, !isspace(*bg));
    }

    ic_core_dcl ch16_p ic_call icSkipSpaces16(cch16_p bg, cch16_p ed) ic_noexc {
        icSkipXX_m(ch16_t, !iswspace((wch_t)*bg));
    }

    ic_core_dcl ch32_p ic_call icSkipSpaces32(cch32_p bg, cch32_p ed) ic_noexc {
        icSkipXX_m(ch32_t, !iswspace((wch_t)*bg));
    }

    ic_core_dcl ch8_p ic_call icSkipGraphs8(cch8_p bg, cch8_p ed) ic_noexc {
        icSkipXX_m(ch8_t, !isgraph(*bg));
    }

    ic_core_dcl ch16_p ic_call icSkipGraphs16(cch16_p bg, cch16_p ed) ic_noexc {
        icSkipXX_m(ch16_t, !iswgraph((wch_t)*bg));
    }

    ic_core_dcl ch32_p ic_call icSkipGraphs32(cch32_p bg, cch32_p ed) ic_noexc {
        icSkipXX_m(ch32_t, !iswgraph((wch_t)*bg));
    }

#undef icSkipXX_m

#define icSkipXXBackward_m(ch_xt, b) \
    while(bg != ed) {\
        --ed;\
        ic_if_do_and_break(b, ++ed);\
    }\
    return (ch_xt*)ed

    ic_core_dcl ch8_p ic_call icSkipSpacesBackward8(cch8_p bg, cch8_p ed) ic_noexc {
        icSkipXXBackward_m(ch8_t, !isspace(*ed));
    }

    ic_core_dcl ch16_p ic_call icSkipSpacesBackward16(cch16_p bg, cch16_p ed) ic_noexc {
        icSkipXXBackward_m(ch16_t, !iswspace((wch_t)*ed));
    }

    ic_core_dcl ch32_p ic_call icSkipSpacesBackward32(cch32_p bg, cch32_p ed) ic_noexc {
        icSkipXXBackward_m(ch32_t, !iswspace((wch_t)*ed));
    }

    ic_core_dcl ch8_p ic_call icSkipGraphsBackward8(cch8_p bg, cch8_p ed) ic_noexc {
        icSkipXXBackward_m(ch8_t, !isgraph(*ed));
    }

    ic_core_dcl ch16_p ic_call icSkipGraphsBackward16(cch16_p bg, cch16_p ed) ic_noexc {
        icSkipXXBackward_m(ch16_t, !iswgraph((wch_t)*ed));
    }

    ic_core_dcl ch32_p ic_call icSkipGraphsBackward32(cch32_p bg, cch32_p ed) ic_noexc {
        icSkipXXBackward_m(ch32_t, !iswgraph((wch_t)*ed));
    }
#undef icSkipXXBackward_m