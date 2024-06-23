
#pragma once

#include"../../../Common/Macros/icCoreCommonMacros.h"
#include"../../../Common/Types/icCoreCommonTypes.h"
#include"../../../Common/Enums/icCoreCommonEnums.h"

ic_info("headers")
    #include"../../../Common/Types/icCoreCommonTypes.h"
    #include"../../../Common/icCoreHeaders.h"
    #include"../../../Geometry/icCoreGeometry.h"
    #include"../../../FileMapping/Enums/icFileMappingEnums.h"
    #include"../icCoreMicroUnixHeaders.h"

ic_info("inl decs")
    ic_inl ptrdiff_t ic_call icMicroUnixLockedInc(volatile ptrdiff_t* pI) ic_noexc;
    ic_inl ptrdiff_t ic_call icMicroUnixLockedDec(volatile ptrdiff_t* pI) ic_noexc;

ic_info("decs")
    ic_core_dcl void       ic_call icMicroUnixYell(cch8_p Msg, cch8_p FuncName, cch8_p FileName, cch8_p moduleName, int LineNumber) ic_noexc;
    ic_core_dcl void       ic_call icMicroUnixAssert(bool b, cch8_p condStr, cch8_p msg, cch8_p funcName, cch8_p moduleName, cch8_p fileName, size_t lineNum, cch8_p timeStamp) ic_noexc;
    ic_core_dcl size_t     ic_call icMicroUnixGetThreadMaxCount() ic_noexc;
    ic_core_dcl size_t     ic_call icMicroUnixGetCPUCoreCount() ic_noexc;
    ic_core_dcl IC_CXY_U32 ic_call icMicroUnixGetScreenCxy() ic_noexc;
    ic_core_dcl wch_p      ic_call icMicroUnixCreateWFromN(size_t* pDstLen, cnch_p strAString, size_t length, bool b0Term, ic_alloc_f fAlloc) ic_noexc;
    ic_core_dcl nch_p      ic_call icMicroUnixCreateNFromW(size_t* pDstLen, cwch_p strWString, size_t length, bool b0Term, ic_alloc_f fAlloc) ic_noexc;
    ic_core_dcl void_p     ic_call icMicroUnixMapFileN(cnch_p fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc;
    ic_core_dcl void_p     ic_call icMicroUnixMapFileW(cwch_p fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc;
    ic_core_dcl uint64_t   ic_call icMicroUnixBeginPerformanceTest(uint64_t u64Count) ic_noexc;

ic_info("inl defs")
    #include"./P_icCoreMicroUnixFuncsInl.h"