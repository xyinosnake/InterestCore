
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("decs: FindVal")
    ic_core_dcl int8_p  ic_call icFindVal8 (cint8_p  bg, cint8_p  ed, int8_t  val) ic_noexc;
    ic_core_dcl int16_p ic_call icFindVal16(cint16_p bg, cint16_p ed, int16_t val) ic_noexc;
    ic_core_dcl int32_p ic_call icFindVal32(cint32_p bg, cint32_p ed, int32_t val) ic_noexc;
    ic_core_dcl int64_p ic_call icFindVal64(cint64_p bg, cint64_p ed, int64_t val) ic_noexc;