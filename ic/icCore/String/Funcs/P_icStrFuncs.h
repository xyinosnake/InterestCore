
#pragma once

#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("headers")
    #include"../Enums/icCoreStringEnums.h"
    #include"../Structs/icCoreStringStructs.h"
    #include"../../Common/icCoreHeaders.h"
    #include"../../Common/Types/icCoreCommonTypes.h"
    #include"../../MicroPlatforms/icCoreMicroPlatforms.h"

ic_info("inl decs")
    #define               icStrLen icStrLen8
    ic_inl size_t ic_call icStrLen8 (cch8_t*  cs) ic_noexc;
    ic_inl size_t ic_call icStrLen16(cch16_t* cs) ic_noexc;
    ic_inl size_t ic_call icStrLen32(cch32_t* cs) ic_noexc;
    ic_inl size_t ic_call icStrLenW(cwch_t* cs) ic_noexc;
    ic_inl size_t ic_call icStrLenN(cnch_t* cs) ic_noexc;
#ifdef IC_OS_WINDOWS
    #define               icStrLenA icStrLenN
#endif
    ic_inl size_t ic_call icMaxStrSizeOfInt(size_t btSzOfval, size_t szOfPre) ic_noexc;
    #define               icMaxStrSizeOfUint icMaxStrSizeOfInt
    ic_inl size_t ic_call icMaxStrSizeOfFrac(size_t btSzOfval) ic_noexc;
    ic_inl size_t ic_call icMaxStrSizeOfFlo(size_t btSzOfval, size_t szOfPre) ic_noexc;

ic_info("decs");
    ic_core_dcl size_t ic_call icStrLen16Func(cch16_t* cs) ic_noexc;
    ic_core_dcl size_t ic_call icStrLen32Func(cch32_t* cs) ic_noexc;
    ic_core_dcl ch16_p ic_call icASCIIToUtf16(ch16_p dst, cch8_p sASCIIBg, cch8_p sASCIIEd) ic_noexc;
    ic_core_dcl ch32_p ic_call icASCIIToUtf32(ch32_p dst, cch8_p sASCIIBg, cch8_p sASCIIEd) ic_noexc;
    ic_core_dcl size_t ic_call icStrFormatToCharTypeSize(ic_str_fmt_e sfm) ic_noexc;

    ic_core_dcl size_t ic_call ic00StrLen8 (cch8_p  s00) ic_noexc;
    ic_core_dcl size_t ic_call ic00StrLen16(cch16_p s00) ic_noexc;
    ic_core_dcl size_t ic_call ic00StrLen32(cch32_p s00) ic_noexc;

    ic_core_dcl size_t ic_call icWToN(nch_p dst, cwch_p src, size_t length) ic_noexc;
    ic_core_dcl size_t ic_call icNToW(wch_p dst, cnch_p src, size_t length) ic_noexc;

    ic_core_dcl IC_TRANSLATED_CHAR_INFO ic_call icReadUtf8Buf (cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl IC_TRANSLATED_CHAR_INFO ic_call icReadUtf16Buf(cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl IC_TRANSLATED_CHAR_INFO ic_call icReadUtf32Buf(cch32_p bg, cch32_p ed) ic_noexc;

    ic_core_dcl ch32_t ic_call icUtf8BufToCh32 (cch8_p  buf, size_t len) ic_noexc;
    ic_core_dcl ch32_t ic_call icUtf16BufToCh32(cch16_p buf, size_t len) ic_noexc;
    ic_core_dcl ch32_t ic_call icUtf32BufToCh32(cch32_p buf, size_t len) ic_noexc;

    ic_inl size_t ic_call icCh32ToUtfBuf8Len (ch32_t c) ic_noexc;
    ic_inl size_t ic_call icCh32ToUtfBuf16Len(ch32_t c) ic_noexc;
    ic_inl size_t ic_call icCh32ToUtfBuf32Len(ch32_t c) ic_noexc;

    ic_core_dcl size_t ic_call icCh32ToUtfBuf8 (ch8_p  buf, ch32_t c) ic_noexc;
    ic_core_dcl size_t ic_call icCh32ToUtfBuf16(ch16_p buf, ch32_t c) ic_noexc;
    ic_core_dcl size_t ic_call icCh32ToUtfBuf32(ch32_p buf, ch32_t c) ic_noexc;

    ic_core_dcl size_t ic_call icS8ToS16Len (IC_TRANSLATED_STRING_INFO* pInfo, cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl size_t ic_call icS8ToS32Len (IC_TRANSLATED_STRING_INFO* pInfo, cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl size_t ic_call icS16ToS8Len (IC_TRANSLATED_STRING_INFO* pInfo, cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl size_t ic_call icS16ToS32Len(IC_TRANSLATED_STRING_INFO* pInfo, cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl size_t ic_call icS32ToS8Len (IC_TRANSLATED_STRING_INFO* pInfo, cch32_p bg, cch32_p ed) ic_noexc;
    ic_core_dcl size_t ic_call icS32ToS16Len(IC_TRANSLATED_STRING_INFO* pInfo, cch32_p bg, cch32_p ed) ic_noexc;

    ic_core_dcl size_t ic_call icS8ToS16 (ch16_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl size_t ic_call icS8ToS32 (ch32_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl size_t ic_call icS16ToS8 (ch8_p  dst, IC_TRANSLATED_STRING_INFO* pInfo, cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl size_t ic_call icS16ToS32(ch32_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl size_t ic_call icS32ToS8 (ch8_p  dst, IC_TRANSLATED_STRING_INFO* pInfo, cch32_p bg, cch32_p ed) ic_noexc;
    ic_core_dcl size_t ic_call icS32ToS16(ch16_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch32_p bg, cch32_p ed) ic_noexc;

ic_info("inl defs")
    ic_inl size_t ic_call icStrLen8(cch8_t* cs) ic_noexc {
        return strlen(cs);
    }

    ic_inl size_t ic_call icStrLen16(cch16_t* cs) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return wcslen(cs);
    #else
        return icStrLen16Func(cs);
    #endif
    }

    ic_inl size_t ic_call icStrLen32(cch32_t* cs) ic_noexc {    
    #if defined(IC_OS_UNIX_LIKE)
        return wcslen(cs);
    #else
        return icStrLen32Func(cs);
    #endif
    }

    ic_inl size_t ic_call icStrLenW(cwch_t* cs) ic_noexc {
        return wcslen(cs);
    }

    ic_inl size_t ic_call icStrLenN(cnch_t* cs) ic_noexc {
        return strlen(cs);
    }

    ic_inl size_t ic_call icMaxStrSizeOfInt(size_t btSzOfval, size_t szOfPre) ic_noexc {
        return 1 + szOfPre + 8 * btSzOfval; // sign + szOfPre + MaxSzOfDigits
    }

    ic_inl size_t ic_call icMaxStrSizeOfFrac(size_t btSzOfval) ic_noexc {
        return 3 + 8 * btSzOfval; //3 = sign x 2 + '/', 8 x btSzOfval = bitsOfVal
    }

    ic_inl size_t ic_call icMaxStrSizeOfFlo(size_t btSzOfval, size_t szOfPre) ic_noexc {
        return 1 + szOfPre + 8 * btSzOfval; // sign + szOfPre + MaxSzOfDigits
    }

    ic_inl size_t ic_call icCh32ToUtfBuf8Len(ch32_t c) ic_noexc {
        ic_if_return(c <= 0x007F, 1) // 对于U+0000到U+007F的字符，使用单个字节表示
        ic_if_return(c <= 0x07FF, 2) // 对于U+0080到U+07FF的字符，使用两个字节表示
        ic_if_return(c <= 0xFFFF, 3) // 对于U+0800到U+FFFF的字符，使用三个字节表示
        return 4;                    // 对于U+10000到U+10FFFF的字符，使用四个字节表示
    }

    ic_inl size_t ic_call icCh32ToUtfBuf16Len(ch32_t c) ic_noexc {
        return c <= 0xFFFF ? 1 : 2;
    }

    ic_inl size_t ic_call icCh32ToUtfBuf32Len(ch32_t c) ic_noexc {
        return 1;
    }
