
#pragma once

#include"../Common/Macros/icCoreCommonMacros.h"
#include"./Funcs/icCoreMicroPlatformsFuncs.h"

ic_info("switch os")
    #if defined(IC_OS_WINDOWS)
        #include"./Win32/icCoreMicroWin32.h"
    #elif defined(IC_OS_UNIX_LIKE)
        #include"./Unix/icCoreMicroUnix.h"
    #endif