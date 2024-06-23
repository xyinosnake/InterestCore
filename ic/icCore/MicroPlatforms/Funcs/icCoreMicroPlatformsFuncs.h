
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("switch os")
    #if defined(IC_OS_WINDOWS)
        #include"../Win32/Funcs/icCoreMicroWin32Funcs.h"
    #elif defined(IC_OS_UNIX_LIKE)
        #include"../Unix/Funcs/icCoreMicroUnixFuncs.h"
    #endif