
#pragma once

#include"../../../icCore/Common/icCoreCommon.h"
#include"../Macros/icCommonMacros.h"
#include"../Enums/icCommonEnums.h"
#include"../../Platforms/icPlatforms.h"

ic_info("icName & icDep")
        #define icName()        "ic"
        #define icNameColored() icCmdFgClr(256, 256, 128) icName() icCmdFgClrReset()
    #if defined(IC_OS_WINDOWS)
        #define icDep()         icName() "(" icCoreDep() ", " icWin32Dep() ")"
        #define icDepColored()  icNameColored() icCmdFgClr(64, 255, 64) "(" icCoreDepColored() icCmdFgClr(64, 255, 64) ", " icWin32DepColored() icCmdFgClr(64, 255, 64) ")" icCmdFgClrReset()
    #elif defined(IC_OS_UNIX_LIKE)
        #define icDep()         icName() "(" icCoreDep() ", " icUnixDep() ")"
        #define icDepColored()  icNameColored() icCmdFgClr(64, 255, 64) "(" icCoreDepColored() icCmdFgClr(64, 255, 64) ", " icUnixDepColored() icCmdFgClr(64, 255, 64) ")" icCmdFgClrReset()
    #endif

ic_info("declarations")
    ic_dcl void ic_call icHello(ic_hello_flags_e flags ic_dfv(ic_hf_default_v)) ic_noexc;
    ic_dcl bool ic_call icInit(ic_init_flags_e flags ic_dfv(ic_itf_default_v)) ic_noexc;
    ic_dcl bool ic_call icUninit() ic_noexc;
    ic_dcl bool ic_call icEnable (ic_init_flags_e flags) ic_noexc;
    ic_dcl bool ic_call icDisable(ic_init_flags_e flags) ic_noexc;
    ic_dcl bool ic_call icEnableThread (ic_init_thread_flags_e flags) ic_noexc;
    ic_dcl bool ic_call icDisableThread(ic_init_thread_flags_e flags) ic_noexc;