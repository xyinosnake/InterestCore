
#pragma once

#include"./Common/Macros/icInfo.h"

ic_info("headers")
    #include"./MicroPlatforms/icCoreMicroPlatforms.h"
    #include"./Common/icCoreCommon.h"
    #include"./Memory/icCoreMemory.h"
    #include"./String/icCoreString.h"
    #include"./Math/icCoreMath.h"
    #include"./Geometry/icCoreGeometry.h"
    #include"./Algorithm/icCoreAlgorithm.h"
    #include"./System/icCoreSystem.h"
    #include"./Stream/icCoreStream.h"
    #include"./File/icCoreFile.h"
    #include"./FileMapping/icFileMapping.h"
    #include"./Console/icCoreConsole.h"
    #include"./Time/icCoreTime.h"
    #include"./Thread/icCoreThread.h"
    #include"./Wave/icCoreWave.h"

ic_info("*.c")
    #ifdef IC_CORE_COMPILE //默认
        #include"./icCore.c"
    #endif
    #if defined(IC_OS_WINDOWS) && defined(IC_CORE_EXPORT)
        #include"./icCoreDllMain.c"
    #endif