
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("headers")
    #include"../../Common/Types/icCoreCommonTypes.h"
    #include"../../Common/icCoreHeaders.h"

ic_info("macros")
    #define ic_performance_begin(u64Count)  for (uint64_t __ic_H_Count = icBeginPerformanceTest(u64Count); __ic_H_Count; --__ic_H_Count)
    #define ic_performance_end()            icEndPerformanceTest()

ic_info("declarations")
    ic_core_dcl uint64_t ic_call icBeginPerformanceTest(uint64_t u64Count) ic_noexc;
    ic_core_dcl flo64_t  ic_call icEndPerformanceTest() ic_noexc;