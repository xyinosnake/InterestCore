
#ifndef IC_CORE_MICRO_PLATFORMS_FUNCS
#define IC_CORE_MICRO_PLATFORMS_FUNCS

#include"../icCoreMicroPlatforms.h"

ic_info("switch os")
    #if defined(IC_OS_WINDOWS)
        #include"../Win32/Funcs/icCoreMicroWin32Funcs.c"
    #elif defined(IC_OS_UNIX_LIKE)
        #include"../Unix/Funcs/icCoreMicroUnixFuncs.c"
    #endif

#endif