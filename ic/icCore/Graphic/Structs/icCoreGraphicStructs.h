
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"
#include"../../Common/Types/icCoreCommonTypes.h"

ic_info("declarations")
    ic_dcl_struct(IC_32_RGBA_U8X4);
    ic_dcl_struct(IC_32_BGRA_U8X4);
    ic_dcl_struct(IC_128_RGBA_F32X4);
    ic_dcl_struct(IC_128_BGRA_F32X4);

ic_info("definitions")
    struct IC_32_RGBA_U8X4 {
        uint8_t R, G, B, A;
    };

    struct IC_32_BGRA_U8X4 {
        uint8_t B, G, R, A;
    };

    struct IC_128_RGBA_F32X4 {
        flo32_t R, G, B, A;
    };

    struct IC_128_BGRA_F32X4 {
        flo32_t B, G, R, A;
    };