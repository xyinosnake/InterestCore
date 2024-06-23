
#include"./C/icct.h"

#if defined(IC_OS_WINDOWS)
    #define HELP \
        "#用法：ddep (fileName.exe || fileName.dll)\r\n" \
        "#功能：输出动态链接库文件的依赖项。\r\n" \
        "#原理：将输入参数转化为“dumpbin /dependents fileName.exe”的形式。\r\n"
    #define FM "echo. && dumpbin /dependents %s | rg --color=never --multiline -e \".*\\.dll\" && echo."
#else
    #define HELP \
        "#用法：ddep (fileName || fileName.so)\r\n" \
        "#功能：输出动态链接库文件的依赖项。\r\n" \
        "#原理：将输入参数转化为“objdump -x fileName.so | grep \"NEEDED\"”的形式。\r\n"
    #define FM "objdump -x %s | grep \"NEEDED\""
#endif

ic_def_main(argv, argc) {
    icCoreInit(ic_itf_core_default_v);
    ic_if_return(!icctCheckHelp(argv, argc, HELP), 0);
#define MAX_N 1024
    nch_t buf[MAX_N];
    nch_p cmd = icSNPrintfBufferedAllocN(buf, MAX_N, icPosixAlloc, NULL, FM, argv[1]);
    ic_if_do_and_return(!cmd, printf("%s", "#错误：内存不足！\r\n"), -1);
    system(cmd);
    ic_if_do(cmd != buf, icPosixDealloc(cmd));
#undef MAX_N
    icCoreUninit();
    return 0;
}
