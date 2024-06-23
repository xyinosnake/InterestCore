 
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"
#include"../../Common/Types/icCoreCommonTypes.h"
#include"../../Common/icCoreHeaders.h"
#include"../Enums/icCoreFileEnums.h"

ic_info("decs:")
    #define                       icCreateFile   icCreateFileN
    ic_core_dcl ic_file_h ic_call icCreateFileN(cnch_p fName, ic_file_e e) ic_noexc;
    ic_core_dcl ic_file_h ic_call icCreateFileW(cwch_p fName, ic_file_e e) ic_noexc;
    ic_core_dcl bool      ic_call icDestroyFile(ic_file_h hFile) ic_noexc;
    ic_core_dcl bool      ic_call icWriteFile(ic_file_h hFile, cvoid_p pData, size_t btSz) ic_noexc;
    ic_core_dcl bool      ic_call icReadFile(ic_file_h hFile, void_p pData, size_t btSz) ic_noexc;
    ic_core_dcl uint64_t  ic_call icSizeOfFile(ic_file_h hFile) ic_noexc;
    ic_core_dcl uint64_t  ic_call icGetFilePos(ic_file_h hFile) ic_noexc;
    ic_core_dcl bool      ic_call icSetFilePos(ic_file_h hFile, uint64_t uBtPos) ic_noexc;
    ic_core_dcl bool      ic_call icFlushFile(ic_file_h hFile) ic_noexc;
    ic_core_dcl bool      ic_call icSaveFileN(cnch_p fName, cvoid_p pData, size_t btSz) ic_noexc;
    ic_core_dcl bool      ic_call icSaveFileW(cwch_p fName, cvoid_p pData, size_t btSz) ic_noexc;