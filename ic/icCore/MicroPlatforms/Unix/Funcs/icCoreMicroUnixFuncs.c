
#ifndef IC_CORE_MICRO_UNIX_FUNCS
#define IC_CORE_MICRO_UNIX_FUNCS

#include"./icCoreMicroUnixFuncs.h"
#include"../../../Common/Funcs/icCoreCommonFuncs.h"
#include"../../../Memory/Funcs/icCoreMemoryFuncs.h"
#include"../../../String/Funcs/icCoreStringFuncs.h"

ic_info("defs")
    ic_core_dcl void ic_call icMicroUnixYell(cch8_p Msg, cch8_p FuncName, cch8_p FileName, cch8_p moduleName, int LineNumber) ic_noexc {
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
        fwrite(buf, sizeof(char), u8Len, stdout);
        fflush(stdout);
    #undef IC_N_MAX
    #undef if_s
    }

    ic_core_dcl void ic_call icMicroUnixAssert(bool b, cch8_p condStr, cch8_p msg, cch8_p funcName,
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
        }
        printf("[IC动态断言]\r\n\r\n%s（y/n）：", buffer);
        fflush(stdout);
        ch8_t c = (ch8_t)tolower(getchar());
        if (c == 'y') {
            exit(3); // 标准断言assert退出值就是3。
        }
        #undef if_s
        #undef IC_N_MAX
    }

    ic_core_dcl size_t ic_call icMicroUnixGetThreadMaxCount() ic_noexc {
        return (size_t)sysconf(_SC_NPROCESSORS_ONLN); //返回包括超线程的线程总数。
    }

    ic_core_dcl size_t ic_call icMicroUnixGetCPUCoreCount() ic_noexc {
        return (size_t)sysconf(_SC_NPROCESSORS_CONF); //返回CPU核心数总数（不包括超线程）。
    }

    ic_core_dcl IC_CXY_U32 ic_call icMicroUnixGetScreenCxy() ic_noexc {
        IC_CXY_U32 cxy = {};
    #if defined(IC_OS_LINUX)
        int fd;
        struct fb_var_screeninfo screen_info;
        fd = open("/dev/fb0", O_RDWR);
        ic_if_return(fd == -1, cxy);
        ic_if_return(ioctl(fd, FBIOGET_VSCREENINFO, &screen_info) == -1, cxy);
        cxy.cx = (uint32_t)screen_info.xres;
        cxy.cy = (uint32_t)screen_info.yres;
        close(fd);
    #elif defined(IC_OS_UNIX)
        // #include <sys/fbio.h>
        // struct fbgattr
        /*
            #include<sys/sysctl.h>
            #include<sys/types.h>
            #include<stdio.h>

            int icGetScreenCxy(int *width, int *height) {
                struct video_info info;
                size_t info_size = sizeof(info);
                int mib[] = {CTL_HW, HW_VIDEO};

                if (sysctl(mib, 2, &info, &info_size, NULL, 0) < 0) {
                    perror("sysctl");
                    return -1;
                }

                if (width) *width = info.vi_width;
                if (height) *height = info.vi_height;

                return 0;
            }
        */
    #endif
        return cxy;
    }

    ic_core_dcl wch_p ic_call icMicroUnixCreateWFromN(size_t* pDstLen, cnch_p strAString, size_t length, bool b0Term, ic_alloc_f fAlloc) ic_noexc {
        size_t lenNeed = mbstowcs(NULL, strAString, length);
        ic_if_do(b0Term, ++lenNeed);
        wch_p ptr = (wch_p)fAlloc(sizeof(wch_t) * lenNeed);
        ic_if_do_x3(ptr, 
            lenNeed = mbstowcs(ptr, strAString, length),
            ic_if_do(pDstLen, *pDstLen = lenNeed),
            ic_if_do(b0Term, ptr[lenNeed] = (wch_t)'\0'));
        return ptr;
    }

    ic_core_dcl nch_p ic_call icMicroUnixCreateNFromW(size_t* pDstLen, cwch_p strWString, size_t length, bool b0Term, ic_alloc_f fAlloc) ic_noexc {
        size_t lenNeed = wcstombs(NULL, strWString, length);
        ic_if_do(b0Term, ++lenNeed);
        nch_p ptr = (nch_p)fAlloc(sizeof(nch_t) * lenNeed);
        ic_if_do_x3(ptr, 
            lenNeed = wcstombs(ptr, strWString, length),
            ic_if_do(pDstLen, *pDstLen = lenNeed),
            ic_if_do(b0Term, ptr[lenNeed] = (nch_t)'\0'));
        return ptr;
    }

    ic_hide int g_icMicroUnix_FM_iFileModeVals[] = { O_RDONLY,    O_RDWR | O_CREAT,       O_RDWR | O_CREAT       };
    ic_hide int g_icMicroUnix_FM_iProtVals    [] = { PROT_READ,   PROT_READ | PROT_WRITE, PROT_READ | PROT_WRITE };
    ic_hide int g_icMicroUnix_FM_iMapModeVals [] = { MAP_PRIVATE, MAP_SHARED,             MAP_SHARED             };
    ic_core_dcl void_p ic_call icMicroUnixMapFileN(cnch_p fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc {
        mode_t fmode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; //| S_IXUSR | S_IXGRP | S_IXOTH （RWX读写执行）
        int    fd    = open(fName, g_icMicroUnix_FM_iFileModeVals[fmMode], fmode);
        ic_if_return(fd == -1, NULL);
        struct stat   statbuf;
               size_t fbtsz;
        switch (fmMode) {
        case ic_fmm_read_v:
        icReadPos:
            fstat(fd, &statbuf);
            fbtsz = statbuf.st_size;
            break;
        case ic_fmm_read_write_v:
            if(uModeBtSz) {
                fbtsz = uModeBtSz;
        #ifdef IC_OS_LINUX
                extern int ftruncate(int, __off_t) __THROW __wur;
        #endif
                ic_if_goto(ftruncate(fd, fbtsz) == -1, icDefPos);
            } ic_else_goto(icReadPos)
            break;        
        case ic_fmm_append_v:
            fstat(fd, &statbuf);
            fbtsz = statbuf.st_size;
            ic_if_do(pBtSzAppendPosition, *pBtSzAppendPosition = fbtsz)
            fbtsz += uModeBtSz;
            break;
        default: icDefPos:
            close(fd);
            return NULL;
        }
        ic_if_do_and_return(!fbtsz, close(fd), NULL) // 对于POSIX，创建长度为0的内存映射会返回不可用的非空指针。因此这里需要作特殊处理。
        void_p data = mmap(NULL, fbtsz, g_icMicroUnix_FM_iProtVals[fmMode], g_icMicroUnix_FM_iMapModeVals[fmMode], fd, 0);
        close(fd);
        ic_if_return(data == MAP_FAILED, NULL);
        *pBtSzMapped = fbtsz;
        return data;
    }

    ic_core_dcl void_p ic_call icMicroUnixMapFileW(cwch_p fName, ic_file_mapping_mode_e fmMode, size_t uModeBtSz, size_t* pBtSzMapped, size_t* pBtSzAppendPosition) ic_noexc {
        cnch_p ptr = icMicroUnixCreateNFromW(NULL, fName, icStrLenW(fName), true, icPosixAlloc);
        ic_if_return(!ptr, NULL);
        void_p pMem = icMicroUnixMapFileN(ptr, fmMode, uModeBtSz, pBtSzMapped, pBtSzAppendPosition);
        icPosixDealloc((void_p)ptr);
        return pMem;
    }

    ic_thread_own uint64_t g_icMicroUnixPerformanceStartTime;
    ic_core_dcl uint64_t ic_call icMicroUnixBeginPerformanceTest(uint64_t u64Count) ic_noexc {
        g_icMicroUnixPerformanceStartTime = clock(); //In milliseconds.
        return u64Count;
    }

    ic_core_dcl flo64_t ic_call icMicroUnixEndPerformanceTest() ic_noexc {
        clock_t stop_time  = clock(); //精度较低，仅毫秒级。
        clock_t start_time = g_icMicroUnixPerformanceStartTime;
        return (flo64_t)(stop_time - start_time) / (flo64_t)CLOCKS_PER_SEC; //In seconds.
    }
#endif