
#pragma once

#include"./icInfo.h"

ic_info("noXX { ic_noexcept, ic_nodiscard }")
    #if defined(__cplusplus) && !defined(IC_NO_NOEXCEPT)
        #define ic_noexcept                    noexcept
    #else
        #define ic_noexcept
    #endif

    #if defined(__cplusplus) && !defined(IC_NO_NODISCARD)
        #define ic_nodiscard                   [[nodiscard]]
    #else
        #define ic_nodiscard
    #endif

ic_info("mini keywords")
    #define ic_noexc ic_noexcept
    #define ic_nodis ic_nodiscard