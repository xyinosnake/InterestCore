
#pragma once

#include"../Macros/icUnixCommonMacros.h"
#include"../../../../icCore/Common/Funcs/icCoreCommonFuncs.h"

ic_info("icCoreName & icCoreDep")
    #define icUnixName()        "icUnix"
    #define icUnixNameColored() icCmdFgClr(12, 234, 12) icUnixName() icCmdClrReset()
    #define icUnixDep()         icUnixName() "(" icCoreDep() ")"
    #define icUnixDepColored()  icUnixNameColored() icCmdFgClr(64, 255, 64) "(" icCoreDepColored() icCmdFgClr(64, 255, 64) ")" icCmdClrReset()

ic_info("declarations")
    ic_unix_dcl void ic_call icUnixHello(ic_hello_flags_e flags ic_dfv(ic_hf_default_v)) ic_noexc;