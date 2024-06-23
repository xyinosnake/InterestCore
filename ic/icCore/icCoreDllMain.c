
#ifndef IC_CORE_DLL_MAIN
#define IC_CORE_DLL_MAIN

#include"./icCore.h"

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD   dwReasonForCall,
    LPVOID  lpReserved
) ic_noexc {
    switch (dwReasonForCall) {
    case DLL_PROCESS_ATTACH:
        // ic_if_return(!icCoreInit(ic_itf_default_v), FALSE);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        // ic_if_return(!icCoreUninit(), FALSE);
        break;
    }
    return TRUE;
}

#endif