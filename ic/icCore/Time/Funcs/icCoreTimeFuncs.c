#ifndef IC_CORE_TIME_FUNCS
#define IC_CORE_TIME_FUNCS

#include"./icCoreTimeFuncs.h"
#include"../../MicroPlatforms/icCoreMicroPlatforms.h"

ic_info("definitions")
    ic_core_dcl uint64_t ic_call icBeginPerformanceTest(uint64_t u64Count) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return (uint64_t)icMicroWin32BeginPerformanceTest(u64Count);
    #elif defined(IC_OS_UNIX_LIKE)
        return icMicroUnixBeginPerformanceTest(u64Count);
    #else
        return 0;
    #endif
    }

    ic_core_dcl flo64_t ic_call icEndPerformanceTest() ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return icMicroWin32EndPerformanceTest();
    #elif defined(IC_OS_UNIX_LIKE)
        return icMicroUnixEndPerformanceTest();
    #else
        return 0;
    #endif
    }
#endif