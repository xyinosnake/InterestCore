
#pragma once

#include"../../Common/Types/icCoreCommonTypes.h"

ic_info("Fractions")
    ic_dcl_struct(IC_FRAC16 );
    ic_dcl_struct(IC_FRAC32 );
    ic_dcl_struct(IC_FRAC64 );
    ic_dcl_struct(IC_FRAC128);

ic_info("Fractions")
    struct IC_FRAC16 {
        int8_t num; //numerator
        int8_t den; //denominator
    };
    
    struct IC_FRAC32 {
        int16_t num; //numerator
        int16_t den; //denominator
    };
    
    struct IC_FRAC64 {
        int32_t num; //numerator
        int32_t den; //denominator
    };
    
    struct IC_FRAC128 {
        int64_t num; //numerator
        int64_t den; //denominator
    };