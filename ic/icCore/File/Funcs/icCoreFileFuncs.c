
#ifndef IC_CORE_FILE_FUNCS
#define IC_CORE_FILE_FUNCS

#include"./icCoreFileFuncs.h"
#include"../../Stream/Funcs/icCoreStreamFuncs.h"
#include"../../Stream/Macros/icCoreStreamMacros.h"
#include"../../MicroPlatforms/Funcs/icCoreMicroPlatformsFuncs.h"

ic_info("defs")
    ic_core_dcl ic_file_h ic_call icCreateFileN(cnch_p fName, ic_file_e e) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return (ic_file_h)icMicroWin32CreateFileN((PCSTR)fName, e);
    #else
        return icCreateStreamN(fName, e);
    #endif
    }

    ic_core_dcl ic_file_h ic_call icCreateFileW(cwch_p fName, ic_file_e e) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return (ic_file_h)icMicroWin32CreateFileW((PCWSTR)fName, e);
    #else
        return icCreateStreamW(fName, e);
    #endif
    }

    ic_core_dcl bool ic_call icDestroyFile(ic_file_h hFile) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return CloseHandle((HANDLE)hFile) == TRUE;
    #else
        return icDestroyStream((ic_stream_h)hFile);
    #endif
    }

    ic_core_dcl bool ic_call icWriteFile(ic_file_h hFile, cvoid_p pData, size_t btSz) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        ic_if_return(btSz > (size_t)0xFFFFFFFF, false);
        ic_stv_x2(DWORD, dwBtCount, dwbtSz = (DWORD)btSz);
        ic_if_return(WriteFile((HANDLE)hFile, pData, dwbtSz, &dwBtCount, NULL) == FALSE, false);
        return dwBtCount == btSz;
    #else
        return icWriteStream((ic_stream_h)hFile, pData, btSz);
    #endif
    }

    ic_core_dcl bool ic_call icReadFile(ic_file_h hFile, void_p pData, size_t btSz) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        ic_if_return(btSz > (size_t)0xFFFFFFFF, false);
        ic_stv_x2(DWORD, dwBtCount, dwbtSz = (DWORD)btSz);
        ic_if_return(ReadFile((HANDLE)hFile, pData, dwbtSz, &dwBtCount, NULL) == FALSE, false);
        return dwBtCount == btSz;
    #else
        return icReadStream((ic_stream_h)hFile, pData, btSz);
    #endif
    }

    ic_core_dcl uint64_t ic_call icSizeOfFile(ic_file_h hFile) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        uint64_t fileBtSz;
        BOOL     b = GetFileSizeEx(hFile, (PLARGE_INTEGER)&fileBtSz);
        return b ? fileBtSz : -1;
    #else
        return icSizeOfFile((ic_stream_h)hFile);
    #endif
    }

    ic_core_dcl uint64_t ic_call icGetFilePos(ic_file_h hFile) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        uint64_t      nPos;
        LARGE_INTEGER L0; L0.QuadPart = 0;
        BOOL b = SetFilePointerEx((FILE*)hFile, L0, (PLARGE_INTEGER)&nPos, FILE_CURRENT);
        return b ? nPos : -1;
    #else
        return icGetStreamPos((ic_stream_h)hFile);
    #endif
    }

    ic_core_dcl bool ic_call icSetFilePos(ic_file_h hFile, uint64_t uBtPos) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return TRUE == SetFilePointerEx((FILE*)hFile, *(PLARGE_INTEGER)&uBtPos, NULL, FILE_CURRENT);
    #else
        return icSetStreamPos((ic_stream_h)hFile, uBtPos);
    #endif
    }

    ic_core_dcl bool ic_call icFlushFile(ic_file_h hFile) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return FlushFileBuffers((HANDLE)hFile) == TRUE;
    #else
        return icFlushStream((ic_stream_h)hFile);
    #endif
    }

    ic_core_dcl bool ic_call icSaveFileN(cnch_p fName, cvoid_p pData, size_t btSz) ic_noexc {
        ic_file_h hFile = icCreateFileN(fName, (ic_file_e)ic_fm_write_v);
        ic_if_return(!hFile, false);
        ic_if_return(!icWriteFile(hFile, pData, btSz), false);
        return icDestroyFile(hFile);
    }

    ic_core_dcl bool ic_call icSaveFileW(cwch_p fName, cvoid_p pData, size_t btSz) ic_noexc {
        ic_file_h hFile = icCreateFileW(fName, (ic_file_e)ic_fm_write_v);
        ic_if_return(!hFile, false);
        ic_if_return(!icWriteFile(hFile, pData, btSz), false);
        return icDestroyFile(hFile);
    }
#endif