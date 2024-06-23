
#pragma once

#include"./P_icSkip.h"
#include"./P_icFind.h"

ic_info("defs")
    #define icSkipVals_m(val_xt, b) \
        ic_while_do_x2_return(bg != ed, ic_if_break(b), ++bg, (val_xt*)bg)
    ic_core_dcl int8_p ic_call icSkipVals8(cint8_p bg, cint8_p  ed, cint8_p  pSetBg, cint8_p  pSetEd) ic_noexc {
        icSkipVals_m(int8_t, icFindVal8(pSetBg, pSetEd, *bg) == pSetEd);
    }

    ic_core_dcl int16_p ic_call icSkipVals16(cint16_p bg, cint16_p ed, cint16_p pSetBg, cint16_p pSetEd) ic_noexc {
        icSkipVals_m(int16_t, icFindVal16(pSetBg, pSetEd, *bg) == pSetEd);
    }

    ic_core_dcl int32_p ic_call icSkipVals32(cint32_p bg, cint32_p ed, cint32_p pSetBg, cint32_p pSetEd) ic_noexc {
        icSkipVals_m(int32_t, icFindVal32(pSetBg, pSetEd, *bg) == pSetEd);
    }

    ic_core_dcl int64_p ic_call icSkipVals64(cint64_p bg, cint64_p ed, cint64_p pSetBg, cint64_p pSetEd) ic_noexc {
        icSkipVals_m(int64_t, icFindVal64(pSetBg, pSetEd, *bg) == pSetEd);
    }
    #undef icSkipVals_m

    #define icSkipValsBackward_m(val_xt, b) \
        ic_while_do_x2_return(bg != ed, --ed, ic_if_do_and_break(b, ++ed), (val_xt*)ed)
    ic_core_dcl int8_p ic_call icSkipValsBackward8(cint8_p bg, cint8_p ed, cint8_p pSetBg, cint8_p pSetEd) ic_noexc {
        icSkipValsBackward_m(int8_t, icFindVal8(pSetBg, pSetEd, *ed) == pSetEd);
    }

    ic_core_dcl int16_p ic_call icSkipValsBackward16(cint16_p bg, cint16_p ed, cint16_p pSetBg, cint16_p pSetEd) ic_noexc {
        icSkipValsBackward_m(int16_t, icFindVal16(pSetBg, pSetEd, *ed) == pSetEd);
    }

    ic_core_dcl int32_p ic_call icSkipValsBackward32(cint32_p bg, cint32_p ed, cint32_p pSetBg, cint32_p pSetEd) ic_noexc {
        icSkipValsBackward_m(int32_t, icFindVal32(pSetBg, pSetEd, *ed) == pSetEd);
    }

    ic_core_dcl int64_p ic_call icSkipValsBackward64(cint64_p bg, cint64_p ed, cint64_p pSetBg, cint64_p pSetEd) ic_noexc {
        icSkipValsBackward_m(int64_t, icFindVal64(pSetBg, pSetEd, *ed) == pSetEd);
    }
    #undef icSkipValsBackward_m