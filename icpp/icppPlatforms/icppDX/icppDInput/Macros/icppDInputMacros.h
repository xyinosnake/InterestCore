
#pragma once

#include"./icppDInputLink.h"
#include"../../../../icpp/Common/Macros/icppCommonMacros.h"

ic_info("ICPP DINPUT COOPERATIVE LEVEL")
    #define ICPP_DINPUT_COOPERATIVE_LEVEL_0    DISCL_NONEXCLUSIVE | DISCL_BACKGROUND
    #define ICPP_DINPUT_COOPERATIVE_LEVEL_1    DISCL_EXCLUSIVE | DISCL_BACKGROUND | DISCL_NOWINKEY