
#pragma once

#include"../../Common/Types/icCoreCommonTypes.h"

ic_info("color types")
    ic_alias(RGBA_t,  uint32_t); //Same to IC_32_RGBA_U8X4.
    ic_alias(BGRA_t,  uint32_t); //Same to IC_32_BGRA_U8X4.
    ic_alias(color_t, RGBA_t);   //IC default color type.