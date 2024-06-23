
#ifndef IC_CORE_MICRO_WIN32_FUNCS
#define IC_CORE_MICRO_WIN32_FUNCS

#include"./icCoreMicroWin32Funcs.h"
#include"../../../Common/Funcs/icCoreCommonFuncs.h"
#include"../../../Memory/Funcs/icCoreMemoryFuncs.h"
#include"../../../String/Funcs/icCoreStringFuncs.h"

ic_info("decs")
    ic_core_dcl void ic_call icMicroWin32Yell(cch8_p Msg, cch8_p FuncName, cch8_p FileName, cch8_p moduleName, int LineNumber) ic_noexc {
    #define if_s(s, sIfNull)    (s ? s : sIfNull)
    #define IC_N_MAX 1024
        char buf[IC_N_MAX];
        int u8Len = snprintf(buf, IC_N_MAX,
            "消息：%s\r\n"
            "函数：%s\r\n"
            "文件：%s\r\n"
            "模块：%s\r\n"
            "行号：%d\r\n\r\n",
            if_s(Msg, "无"),
            if_s(FuncName, "无"),
            if_s(FileName, "无"),
            if_s(moduleName, "无"),
            LineNumber
        );
        WCHAR wBuf[IC_N_MAX];
        *(wBuf + icMicroWin32AToW(wBuf, buf, u8Len, CP_UTF8)) = L'\0';
        MessageBoxA(NULL, buf, "icWin32Yell", MB_OK);
    #undef IC_N_MAX
    #undef if_s
    }

    ic_hide UINT  g_icMicroWin32ICP;
    ic_hide UINT  g_icMicroWin32OCP;
    ic_hide DWORD g_icMicroWin32OldConsoleMode;
    extern uint32_t g_icInitFlags;
    ic_core_dcl BOOL ic_call icMicroWin32CoreEnable(ic_init_flags_e flags) ic_noexc {
        BOOL     b = TRUE;
        uint32_t v;
        ic_init_if(v = ic_itf_utf8_v, icGetBit(flags, v) && !icGetBit(g_icInitFlags, v)) {
            icMicroWin32GetCIOCP(&g_icMicroWin32ICP, &g_icMicroWin32OCP);
            b = icMicroWin32SetCIOCP(CP_UTF8, CP_UTF8);
            ic_if_return(!b, b);
            icSetBits(g_icInitFlags, v);
        }
        ic_init_if(v = ic_itf_console_buffer_v, icGetBit(flags, v) && !icGetBit(g_icInitFlags, v)) {
            b = (setvbuf(stdout, NULL, _IOFBF, 256) == 0);
            ic_if_return(!b, b);
            icSetBits(g_icInitFlags, v);
        }
        ic_init_if(v = ic_itf_console_color_v, icGetBit(flags, v) && !icGetBit(g_icInitFlags, v)) {
            b = icMicroWin32EnableCColor(TRUE, &g_icMicroWin32OldConsoleMode);
            ic_if_return(!b, b);
            icSetBits(g_icInitFlags, v);
        }
        ic_init_if(v = ic_itf_time_v,  icGetBit(flags, v) && !icGetBit(g_icInitFlags, v)) {
            b = icMicroWin32InitPerformanceFrequency();
            ic_if_return(!b, b);
            icSetBits(g_icInitFlags, v);
        }
        return b;
    }

    ic_core_dcl BOOL ic_call icMicroWin32CoreDisable(ic_init_flags_e flags) ic_noexc {
        BOOL     b = TRUE;
        uint32_t v;
        ic_init_if(v = ic_itf_utf8_v, icGetBit(flags, v) && icGetBit(g_icInitFlags, v)) {
            b = icMicroWin32SetCIOCP(g_icMicroWin32ICP, g_icMicroWin32OCP);
            ic_if_return(!b, b);
            icClearBits(g_icInitFlags, v);
        }
        ic_init_if(v = ic_itf_console_buffer_v, icGetBit(flags, v) && icGetBit(g_icInitFlags, v)) {
            b = (setvbuf(stdout, NULL, _IONBF, 0) == 0);
            ic_if_return(!b, b);
            icClearBits(g_icInitFlags, v);
        }
        ic_init_if(v = ic_itf_console_color_v, icGetBit(flags, v) && icGetBit(g_icInitFlags, v)) {
            b = SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), g_icMicroWin32OldConsoleMode);
            ic_if_return(!b, b);
            icClearBits(g_icInitFlags, v);
        }
        ic_init_if(v = ic_itf_time_v, icGetBit(flags, v) && icGetBit(g_icInitFlags, v)) {
            icClearBits(g_icInitFlags, v);
        }
        return b;
    }

    ic_core_dcl BOOL ic_call icMicroWin32SetCIOCP(UINT iCP, UINT oCP) ic_noexc {
        ic_if_return(!SetConsoleCP(iCP), FALSE);
        return SetConsoleOutputCP(oCP);
    }

    ic_core_dcl void ic_call icMicroWin32GetCIOCP(UINT* pICP, UINT* pOCP) ic_noexc {
        *pICP = GetConsoleCP();
        *pOCP = GetConsoleOutputCP();
    }

    ic_core_dcl BOOL ic_call icMicroWin32EnableCColor(BOOL bEnable, DWORD* pOldMode) ic_noexcept {
        HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD  consoleMode;
        BOOL   B = GetConsoleMode(hConsoleOutput, &consoleMode);
        ic_if_return(!B, B);
        *pOldMode = consoleMode;
        icSetOrClearBits(bEnable, consoleMode, ENABLE_VIRTUAL_TERMINAL_PROCESSING);
        B = SetConsoleMode(hConsoleOutput, consoleMode);
        bool b = (B != FALSE);
        return b;
    }

    ic_core_dcl size_t ic_call icMicroWin32AToW(WCHAR* dst, const CHAR* strAString, size_t length, UINT codePage) ic_noexc {
        ic_if_return(!length, length); //MB_ERR_INVALID_CHARS在该函数虽然可用，但为了同WideCharToMultiByte形式统一，故不使用该参数。
        length = (size_t)MultiByteToWideChar(codePage, 0, strAString, (int)(length), dst, dst ? 0x7FFFFFFF : 0);
        ic_if_do(length == 0, length = -1);
        return length;
    }

    ic_core_dcl size_t ic_call icMicroWin32WToA(CHAR* dst, const WCHAR* strWString, size_t length, UINT codePage) ic_noexc {
        ic_if_return(!length, length); //CodePage是CP_UTF8或54936时，MB_ERR_INVALID_CHARS才是可用的。它不能与其他字码页搭配。
        length = (size_t)WideCharToMultiByte(codePage, 0, strWString, (int)(length), dst, dst ? 0x7FFFFFFF : 0, NULL, NULL);
        ic_if_do(length == 0, length = -1);
        return length;
    }

    ic_core_dcl PWSTR ic_call icMicroWin32CreateWFromA(size_t* pDstLen, PCSTR strAString, size_t length, BOOL b0Term, UINT codePage, ic_alloc_f fAlloc) ic_noexc {
        size_t lenNeed = icMicroWin32AToW(NULL, strAString, length, codePage);
        ic_if_do(b0Term, ++lenNeed);
        PWSTR ptr = (PWSTR)fAlloc(sizeof(WCHAR) * lenNeed);
        ic_if_do_x3(ptr, 
            lenNeed = icMicroWin32AToW(ptr, strAString, length, codePage),
            ic_if_do(pDstLen, *pDstLen = lenNeed),
            ic_if_do(b0Term, ptr[lenNeed] = (WCHAR)'\0'));
        return ptr;
    }

    ic_core_dcl PSTR ic_call icMicroWin32CreateAFromW(size_t* pDstLen, PCWSTR strWString, size_t length, BOOL b0Term, UINT codePage, ic_alloc_f fAlloc) ic_noexc {
        size_t lenNeed = icMicroWin32WToA(NULL, strWString, length, codePage);
        ic_if_do(b0Term, ++lenNeed);
        PSTR ptr = (PSTR)fAlloc(sizeof(CHAR) * lenNeed);
        ic_if_do_x3(ptr, 
            lenNeed = icMicroWin32WToA(ptr, strWString, length, codePage),
            ic_if_do(pDstLen, *pDstLen = lenNeed),
            ic_if_do(b0Term, ptr[lenNeed] = (CHAR)'\0'));
        return ptr;
    }

    ic_core_dcl void ic_call icMicroWin32Assert(bool b, cch8_p condStr, cch8_p msg, cch8_p funcName, 
        cch8_p moduleName, cch8_p fileName, size_t lineNum, cch8_p timeStamp) ic_noexc {
        // 程序触发动态断言！
        // 
        // 条件：condStr
        // 消息：msg
        // 函数：funcName
        // 模块：moduleName
        // 文件：file_name
        // 行号：line_number
        // 时戳：timeStamp
        // 
        // 要终止程序吗？
        #define if_s(s, sIfNull)    (s ? s : sIfNull)
        #define IC_N_MAX            2048
        ch8_t buffer[IC_N_MAX];
        if (!b) {
            int u8Len = snprintf((ch8_t*)buffer,
                IC_N_MAX,
                "程序触发动态断言！\r\n"
                "\r\n"
                "条件：%s\r\n"
                "消息：%s\r\n"
                "函数：%s\r\n"
                "模块：%s\r\n"
                "文件：%s\r\n"
                "行号：%u\r\n"
                "时戳：%s\r\n"
                "\r\n"
                "要终止程序吗？",
                if_s(condStr,    "无"),
                if_s(msg,        "无"),
                if_s(funcName,   "无"),
                if_s(moduleName, "无"),
                if_s(fileName,   "无"),
                (uint32_t)lineNum,
                if_s(timeStamp,  "无")
            );
            WCHAR wBuffer[IC_N_MAX];
            *(wBuffer + icMicroWin32AToW(wBuffer, buffer, u8Len, CP_UTF8)) = L'\0';
            int r = MessageBoxW(NULL, wBuffer, L"IC动态断言", MB_YESNO | MB_ICONERROR);
            ic_if_do(r == IDYES, ExitProcess(3)); // 标准断言assert退出值就是3。
        }
        #undef IC_N_MAX
        #undef if_s
    }

    ic_core_dcl size_t ic_call icMicroWin32GetThreadMaxCount() ic_noexc {
        SYSTEM_INFO info;
        GetSystemInfo(&info);
        return (size_t)info.dwNumberOfProcessors;
    }

    ic_core_dcl IC_CXY_U32 ic_call icMicroWin32GetScreenCxy() ic_noexc {
        IC_CXY_U32 cxy = {
            (uint32_t)GetSystemMetrics(SM_CXSCREEN),
            (uint32_t)GetSystemMetrics(SM_CYSCREEN)
        };  
        return cxy;
    }

    ic_core_dcl bool ic_call icMicroWin32WriteClipboardW(PCWSTR bg, size_t sz) ic_noexc {
        ic_if_return(!OpenClipboard(NULL), false);
        ic_if_do_and_return(!EmptyClipboard(), CloseClipboard(), false);
        HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, sz + 1);
        ic_if_do_and_return(!hGlobal, CloseClipboard(), false);
        wch_p lpszText = (wch_p)GlobalLock(hGlobal);
        *(wch_p)icCopyMemSize(lpszText, bg, sizeof(wch_t) * sz) = (wch_t)'\0';
        GlobalUnlock(hGlobal);
        if (!SetClipboardData(CF_UNICODETEXT, hGlobal)) {
            GlobalFree(hGlobal);
            CloseClipboard();
            return false;
        }
        ic_do_and_return(CloseClipboard(), true);
    }

    ic_core_dcl bool ic_call icMicroWin32WriteClipboardA(PCSTR bg, size_t sz) ic_noexc {
        ic_if_return(!OpenClipboard(NULL), false);
        ic_if_do_and_return(!EmptyClipboard(), CloseClipboard(), false);
        HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, sz + 1);
        ic_if_do_and_return(!hGlobal, CloseClipboard(), false);
        ach_p lpszText = (ach_p)GlobalLock(hGlobal);
        *(ach_p)icCopyMemSize(lpszText, bg, sizeof(ach_t) * sz) = (ach_t)'\0';
        GlobalUnlock(hGlobal);
        if (!SetClipboardData(CF_TEXT, hGlobal)) {
            GlobalFree(hGlobal);
            CloseClipboard();
            return false;
        }
        ic_do_and_return(CloseClipboard(), true);
    }

    #define GENERIC_RW GENERIC_READ | GENERIC_WRITE
        ic_hide const DWORD g_icMicroWin32_F_dwDesiredAccessVals      [] = { GENERIC_READ,    GENERIC_WRITE, GENERIC_RW,  GENERIC_WRITE };
        ic_hide const DWORD g_icMicroWin32_F_dwShareModeVals          [] = { FILE_SHARE_READ, 0,             0,           0             };
        ic_hide const DWORD g_icMicroWin32_F_dwCreationDispositionVals[] = { OPEN_EXISTING,   CREATE_ALWAYS, OPEN_ALWAYS, OPEN_ALWAYS   };
    ic_core_dcl HANDLE ic_call icMicroWin32CreateFileA(PCSTR fName, ic_file_e e) ic_noexc {
        ic_if_return(e > ic_fm_append_v, ic_null); // ic_fm_read_e = 0, ic_fm_write_e, ic_fm_read_write_e, ic_fm_append_e, ic_fm_overwrite_e = ic_fm_read_write_e
        HANDLE hdl = CreateFileA(fName, g_icMicroWin32_F_dwDesiredAccessVals[e], g_icMicroWin32_F_dwShareModeVals[e], NULL, 
            g_icMicroWin32_F_dwCreationDispositionVals[e], FILE_ATTRIBUTE_NORMAL, NULL);
        ic_if_return(hdl == INVALID_HANDLE_VALUE, ic_null);
        ic_if_do_x3(e == ic_fm_append_v, LARGE_INTEGER L0, L0.QuadPart = 0, SetFilePointerEx(hdl, L0, NULL, FILE_END));
        return (ic_file_h)hdl;
    }

    ic_core_dcl HANDLE ic_call icMicroWin32CreateFileW(PCWSTR fName, ic_file_e e) ic_noexc {
        ic_if_return(e > ic_fm_append_v, ic_null); // ic_fm_read_e = 0, ic_fm_write_e, ic_fm_read_write_e, ic_fm_append_e, ic_fm_overwrite_e = ic_fm_read_write_e
        HANDLE hdl = CreateFileW(fName, g_icMicroWin32_F_dwDesiredAccessVals[e], g_icMicroWin32_F_dwShareModeVals[e], NULL, 
            g_icMicroWin32_F_dwCreationDispositionVals[e], FILE_ATTRIBUTE_NORMAL, NULL);
        ic_if_return(hdl == INVALID_HANDLE_VALUE, ic_null);
        ic_if_do_x3(e == ic_fm_append_v, LARGE_INTEGER L0, L0.QuadPart = 0, SetFilePointerEx(hdl, L0, NULL, FILE_END));
        return (ic_file_h)hdl;
    }

    ic_core_dcl HANDLE ic_call icMicroWin32CreateFileN(PCSTR fName, ic_file_e e) ic_noexc {
        PCWSTR ptr = (PCWSTR)icMicroWin32CreateWFromA(NULL, fName, icStrLenN(fName), TRUE, CP_UTF8, icPosixAlloc);
        ic_if_return(!ptr, NULL);
        HANDLE hdl = icMicroWin32CreateFileW(ptr, e);
        icPosixDealloc((void_p)ptr);
        return hdl;
    }

    #define FILE_MAP_RW FILE_MAP_READ | FILE_MAP_WRITE
        ic_hide const DWORD g_icMicroWin32_FM_dwDesiredAccessVals      [] = { GENERIC_READ,    GENERIC_RW,     GENERIC_RW     };
        ic_hide const DWORD g_icMicroWin32_FM_dwShareModeVals          [] = { FILE_SHARE_READ, 0,              0              };
        ic_hide const DWORD g_icMicroWin32_FM_dwCreationDispositionVals[] = { OPEN_EXISTING,   OPEN_ALWAYS,    OPEN_ALWAYS    };
        ic_hide const DWORD g_icMicroWin32_FM_flProtectVals            [] = { PAGE_READONLY,   PAGE_READWRITE, PAGE_READWRITE };
        ic_hide const DWORD g_icMicroWin32_FM_dwFMDesiredAccessVals    [] = { FILE_MAP_READ,   FILE_MAP_RW,    FILE_MAP_RW    };
    #define icMicroWin32MapFile_m(CF_f, CFM_f) \
        ic_if_return(fmMode > ic_fmm_append_v, NULL); /* ic_fmm_read_v = 0, ic_fmm_read_write_v, ic_fmm_append_v */ \
        HANDLE hFile = CF_f(fName, g_icMicroWin32_FM_dwDesiredAccessVals[fmMode], g_icMicroWin32_FM_dwShareModeVals[fmMode], NULL, g_icMicroWin32_FM_dwCreationDispositionVals[fmMode], FILE_ATTRIBUTE_NORMAL, NULL); \
        ic_if_return(hFile == INVALID_HANDLE_VALUE, NULL); \
        LARGE_INTEGER lFileSize; \
        switch (fmMode) { \
        case ic_fmm_read_v: \
        icReadPos: \
            ic_if_goto(!GetFileSizeEx(hFile, &lFileSize), icDefPos); \
            break; \
        case ic_fmm_read_write_v: \
            if(uModeBtSz) { \
                lFileSize.QuadPart = uModeBtSz; \
                ic_if_goto(!SetFilePointerEx(hFile, lFileSize, NULL, FILE_BEGIN), icDefPos); \
                ic_if_goto(!SetEndOfFile(hFile), icDefPos); \
            } ic_else_goto(icReadPos) \
            break; \
        case ic_fmm_append_v: \
            ic_if_goto(!GetFileSizeEx(hFile, &lFileSize), icDefPos); \
            ic_if_do(pBtSzAppendPosition, *pBtSzAppendPosition = (size_t)lFileSize.QuadPart) \
            lFileSize.QuadPart += (LONGLONG)uModeBtSz; \
            break; \
        default: icDefPos: \
            CloseHandle(hFile); \
            return NULL; \
        } \
        ic_if_do(pBtSzMapped, *pBtSzMapped = (size_t)lFileSize.QuadPart); /* 对于Win32 API，创建长度为0的内存映射会返回空指针。因此这里不需要作特殊处理。*/ \
        HANDLE hFileMapping = CFM_f(hFile, NULL, g_icMicroWin32_FM_flProtectVals[fmMode], lFileSize.HighPart, lFileSize.LowPart, NULL); \
        CloseHandle(hFile); \
        if (hFileMapping) { \
            void_p pMem = MapViewOfFile(hFileMapping, g_icMicroWin32_FM_dwFMDesiredAccessVals[fmMode], 0, 0, 0); \
            CloseHandle(hFileMapping); \
            return pMem; \
        } ic_else_return(NULL)

    ic_core_dcl void_p ic_call icMicroWin32MapFileW(PCWSTR fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc {
        icMicroWin32MapFile_m(CreateFileW, CreateFileMappingW);
    }

    ic_core_dcl void_p ic_call icMicroWin32MapFileA(PCSTR fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc {
        icMicroWin32MapFile_m(CreateFileA, CreateFileMappingA);
    }

    ic_core_dcl void_p ic_call icMicroWin32MapFileN(PCSTR fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc {
        PCWSTR ptr = (PCWSTR)icMicroWin32CreateWFromA(NULL, fName, icStrLenN(fName), TRUE, CP_UTF8, icPosixAlloc);
        ic_if_return(!ptr, NULL);
        void_p pMem = icMicroWin32MapFileW(ptr, fmMode, uModeBtSz, pBtSzMapped, pBtSzAppendPosition);
        icPosixDealloc((void_p)ptr);
        return pMem;
    }
    #undef FILE_MAP_RW
    #undef GENERIC_RW

    ic_hide UINT64 g_icMicroWin32PerformanceFrequency;
    ic_core_dcl BOOL ic_call icMicroWin32InitPerformanceFrequency() ic_noexc {
        return QueryPerformanceFrequency((LARGE_INTEGER*)&g_icMicroWin32PerformanceFrequency);
    }

    ic_hide ic_thread_own UINT64 g_icMicroWin32PerformanceStartFrame;
    ic_core_dcl UINT64 ic_call icMicroWin32BeginPerformanceTest(uint64_t u64Count) ic_noexc {
        QueryPerformanceCounter((LARGE_INTEGER*)&g_icMicroWin32PerformanceStartFrame);
        return u64Count;
    }

    ic_core_dcl flo64_t ic_call icMicroWin32EndPerformanceTest() ic_noexc {
        UINT64 stop_frame;
        QueryPerformanceCounter((LARGE_INTEGER*)&stop_frame);
        UINT64 start_frame = g_icMicroWin32PerformanceStartFrame;
        UINT64 frequency   = g_icMicroWin32PerformanceFrequency;
        return (flo64_t)(stop_frame - start_frame) / (flo64_t)frequency; //In seconds.
    }
#endif