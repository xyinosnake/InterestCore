
#pragma once

#include"../../Common/icCoreHeaders.h"
#include"../../Common/Macros/icCoreCommonMacros.h"
#include"../../Common/Types/icCoreCommonTypes.h"
#include"../Enums/icFileMappingEnums.h"

ic_info("file mapping")
    ic_core_dcl void_p ic_call icMapFileN(cnch_p fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc;
    ic_core_dcl void_p ic_call icMapFileW(cwch_p fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc;
    ic_core_dcl bool   ic_call icUnmapFile(void_p pMem, size_t btSzMapped) ic_noexc;
    ic_core_dcl int8_t ic_call icSameFileMemW(cwch_p fNameA, cwch_p fNameB) ic_noexc;
    ic_core_dcl int8_t ic_call icSameFileMemN(cnch_p fNameA, cnch_p fNameB) ic_noexc;
    ic_core_dcl bool   ic_call icMemToFileW(cwch_p fName, cvoid_p pMem, size_t btSz) ic_noexc;
    ic_core_dcl bool   ic_call icMemToFileN(cnch_p fName, cvoid_p pMem, size_t btSz) ic_noexc;
    #define                    icSaveFileMappingW icMemToFileW
    #define                    icSaveFileMappingN icMemToFileN