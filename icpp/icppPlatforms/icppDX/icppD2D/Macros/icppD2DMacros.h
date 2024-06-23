
#pragma once

#include"./icppD2DLink.h"
#include"../../../../icpp/Common/Macros/icppCommonMacros.h"

#ifdef IC_DEBUG
    #define ICPP_D2D_DEFAULT_DEBUG_LEVEL D2D1_DEBUG_LEVEL_INFORMATION
#else
    #define ICPP_D2D_DEFAULT_DEBUG_LEVEL D2D1_DEBUG_LEVEL_NONE
#endif