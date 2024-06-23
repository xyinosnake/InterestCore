#ifndef IC_WIN32_ICON_FUNCS
#define IC_WIN32_ICON_FUNCS

#include"./icWin32IconFuncs.h"

/*
说明：
    快捷方式：
        %SystemRoot%/System32/imageres.dll, 154
    文件夹：
        %SystemRoot%/System32/SHELL32.dll,	3
    默认EXE：
        %SystemRoot%/System32/imageres.dll, 11
*/

ic_info("definitions")
    #define icWin32ExtractIcon_m(SHDefExtractIcon_xf) \
        HICON hIcon; \
        ic_if_else_return(SHDefExtractIcon_xf(pszPath, iIndex, 0, &hIcon, NULL, size) == S_OK, \
            hIcon, NULL)

    ic_win32_dcl HICON ic_call icWin32ExtractIconW(LPCWSTR pszPath, int size, int iIndex) ic_noexc {
        icWin32ExtractIcon_m(SHDefExtractIconW); //从路径提取图标
    }

    ic_win32_dcl HICON ic_call icWin32ExtractIconA(LPCSTR pszPath, int size, int iIndex ic_dfv(0)) ic_noexc {
        icWin32ExtractIcon_m(SHDefExtractIconA); //从路径提取图标
    }
    #undef icWin32ExtractIcon_m

    ic_win32_dcl HICON ic_call icWin32ExtractLinkMiniIcon(int size) ic_noexc {
        return icWin32ExtractIconW(L"%SystemRoot%/System32/imageres.dll", size, 154);
    }

    ic_win32_dcl BOOL ic_call icWin32GetIconSize(HICON hIcon, SIZE* sz, INT* bitsPerPixel) ic_noexc {
        ic_stv_x3(int, nWidth = 0, nHeight = 0, nBitsPerPixel = 0); //该函数效率极端低下！
        ICONINFO info = {};
        BOOL     bRes = GetIconInfo(hIcon, &info);
        ic_if_return(!bRes, bRes);
        BITMAP   bmp  = {};
        if (info.hbmColor) {
            const int nWrittenBytes = GetObject(info.hbmColor, sizeof(bmp), &bmp);
            ic_if_do_x3(nWrittenBytes > 0, nWidth = bmp.bmWidth, nHeight = bmp.bmHeight, nBitsPerPixel = bmp.bmBitsPixel);
        } else if (info.hbmMask) { // Icon has no color plane, image data stored in mask
            const int nWrittenBytes = GetObject(info.hbmMask, sizeof(bmp), &bmp);
            ic_if_do_x3(nWrittenBytes > 0, nWidth = bmp.bmWidth, nHeight = bmp.bmHeight / 2, nBitsPerPixel = 1);
        }
        ic_if_do(info.hbmColor, DeleteObject(info.hbmColor));
        ic_if_do(info.hbmMask,  DeleteObject(info.hbmMask));
        ic_if_do_x2(sz, sz->cx = nWidth, sz->cy = nHeight);
        ic_if_do(bitsPerPixel, *bitsPerPixel = nBitsPerPixel);
        return TRUE;
    }
#endif