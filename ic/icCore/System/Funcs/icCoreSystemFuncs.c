#ifndef IC_CORE_SYSTEM_FUNCS
#define IC_CORE_SYSTEM_FUNCS

#include"./icCoreSystemFuncs.h"
#include"../../MicroPlatforms/icCoreMicroPlatforms.h"

ic_info("...")
ic_core_dcl size_t ic_call icGetThreadMaxCount() ic_noexc { //返回包括超线程的线程总数。
#if defined(IC_OS_WINDOWS)
    return icMicroWin32GetThreadMaxCount();
#elif defined(IC_OS_UNIX_LIKE)
    return icMicroUnixGetThreadMaxCount();
#else
    return 0; //对于不能推导的情况，按0处理。
#endif
}

ic_core_dcl size_t ic_call icGetCPUCoreCount() ic_noexc { //返回CPU核心数总数（不包括超线程）。
#if defined(IC_OS_UNIX_LIKE)
    return icMicroUnixGetCPUCoreCount(); 
#else //在Windows下，无法真正查找核心数，只能查找线程数。
    return 0; //对于所有不能推导的情况，按0处理。
#endif
}

ic_core_dcl IC_CXY_U32 ic_call icGetScreenCxy() ic_noexc {
#if defined(IC_OS_WINDOWS)
	return icMicroWin32GetScreenCxy();
#elif defined(IC_OS_LINUX)
    return icMicroUnixGetScreenCxy();
#else
    IC_CXY_U32 cxy = {};
    return cxy;
#endif
}

ic_core_dcl bool ic_call icRunW(const wch_t* sCmd) ic_noexc {
#ifdef IC_OS_WINDOWS
    return -1 != _wsystem(sCmd);
#else
    return false;
#endif
}

ic_core_dcl bool ic_call icRunN(const nch_t* sCmd) ic_noexc {
    return -1 != system(sCmd);
}

ic_core_dcl bool ic_call icWriteClipboardN(cnch_p bg, size_t sz) ic_noexc {
    return false;
}

ic_core_dcl bool ic_call icWriteClipboardW(cwch_p bg, size_t sz) ic_noexc {
#ifdef IC_OS_WINDOWS
    return icMicroWin32WriteClipboardW(bg, sz);
#else
    return false;
#endif
}
#endif
