
#ifndef IC_CORE_FILE_MAPPING_FUNCS
#define IC_CORE_FILE_MAPPING_FUNCS

#include"./icFileMappingFuncs.h"
#include"../../Memory/Funcs/icCoreMemoryFuncs.h"
#include"../../MicroPlatforms/Funcs/icCoreMicroPlatformsFuncs.h"

ic_info("file mapping")
    ic_core_dcl void_p ic_call icMapFileN(cnch_p fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return icMicroWin32MapFileN(fName, fmMode, uModeBtSz, pBtSzMapped, pBtSzAppendPosition);
    #elif defined(IC_OS_UNIX_LIKE)
        return icMicroUnixMapFileN(fName, fmMode, uModeBtSz, pBtSzMapped, pBtSzAppendPosition);
    #else
        return NULL;
    #endif    
    }

    ic_core_dcl void_p ic_call icMapFileW(cwch_p fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return icMicroWin32MapFileW(fName, fmMode, uModeBtSz, pBtSzMapped, pBtSzAppendPosition);
    #elif defined(IC_OS_UNIX_LIKE)
        return NULL;
    #else
        return NULL;
    #endif
    }

    ic_core_dcl bool ic_call icUnmapFile(void_p pMem, size_t btSzMapped) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return UnmapViewOfFile(pMem) == TRUE;
    #elif defined(IC_OS_UNIX_LIKE)
        //ic_if_return(msync(pMem, btSzMapped, MS_SYNC) == -1, false); 无需显示调用（Since Linux 2.6.19）
        return munmap(pMem, btSzMapped) != -1;
    #else
        return false;
    #endif
    }

    ic_hide int8_t ic_call H_icSameFileMem(void_p pMemA, size_t btSzA, void_p pMemB, size_t btSzB) ic_noexc {
        int8_t b;
        ic_if_do_and_goto(!pMemA || !pMemA, b = -1, pos_End);
        b = icSameMemSize(pMemA, btSzA, pMemB, btSzB);
    pos_End:
        ic_if_do(pMemA, icUnmapFile(pMemA, btSzA));
        ic_if_do(pMemB, icUnmapFile(pMemB, btSzB));
        return b;
    }

    ic_core_dcl int8_t ic_call icSameFileMemW(cwch_p fNameA, cwch_p fNameB) ic_noexc {
        ic_stv_x2(size_t, btSzA, btSzB);
        void_p pMemA = icMapFileW(fNameA, ic_fmm_read_v, 0, &btSzA, NULL);
        void_p pMemB = icMapFileW(fNameB, ic_fmm_read_v, 0, &btSzB, NULL);
        return H_icSameFileMem(pMemA, btSzA, pMemB, btSzB);
    }

    ic_core_dcl int8_t ic_call icSameFileMemN(cnch_p fNameA, cnch_p fNameB) ic_noexc {
        ic_stv_x2(size_t, btSzA, btSzB);
        void_p pMemA = icMapFileN(fNameA, ic_fmm_read_v, 0, &btSzA, NULL);
        void_p pMemB = icMapFileN(fNameB, ic_fmm_read_v, 0, &btSzB, NULL);
        return H_icSameFileMem(pMemA, btSzA, pMemB, btSzB);
    }

    ic_core_dcl bool ic_call icMemToFileW(cwch_p fName, cvoid_p pMem, size_t btSz) ic_noexc {
        size_t fBtSz;
        void_p pMemOfFile = icMapFileW(fName, ic_fmm_read_write_v, btSz, &fBtSz, NULL);
        ic_if_return(!pMemOfFile, false);
        icCopyMemSizeNoRet(pMemOfFile, pMem, btSz);
        icUnmapFile(pMemOfFile, fBtSz);
        return true;
    }

    ic_core_dcl bool ic_call icMemToFileN(cnch_p fName, cvoid_p pMem, size_t btSz) ic_noexc {
        size_t fBtSz;
        void_p pMemOfFile = icMapFileN(fName, ic_fmm_read_write_v, btSz, &fBtSz, NULL);
        ic_if_return(!pMemOfFile, false);
        icCopyMemSizeNoRet(pMemOfFile, pMem, btSz);
        icUnmapFile(pMemOfFile, fBtSz);
        return true;
    }
#endif