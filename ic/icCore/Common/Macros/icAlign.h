
#pragma once

#include"./icInfo.h"

ic_info("ic_alignof")
    #ifdef __cplusplus
        #define ic_alignof               alignof
    #else
        #define ic_alignof               _Alignof
    #endif

ic_info("ic_align")
    #if defined(IC_CE_MSC) || defined(IC_CE_ICC)
        #define ic_align(n)      __declspec(align(n))
    #elif defined(IC_CE_GNUC) || defined(IC_CE_CLANG)
        #define ic_align(n)      __attribute__((aligned(n)))
    #endif