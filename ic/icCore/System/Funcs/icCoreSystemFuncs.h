
#pragma once

#include"../../Common/icCoreCommon.h"
#include"../../Geometry/Structs/icCoreGeometryStructs.h"

ic_info("decs")
    ic_core_dcl size_t     ic_call icGetThreadMaxCount() ic_noexc;
    ic_core_dcl size_t     ic_call icGetCPUCoreCount() ic_noexc;
    ic_core_dcl IC_CXY_U32 ic_call icGetScreenCxy() ic_noexc;
    ic_core_dcl bool       ic_call icRunN(cnch_p sCmd) ic_noexc;
    ic_core_dcl bool       ic_call icRunW(cwch_p sCmd) ic_noexc;
    ic_core_dcl bool       ic_call icWriteClipboardN(cnch_p bg, size_t sz) ic_noexc;
    ic_core_dcl bool       ic_call icWriteClipboardW(cwch_p bg, size_t sz) ic_noexc;
    #define                icRun            icRunN
    #define                icWriteClipboard icWriteClipboardN