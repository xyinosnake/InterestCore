
#pragma once

#include"../../../Common/Macros/icCommonMacros.h"
#include"../../../Common/Types/icCommonTypes.h"
#include"../icX64Headers.h"
#include"../icX64Macros.h"
#include"../icX64Types.h"
#include"../icX64Structs.h"

ic_info("Parts")
    #include"./P_icPmt128.h"
    #include"./P_icPmt256.h"
    #include"./P_icPmt512.h"
    #include"./P_icRdRand_RdSeed.h"

ic_info("icCPUID")
    #if defined(IC_OS_WINDOWS)
        #define icCPUID __cpuidex
    #elif defined(IC_OS_UNIX_LIKE)
        #define icCPUID icGetCPUID
    #endif

ic_info("declarations")
    ic_dcl bool   ic_call icGetCPUID(int CPUInfo[4], int Function, int SubLeaf) ic_noexc;
    ic_dcl bool   ic_call icGetCPUFeatures(IC_CPU_FEATURES* cf) ic_noexc;
    ic_dcl size_t ic_call icCPUFeaturesToS8(ch8_t* dst, IC_CPU_FEATURES* pCf) ic_noexc;

ic_info("*.c")
    #if ic_need_c
        #include"./icIntrinsicsFuncs.c"
    #endif