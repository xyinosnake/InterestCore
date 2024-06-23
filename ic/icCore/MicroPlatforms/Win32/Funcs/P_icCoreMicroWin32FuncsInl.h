
#pragma once

#include"../../../Common/Macros/icCoreCommonMacros.h"

ic_info("headers")
    #include"./icCoreMicroWin32Funcs.h"

ic_info("inl defs")
    ic_inl ptrdiff_t ic_call icMicroWin32LockedInc(volatile ptrdiff_t* pI) ic_noexc {
        return (ptrdiff_t)InterlockedIncrementSizeT((volatile LONG64*)pI);
    }

    ic_inl ptrdiff_t ic_call icMicroWin32LockedDec(volatile ptrdiff_t* pI) ic_noexc {
        return (ptrdiff_t)InterlockedDecrementSizeT((volatile LONG64*)pI);
    }