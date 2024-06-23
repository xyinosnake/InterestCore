
#pragma once

#include"../../../Common/Macros/icCoreCommonMacros.h"

ic_info("headers")
    #include"../icCoreMicroWin32Headers.h"
    #include"../../../Common/Types/icCoreCommonTypes.h"
    #include"../../../Common/Enums/icCoreCommonEnums.h"
    #include"../../../FileMapping/Enums/icFileMappingEnums.h"
    #include"../../../Stream/Enums/icCoreStreamEnmus.h"
    #include"../../../Geometry/icCoreGeometry.h"

ic_info("inl decs")
    ic_inl ptrdiff_t ic_call icMicroWin32LockedInc(volatile ptrdiff_t* pI) ic_noexc;
    ic_inl ptrdiff_t ic_call icMicroWin32LockedDec(volatile ptrdiff_t* pI) ic_noexc;

ic_info("decs")
    ic_core_dcl void       ic_call icMicroWin32Yell(cch8_p Msg, cch8_p FuncName, cch8_p FileName, cch8_p moduleName, int LineNumber) ic_noexc;
    ic_core_dcl BOOL       ic_call icMicroWin32CoreEnable (ic_init_flags_e flags) ic_noexc;
    ic_core_dcl BOOL       ic_call icMicroWin32CoreDisable(ic_init_flags_e flags) ic_noexc;
    ic_core_dcl BOOL       ic_call icMicroWin32SetCIOCP(UINT  iCP,  UINT  oCP) ic_noexc;
    ic_core_dcl void       ic_call icMicroWin32GetCIOCP(UINT* pICP, UINT* pOCP) ic_noexc;
    ic_core_dcl BOOL       ic_call icMicroWin32EnableCColor(BOOL bEnable, DWORD* pOldMode) ic_noexcept;
    ic_core_dcl size_t     ic_call icMicroWin32AToW(WCHAR* dst, const CHAR*  strAString, size_t length, UINT codePage) ic_noexc;
    ic_core_dcl size_t     ic_call icMicroWin32WToA(CHAR*  dst, const WCHAR* strWString, size_t length, UINT codePage) ic_noexc;
    ic_core_dcl PWSTR      ic_call icMicroWin32CreateWFromA(size_t* pDstLen, PCSTR  strAString, size_t length, BOOL b0Term, UINT codePage, ic_alloc_f fAlloc) ic_noexc;
    ic_core_dcl PSTR       ic_call icMicroWin32CreateAFromW(size_t* pDstLen, PCWSTR strWString, size_t length, BOOL b0Term, UINT codePage, ic_alloc_f fAlloc) ic_noexc;
    ic_core_dcl void       ic_call icMicroWin32Assert(bool b, cch8_p condStr, cch8_p msg, cch8_p funcName, cch8_p moduleName, cch8_p fileName, size_t lineNum, cch8_p timeStamp) ic_noexc;
    ic_core_dcl size_t     ic_call icMicroWin32GetThreadMaxCount() ic_noexc;
    ic_core_dcl IC_CXY_U32 ic_call icMicroWin32GetScreenCxy() ic_noexc;
    ic_core_dcl bool       ic_call icMicroWin32WriteClipboardW(PCWSTR bg, size_t sz) ic_noexc;
    ic_core_dcl bool       ic_call icMicroWin32WriteClipboardA(PCSTR  bg, size_t sz) ic_noexc;
    ic_core_dcl HANDLE     ic_call icMicroWin32CreateFileW(PCWSTR fName, ic_file_e e) ic_noexc;
    ic_core_dcl HANDLE     ic_call icMicroWin32CreateFileA(PCSTR  fName, ic_file_e e) ic_noexc;
    ic_core_dcl HANDLE     ic_call icMicroWin32CreateFileN(PCSTR  fName, ic_file_e e) ic_noexc;
    ic_core_dcl void_p     ic_call icMicroWin32MapFileW(PCWSTR fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc;
    ic_core_dcl void_p     ic_call icMicroWin32MapFileA(PCSTR  fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc;
    ic_core_dcl void_p     ic_call icMicroWin32MapFileN(PCSTR  fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc;
    ic_core_dcl BOOL       ic_call icMicroWin32InitPerformanceFrequency() ic_noexc;
    ic_core_dcl UINT64     ic_call icMicroWin32BeginPerformanceTest(uint64_t u64Count) ic_noexc;
    ic_core_dcl flo64_t    ic_call icMicroWin32EndPerformanceTest() ic_noexc;

ic_info("inl defs")
    #include"./P_icCoreMicroWin32FuncsInl.h"