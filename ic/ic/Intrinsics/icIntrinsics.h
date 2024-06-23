
#pragma once

#include"../Common/Macros/icCommonMacros.h"

ic_info("CPU")
    #if defined(IC_M_x86_64)
        #include"./x64/icX64.h"
    #else
    #endif