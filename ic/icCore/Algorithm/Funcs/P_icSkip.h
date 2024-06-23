
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs: SkipVals")
    ic_core_dcl int8_p  ic_call icSkipVals8 (cint8_p  bg, cint8_p  ed, cint8_p  pSetBg, cint8_p  pSetEd) ic_noexc;
    ic_core_dcl int16_p ic_call icSkipVals16(cint16_p bg, cint16_p ed, cint16_p pSetBg, cint16_p pSetEd) ic_noexc;
    ic_core_dcl int32_p ic_call icSkipVals32(cint32_p bg, cint32_p ed, cint32_p pSetBg, cint32_p pSetEd) ic_noexc;
    ic_core_dcl int64_p ic_call icSkipVals64(cint64_p bg, cint64_p ed, cint64_p pSetBg, cint64_p pSetEd) ic_noexc;

ic_info("decs: SkipValsBackward")
    ic_core_dcl int8_p  ic_call icSkipValsBackward8 (cint8_p  bg, cint8_p  ed, cint8_p  pSetBg, cint8_p  pSetEd) ic_noexc;
    ic_core_dcl int16_p ic_call icSkipValsBackward16(cint16_p bg, cint16_p ed, cint16_p pSetBg, cint16_p pSetEd) ic_noexc;
    ic_core_dcl int32_p ic_call icSkipValsBackward32(cint32_p bg, cint32_p ed, cint32_p pSetBg, cint32_p pSetEd) ic_noexc;
    ic_core_dcl int64_p ic_call icSkipValsBackward64(cint64_p bg, cint64_p ed, cint64_p pSetBg, cint64_p pSetEd) ic_noexc;