
#pragma once

#include"./Common/Macros/icCoreCommonMacros.h"

#if defined(IC_OS_WINDOWS) && !defined(IC_CE_GNUC)
    #if defined(IC_CORE_IMPORT)
        #pragma comment(lib, "icCore.lib")
    #elif defined(IC_CORE_STATIC_IMPORT)
        #pragma comment(lib, "icCore-Static.lib")
    #endif
#endif