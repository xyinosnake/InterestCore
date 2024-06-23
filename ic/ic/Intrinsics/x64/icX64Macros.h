
#pragma once

#include"../../Common/Macros/icCommonMacros.h"

ic_info("AVX512")
    #ifndef IC_AVX512
        #ifdef IC_MSC
            #if _MSC_VER >= 1928
                #define IC_AVX512 1
            #endif
        #endif
    #endif

    #ifndef IC_AVX512
        #ifdef __GNUC__
            #if __GNUC__ > 6
                #define IC_AVX512 1
            #endif
        #endif
    #endif

    #ifndef IC_AVX512
        #ifdef __clang__
            #if __clang_major__ >= 6
                #define IC_AVX512 0 //暂时不主动开启AVX512
            #endif
        #endif
    #endif

    #ifndef IC_AVX512
        #define IC_AVX512 0
    #endif