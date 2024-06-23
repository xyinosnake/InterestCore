
#pragma once

#include"../icCore/icCore.h"

#include"./Common/icCommon.h"
#include"./Memory/icMemory.h"
#include"./Platforms/icPlatforms.h"
#include"./Intrinsics/icIntrinsics.h"

#ifdef IC_COMPILE //默认
    #include"./ic.c"
#endif

#if defined(IC_OS_WINDOWS) && defined(IC_EXPORT)
    #include"./icDllMain.c"
#endif