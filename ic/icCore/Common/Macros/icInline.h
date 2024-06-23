
#pragma once

#include"./icEnv.h"
#include"./icInfo.h"

ic_info("Inline & Function")
    #if defined(IC_CE_GNUC) || defined(IC_CE_CLANG)
        #define ic_inline    __attribute__((always_inline)) inline
        #define ic_function  __attribute__((noinline))
    #elif defined(IC_CE_MSC) || defined(IC_CE_ICC)
        #define ic_inline    __forceinline
        #define ic_function  __declspec(noinline)
    #else
        #define ic_inline    inline
        #define ic_function
    #endif

ic_info("mini keywords")
    #define ic_inl ic_inline
    #define ic_fct ic_function