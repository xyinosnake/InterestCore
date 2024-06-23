
#ifndef IC_CORE_CONSOLE_FUNCS
#define IC_CORE_CONSOLE_FUNCS

#include"../../Common/icCoreCommon.h"
#include"../../Graphic/Structs/icCoreGraphicStructs.h"
#include"../../MicroPlatforms/icCoreMicroPlatforms.h"
#include"../../String/icCoreString.h"
#include"../../Memory/icCoreMemory.h"
#include"icCoreConsoleFuncs.h"

#ifdef IC_OS_WINDOWS
    extern uint32_t g_icInitFlags;
#endif

ic_hide size_t ic_call H_icCTCToBuf(char* buf, const char* fmIfClr, const char* fmIfResetClr, RGBA_t clr) ic_noexcept {
    if (clr) { // clr != ic_ctc_reset_v
        ic_if_do_and_return(clr != ic_ctc_hold_v, IC_32_RGBA_U8X4* pClr = (IC_32_RGBA_U8X4*)&clr, 
            (size_t)snprintf(buf, 256, fmIfClr, pClr->R, pClr->G, pClr->B))
        ic_else_return(0) // clr设为ic_ctc_hold_v，表示颜色不改变。
    }
    return (size_t)snprintf(buf, 256, "%s", fmIfResetClr);
}

ic_core_dcl size_t ic_call icBgClrToS8(ch8_t* dst, RGBA_t clr) ic_noexc {
    return (size_t)H_icCTCToBuf((char*)dst, "\x1B[48;2;%hhu;%hhu;%hhum", "\x1B[49m", clr);
}

ic_core_dcl size_t ic_call icFgClrToS8(ch8_t* dst, RGBA_t clr) ic_noexc {
    return (size_t)H_icCTCToBuf((char*)dst, "\x1B[38;2;%hhu;%hhu;%hhum", "\x1B[39m", clr);
}

ic_core_dcl bool ic_call icSetConsoleTextColor(RGBA_t txClr, RGBA_t bkClr) ic_noexc {
    //"\x1B[39m" - 恢复文字的前景色（字色）为默认颜色。
    //"\x1B[49m" - 恢复文字的背景色（底色）为默认颜色。
    //"\x1B[38;2;R;G;Bm" - 指定前景色（字色）。
    //"\x1B[48;2;R;G;Bm" - 指定背景色（底色）。
#ifdef IC_OS_WINDOWS
    bool b = ((g_icInitFlags & ic_itf_console_color_v) != 0);
#else
    bool b = true;
#endif
    if (b) {
        char  clBuf[64];
        char* it = clBuf;
        it += H_icCTCToBuf(it, "\x1B[38;2;%hhu;%hhu;%hhum", "\x1B[39m", txClr);
        it += H_icCTCToBuf(it, "\x1B[48;2;%hhu;%hhu;%hhum", "\x1B[49m", bkClr);
        b   = icWriteConsoleUtf8((const ch8_t*)clBuf, it - clBuf);
    }
    return b;
}

ic_core_dcl bool ic_call icSetConsoleTextColorFG(RGBA_t fgClr) ic_noexc {
    //"\x1B[39m" - 恢复文字的前景色（字色）为默认颜色。
    //"\x1B[38;2;R;G;Bm" - 指定前景色（字色）。
#ifdef IC_OS_WINDOWS
    bool b = ((g_icInitFlags & ic_itf_console_color_v) != 0);
#else
    bool b = true;
#endif
    if (b) {
        char  clBuf[64];
        char* it = clBuf;
        it += H_icCTCToBuf(it, "\x1B[38;2;%hhu;%hhu;%hhum", "\x1B[39m", fgClr);
        b   = icWriteConsoleUtf8((const ch8_t*)clBuf, it - clBuf);
    }
    return b;
}

ic_core_dcl bool ic_call icSetConsoleTextColorBG(RGBA_t bgClr) ic_noexc {
    //"\x1B[49m" - 恢复文字的背景色（底色）为默认颜色。
    //"\x1B[48;2;R;G;Bm" - 指定背景色（底色）。
#ifdef IC_OS_WINDOWS
    bool b = ((g_icInitFlags & ic_itf_console_color_v) != 0);
#else
    bool b = true;
#endif
    if (b) {
        char  clBuf[64];
        char* it = clBuf;
        it += H_icCTCToBuf(it, "\x1B[48;2;%hhu;%hhu;%hhum", "\x1B[49m", bgClr);
        b   = icWriteConsoleUtf8((const ch8_t*)clBuf, it - clBuf);
    }
    return b;
}

ic_core_dcl size_t ic_call icWriteConsoleUtf8(cch8_p s, size_t sLen) ic_noexc {
    return fwrite(s, sizeof(utf8_t), sLen, stdout);
}

#define icWriteConsoleUtf_m(ch_xt, icSToSLen_xf, icSToS_xf) \
    IC_TRANSLATED_STRING_INFO info; \
    const ch_xt* sEd = s + sLen; \
    size_t sz = icSToSLen_xf(&info, s, sEd); \
    ic_if_return(info.result != ic_tcr_ok_v, -1); \
    ch8_p pMem = (ch8_p)icPosixAlloc(sizeof(ch8_t) * sz); \
    icSToS_xf(pMem, &info, s, sEd); \
    ic_if_do(icWriteConsoleUtf8(pMem, sz) != sz, sz = -1); \
    icPosixDealloc(pMem); \
    return sz

ic_core_dcl size_t ic_call icWriteConsoleUtf16(cch16_p s, size_t sLen) ic_noexc {
    icWriteConsoleUtf_m(ch16_t, icS16ToS8Len, icS16ToS8);
}

ic_core_dcl size_t ic_call icWriteConsoleUtf32(cch32_p s, size_t sLen) ic_noexc {
    icWriteConsoleUtf_m(ch32_t, icS32ToS8Len, icS32ToS8);
}

#undef icWriteConsoleUtf_m

ic_core_dcl size_t ic_call icReadConsoleUtf8(ch8_t* pMem, size_t bufMax) ic_noexc {
    ic_if_return(!fgets((ch8_t*)pMem, (int)bufMax, stdin), -1);
    return (size_t)(strlen((ch8_t*)pMem) - 1);
}

#define icReadConsoleUtf_m(icSToSLen_xf, icSToS_xf, nBufMax) \
    ch8_t buf8[nBufMax]; \
    ic_if_return(icReadConsoleUtf8(buf8, nBufMax) == -1, -1); \
    ch8_p buf8Ed = buf8 + icStrLen(buf8); \
    IC_TRANSLATED_STRING_INFO info; \
    size_t sz = icSToSLen_xf(&info, buf8, buf8Ed); \
    ic_if_return(info.result != ic_tcr_ok_v, -1); \
    ic_if_return(bufMax < sz + 1, -1); \
    sz = icSToS_xf(pMem, &info, buf8, buf8Ed); \
    pMem[sz] = 0; \
    return sz

ic_core_dcl size_t ic_call icReadConsoleUtf16(ch16_t* pMem, size_t bufMax) ic_noexc {
    icReadConsoleUtf_m(icS8ToS16Len, icS8ToS16, 4096);
}

ic_core_dcl size_t ic_call icReadConsoleUtf32(ch32_t* pMem, size_t bufMax) ic_noexc {
    icReadConsoleUtf_m(icS8ToS32Len, icS8ToS32, 4096);
}
#undef icReadConsoleUtf_m
#endif