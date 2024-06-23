
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("headers")
    #include"../../Common/icCoreHeaders.h"
    #include"../../Common/Types/icCoreCommonTypes.h"

ic_core_dcl nch_p ic_call icSNPrintfAllocN(ic_alloc_f fAlloc, size_t* pSz, cnch_p fm, ...) ic_noexc;
ic_core_dcl wch_p ic_call icSNPrintfAllocW(ic_alloc_f fAlloc, size_t* pSz, cwch_p fm, ...) ic_noexc;
ic_core_dcl nch_p ic_call icSNPrintfBufferedAllocN(nch_p staticBuf, size_t staticCap, ic_alloc_f fAlloc, size_t* pSz, cnch_p fm, ...) ic_noexc;
ic_core_dcl wch_p ic_call icSNPrintfBufferedAllocW(wch_p staticBuf, size_t staticCap, ic_alloc_f fAlloc, size_t* pSz, cwch_p fm, ...) ic_noexc;