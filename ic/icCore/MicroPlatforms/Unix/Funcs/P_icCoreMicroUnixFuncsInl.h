
#pragma once

#include"../../../Common/Macros/icCoreCommonMacros.h"

ic_info("headers")
    #include"./icCoreMicroUnixFuncs.h"

ic_info("inl defs")
    ic_inl ptrdiff_t ic_call icMicroUnixLockedInc(volatile ptrdiff_t* pI) ic_noexc {
        return __sync_add_and_fetch(pI, 1);
    }

    ic_inl ptrdiff_t ic_call icMicroUnixLockedDec(volatile ptrdiff_t* pI) ic_noexc {
        return __sync_sub_and_fetch(pI, 1);
    }
