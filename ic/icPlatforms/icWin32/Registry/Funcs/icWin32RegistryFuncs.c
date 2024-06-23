#ifndef IC_WIN32_REGISTRY_FUNCS
#define IC_WIN32_REGISTRY_FUNCS

#include"./icWin32RegistryFuncs.h"
#include"../../String/icWin32String.h"

ic_info("definitions")
    #define icWin32RegOpenCmd_m(ch_xt, RegSetKeyValue_xf, RegCreateKeyEx_xf, icStrLen_xf, icWOrN_xf) \
        ic_init_x2(HKEY hKey, LSTATUS r); \
        r = RegSetKeyValue_xf(HKEY_CLASSES_ROOT, lpszExtName, NULL, /* 1.注册扩展名并设置默认值为文件类型 */ \
            REG_SZ, lpszFileTypeName, (DWORD)(sizeof(ch_xt) * (icStrLen_xf(lpszFileTypeName) + 1))); \
        ic_if_goto(r != ERROR_SUCCESS, Rtn); \
        r = RegCreateKeyEx_xf(HKEY_CLASSES_ROOT, lpszFileTypeName, 0, /* 2.注册文件类型 */ \
            NULL, 0, KEY_ALL_ACCESS, 0, &hKey, NULL); \
        ic_if_goto(r != ERROR_SUCCESS, Rtn); \
        r = RegSetKeyValue_xf(hKey, icWOrN_xf("shell\\open\\command"), NULL, /* 3.设置命令字符串 */ \
            REG_EXPAND_SZ, lpszCommandString, (DWORD)(sizeof(ch_xt) * (icStrLen_xf(lpszCommandString) + 1))); \
        ic_if_goto(r != ERROR_SUCCESS, Cls); \
        if (lpszIconString) { /* 4.设置默认图标 */ \
            r = RegSetKeyValue_xf(hKey, icWOrN_xf("DefaultIcon"), NULL, \
                REG_EXPAND_SZ, lpszIconString, (DWORD)(sizeof(ch_xt) * (icStrLen_xf(lpszIconString) + 1))); \
            ic_if_goto(r != ERROR_SUCCESS, Cls); \
        } \
        ic_label_do(Cls, RegCloseKey(hKey)); \
        ic_label_return(Rtn, r)
    ic_win32_dcl BOOL ic_call icWin32RegOpenCmdW(LPWSTR lpszExtName, LPWSTR lpszFileTypeName, LPWSTR lpszCommandString, LPWSTR lpszIconString) ic_noexc {
        icWin32RegOpenCmd_m(WCHAR, RegSetKeyValueW, RegCreateKeyExW, icStrLenW, icW);
    }

    ic_win32_dcl BOOL ic_call icWin32RegOpenCmdA(LPSTR lpszExtName, LPSTR lpszFileTypeName, LPSTR lpszCommandString, LPSTR lpszIconString) ic_noexc {
        icWin32RegOpenCmd_m(CHAR, RegSetKeyValueA, RegCreateKeyExA, icStrLenA, icA);
    }
    #undef icWin32RegOpenCmd_m
#endif