
#pragma once

#include"./icEnv.h"
#include"./icInfo.h"

ic_info("ic_thread_own")
    #if defined(IC_CE_MSC)
        #define ic_thread_own __declspec(thread)
    #elif defined(IC_CE_GNUC) || defined(IC_CE_CLANG) || defined(IC_CE_ICC)
        #define ic_thread_own __thread
    #endif

ic_info("mini keywords")
    #define ic_tho ic_thread_own