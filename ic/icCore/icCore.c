#ifndef IC_CORE_C
#define IC_CORE_C

#include"./icCore.h"

ic_info("*.c")
    #include"./MicroPlatforms/Funcs/icCoreMicroPlatformsFuncs.c"
    #include"./Common/Funcs/icCoreCommonFuncs.c"
    #include"./Memory/Funcs/icCoreMemoryFuncs.c"
    #include"./Algorithm/Funcs/icCoreAlgorithmFuncs.c"
    #include"./String/Funcs/icCoreStringFuncs.c"
    #include"./Math/Funcs/icCoreMathFuncs.c"
    #include"./Geometry/Funcs/icCoreGeometryFuncs.c"
    #include"./System/Funcs/icCoreSystemFuncs.c"
    #include"./Stream/Funcs/icCoreStreamFuncs.c"
    #include"./File/Funcs/icCoreFileFuncs.c"
    #include"./FileMapping/Funcs/icFileMappingFuncs.c"
    #include"./Console/Funcs/icCoreConsoleFuncs.c"
    #include"./Time/Funcs/icCoreTimeFuncs.c"
    #include"./Thread/Funcs/icCoreThreadFuncs.c"
    #include"./Wave/Funcs/icCoreWaveFuncs.c"

#endif