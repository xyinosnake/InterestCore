
#pragma once

#include"../../Common/Macros/icCommonMacros.h"
#include"../../Common/icCommon.h"

ic_info("headers")
    #if defined(IC_OS_WINDOWS)
        #include<intrin.h> //VC
        #include<winnt.h>
    #elif defined(IC_OS_LINUX)
        #include<x86intrin.h>
    #endif

/*
    #if defined(IC_CE_CLANG)
        #include<intrin.h>
    #endif
*/