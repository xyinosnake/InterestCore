
#pragma once

#include"./P_icStrFuncs.h"
#include"../Enums/icCoreStringEnums.h"

ic_info("decs");
    ic_core_dcl size_t ic_call icStrLen16Func(cch16_t* cs) ic_noexc {
        cch16_t* it = cs;
        ic_while_do_return(*it != 0, ++it, it - cs);
    }

    ic_core_dcl size_t ic_call icStrLen32Func(cch32_t* cs) ic_noexc {
        cch32_t* it = cs;
        ic_while_do_return(*it != 0, ++it, it - cs);
    }

    ic_core_dcl size_t ic_call icStrFormatToCharTypeSize(ic_str_fmt_e sfm) ic_noexc {
        static const uint8_t vals[4] = { 1, 2, 4, 1 };
        //ic_if_return(sfm >= 4, 0); clang++ warning always false
        return (size_t)(vals[sfm]);
    }

    ic_core_dcl ch16_p ic_call icASCIIToUtf16(ch16_p dst, cch8_p sASCIIBg, cch8_p sASCIIEd) ic_noexc {
        ic_while_do_return(sASCIIBg != sASCIIEd, *dst++ = (ch16_t)*sASCIIBg++, dst);
    }

    ic_core_dcl ch32_p ic_call icASCIIToUtf32(ch32_p dst, cch8_p sASCIIBg, cch8_p sASCIIEd) ic_noexc {
        ic_while_do_return(sASCIIBg != sASCIIEd, *dst++ = (ch32_t)*sASCIIBg++, dst);
    }

    #define ic00StrLenXX_m(ch_xt, f_xt)  \
        ic_init_do_while_return(const ch_xt* it = s00, it = it + f_xt(it) + 1, *it != (ch_xt)'\0', (it - 1) - s00)

    ic_core_dcl size_t ic_call ic00StrLen8(cch8_p s00) ic_noexc {
        ic00StrLenXX_m(ch8_t, icStrLen8);
    }

    ic_core_dcl size_t ic_call ic00StrLen16(cch16_p s00) ic_noexc {
        ic00StrLenXX_m(ch16_t, icStrLen16);
    }

    ic_core_dcl size_t ic_call ic00StrLen32(cch32_p s00) ic_noexc {
        ic00StrLenXX_m(ch32_t, icStrLen32);
    }

    ic_core_dcl size_t ic_call icWToN(nch_p dst, cwch_p src, size_t length) ic_noexc {
        return wcstombs(dst, src, length);
    }

    ic_core_dcl size_t ic_call icNToW(wch_p dst, cnch_p src, size_t length) ic_noexc {
        return mbstowcs(dst, src, length);
    }

    ic_inl IC_TRANSLATED_CHAR_INFO ic_call H_icMakeTCI(
        uint8_t result, uint8_t srcLenOrResidualLen, uint8_t srcNecessaryLen, uint8_t srcErrPos) ic_noexc {
        IC_TRANSLATED_CHAR_INFO info;
        info.result              = result;
        info.srcLenOrResidualLen = srcLenOrResidualLen;
        info.srcNecessaryLen     = srcNecessaryLen;
        info.srcErrPos           = srcErrPos;
        return info;
    }

    ic_core_dcl IC_TRANSLATED_CHAR_INFO ic_call icReadUtf8Buf(cch8_p bg, cch8_p ed) ic_noexc {
        // 出于效率方面的考虑，即使区间为空也不会设置ic_tcr_empty_source_v。
        uint8_t trLen  = 0; //Translated Len
        uint8_t c      = (uint8_t)*bg; // 检查第一个字节，确定UTF-8字符的字节长度
             ic_if_do((c & 0x80) == 0x00, trLen = 1) // 单字节字符
        else ic_if_do((c & 0xE0) == 0xC0, trLen = 2) // 双字节字符
        else ic_if_do((c & 0xF0) == 0xE0, trLen = 3) // 三字节字符
        else ic_if_do((c & 0xF8) == 0xF0, trLen = 4) // 四字节字符
        ic_else_return(H_icMakeTCI(ic_tcr_char_error_v, 0, 0, 0)) // 非法的起始字节
        size_t sz = ed - bg;
        ic_if_return(sz < (size_t)trLen, H_icMakeTCI(ic_tcr_not_enough_char_count_v, (uint8_t)sz, trLen, 0));
        for(uint8_t tempTrLen = 1; tempTrLen != trLen; ++tempTrLen) {
            c = *++bg;
            ic_if_return((c & 0xC0) != 0x80, H_icMakeTCI(ic_tcr_char_error_v, trLen, trLen, (uint8_t)tempTrLen));
        }
        return H_icMakeTCI(ic_tcr_ok_v, trLen, trLen, 0);
    }

    ic_core_dcl IC_TRANSLATED_CHAR_INFO ic_call icReadUtf16Buf(cch16_p bg, cch16_p ed) ic_noexc {
        // 出于效率方面的考虑，即使区间为空也不会设置ic_tcr_empty_source_v。
        uint8_t  trLen = 0;
        uint16_t c     = (uint16_t)*bg; // 检查第一个字，确定UTF-16字符的字节长度
             ic_if_do(c < 0xD800 || c > 0xDFFF, trLen = 1) // 单字字符
        else ic_if_do((c & 0xFC00) == 0xD800,   trLen = 2) // 双字字符
        ic_else_return(H_icMakeTCI(ic_tcr_char_error_v, 0, 0, 0)) // 非法的起始字
        size_t sz = ed - bg;
        ic_if_return(sz < (size_t)trLen, H_icMakeTCI(ic_tcr_not_enough_char_count_v, (uint8_t)sz, trLen, 0));
        if (trLen == 2) {
            c = *++bg;
            ic_if_return((c & 0xFC00) == 0xDC00, H_icMakeTCI(ic_tcr_char_error_v, trLen, trLen, 1));
        }
        return H_icMakeTCI(ic_tcr_ok_v, trLen, trLen, 0);
    }

    ic_core_dcl IC_TRANSLATED_CHAR_INFO ic_call icReadUtf32Buf(cch32_p bg, cch32_p ed) ic_noexc {
        // 出于效率方面的考虑，即使区间为空也不会设置ic_tcr_empty_source_v。
        ic_if_return(*bg > 0x10FFFF, H_icMakeTCI(ic_tcr_char_error_v, 0, 0, 0)); // 检查第一个双字范围
        return H_icMakeTCI(ic_tcr_ok_v, 1, 1, 0);
    }

    ic_core_dcl ch32_t ic_call icUtf8BufToCh32(cch8_p buf, size_t len) ic_noexc {
        ic_assert(len <= 4 && len != 0, "Utf8 char buf valid len -> 1 2 3 4");
        uint32_t utf32;
        switch (len) {
            case 4: // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
                utf32  = (uint32_t)(buf[0] & 0x07) << 18;
                utf32 |= (uint32_t)(buf[1] & 0x3F) << 12;
                utf32 |= (uint32_t)(buf[2] & 0x3F) << 6;
                utf32 |= (uint32_t)(buf[3] & 0x3F);
                utf32 += 0x10000;
                break;
            case 3: // 1110xxxx 10xxxxxx 10xxxxxx
                utf32  = (uint32_t)(buf[0] & 0x0F) << 12;
                utf32 |= (uint32_t)(buf[1] & 0x3F) << 6;
                utf32 |= (uint32_t)(buf[2] & 0x3F);
                break;
            case 2: // 110xxxxx 10xxxxxx
                utf32  = (uint32_t)(buf[0] & 0x1F) << 6;
                utf32 |= (uint32_t)(buf[1] & 0x3F);
                break;
            case 1: // 0xxxxxxx (ASCII)
                utf32 = (uint32_t)buf[0];
                break;
        }
        return (ch32_t)utf32;
    }

    ic_core_dcl ch32_t ic_call icUtf16BufToCh32(cch16_p buf, size_t len) ic_noexc {
        ic_assert(len <= 2 && len != 0, "Utf16 char buf valid len -> 1 2");
        uint32_t utf32 = 0;
        switch (len) {
            case 2: // 代理对
                utf32 = ((uint32_t)(buf[0] - 0xD800) << 10) + 
                        ((uint32_t)(buf[1] - 0xDC00) + 0x10000);
                break;
            case 1: // BMP字符
                utf32 = (uint32_t)buf[0]; // 直接使用第一个16位代码单元
                break;
        }
        return utf32;
    }

    ic_core_dcl ch32_t ic_call icUtf32BufToCh32(cch32_p buf, size_t len) ic_noexc {
        ic_assert(len == 1, "Utf16 char buf valid len -> 1");
        return buf[0];
    }

    ic_core_dcl size_t ic_call icCh32ToUtfBuf8(ch8_p buf, ch32_t c) ic_noexc {
        if (c <= 0x7F) { // 对于U+0000到U+007F的字符，使用单个字节表示
            buf[0] = (ch8_t)c;
            return 1;
        } else if (c <= 0x7FF) { // 对于U+0080到U+07FF的字符，使用两个字节表示
            buf[0] = (ch8_t)(((c >> 6) & 0x1F) | 0xC0);
            buf[1] = (ch8_t)((c & 0x3F) | 0x80);
            return 2;
        } else if (c <= 0xFFFF) { // 对于U+0800到U+FFFF的字符，使用三个字节表示
            buf[0] = (ch8_t)(((c >> 12) & 0x0F) | 0xE0);
            buf[1] = (ch8_t)(((c >> 6) & 0x3F) | 0x80);
            buf[2] = (ch8_t)((c & 0x3F) | 0x80);
            return 3;
        } else { // 对于U+10000到U+10FFFF的字符，使用四个字节表示
            buf[0] = (ch8_t)(((c >> 18) & 0x07) | 0xF0);
            buf[1] = (ch8_t)(((c >> 12) & 0x3F) | 0x80);
            buf[2] = (ch8_t)(((c >> 6) & 0x3F) | 0x80);
            buf[3] = (ch8_t)((c & 0x3F) | 0x80);
            return 4;
        }
    }

    ic_core_dcl size_t ic_call icCh32ToUtfBuf16(ch16_p buf, ch32_t c) ic_noexc {
        ic_if_do_and_return(c <= 0xFFFF, buf[0] = (ch16_t)c, 1) // 如果字符在BMP内，使用单个16位值表示
        uint32_t u = (uint32_t)c - (uint32_t)0x10000;      // 如果字符在BMP外，使用代理项对表示
        buf[0] = (ch16_t)((uint32_t)0xD800 + (u >> 10));   // 高代理项
        buf[1] = (ch16_t)((uint32_t)0xDC00 + (u & 0x3FF)); // 低代理项
        return 2;
    }

    ic_core_dcl size_t ic_call icCh32ToUtfBuf32(ch32_p buf, ch32_t c) ic_noexc {
        *buf = c;
        return 1;
    }

    
    ic_inl void ic_call H_icMakeTSI(IC_TRANSLATED_STRING_INFO* pInfo,
        int16_t result, int16_t srcResidualLen, int16_t srcCharNecessaryLen, size_t srcErrStartPos, int16_t srcErrStartPosShift) ic_noexc {
        pInfo->result              = result;
        pInfo->srcResidualLen      = srcResidualLen;
        pInfo->srcCharNecessaryLen = srcCharNecessaryLen;
        pInfo->srcErrStartPosShift = srcErrStartPosShift;
        pInfo->srcErrStartPos      = srcErrStartPos;
    }

    ic_inl void ic_call H_icConvertTCIToTSI(IC_TRANSLATED_STRING_INFO* pInfo, IC_TRANSLATED_CHAR_INFO tci, size_t srcErrStartPos) ic_noexc {
        pInfo->result              = tci.result;
        pInfo->srcResidualLen      = tci.srcLenOrResidualLen;
        pInfo->srcCharNecessaryLen = tci.srcNecessaryLen;
        pInfo->srcErrStartPos      = srcErrStartPos;
        pInfo->srcErrStartPosShift = tci.srcErrPos;
    }

    #define icS1ToS2Len_m(ch1_xt, icReadUtfBuf_xf, icUtfBufToCh32_xf, icCh32ToUtfBufLen_xf) \
        ic_if_do_and_return(bg == ed, H_icMakeTSI(pInfo, ic_tcr_empty_source_v, 0, 0, 0, 0), 0); \
        IC_TRANSLATED_CHAR_INFO info; \
        const ch1_xt* it = bg; \
            size_t  sz = 0; \
            size_t  tLen; \
        while (it != ed) { \
            info = icReadUtfBuf_xf(it, ed); \
            ic_if_do_and_return(info.result != ic_tcr_ok_v, H_icConvertTCIToTSI(pInfo, info, it - bg), 0); \
            tLen = (size_t)info.srcLenOrResidualLen; \
            sz  += icCh32ToUtfBufLen_xf(icUtfBufToCh32_xf(it, tLen)); \
            it  += tLen; \
        } \
        H_icMakeTSI(pInfo, ic_tcr_ok_v, 0, 0, 0, 0); \
        return sz
    #define icParamTo1_m(prm)         1

    ic_core_dcl size_t ic_call icS8ToS16Len(IC_TRANSLATED_STRING_INFO* pInfo, cch8_p bg, cch8_p ed) ic_noexc {
        icS1ToS2Len_m(ch8_t, icReadUtf8Buf, icUtf8BufToCh32, icCh32ToUtfBuf16Len);
    }

    ic_core_dcl size_t ic_call icS8ToS32Len(IC_TRANSLATED_STRING_INFO* pInfo, cch8_p bg, cch8_p ed) ic_noexc {
        icS1ToS2Len_m(ch8_t, icReadUtf8Buf, icUtf8BufToCh32, icParamTo1_m);
    }

    ic_core_dcl size_t ic_call icS16ToS8Len(IC_TRANSLATED_STRING_INFO* pInfo, cch16_p bg, cch16_p ed) ic_noexc {
        icS1ToS2Len_m(ch16_t, icReadUtf16Buf, icUtf16BufToCh32, icCh32ToUtfBuf8Len);
    }

    ic_core_dcl size_t ic_call icS16ToS32Len(IC_TRANSLATED_STRING_INFO* pInfo, cch16_p bg, cch16_p ed) ic_noexc {
        icS1ToS2Len_m(ch16_t, icReadUtf16Buf, icUtf16BufToCh32, icParamTo1_m);
    }

    ic_core_dcl size_t ic_call icS32ToS8Len(IC_TRANSLATED_STRING_INFO* pInfo, cch32_p bg, cch32_p ed) ic_noexc {
        icS1ToS2Len_m(ch32_t, icReadUtf32Buf, icUtf32BufToCh32, icCh32ToUtfBuf8Len);
    }

    ic_core_dcl size_t ic_call icS32ToS16Len(IC_TRANSLATED_STRING_INFO* pInfo, cch32_p bg, cch32_p ed) ic_noexc {
        icS1ToS2Len_m(ch32_t, icReadUtf32Buf, icUtf32BufToCh32, icCh32ToUtfBuf16Len);
    }
    #undef ic00StrLenXX_m
    #define icS1ToS2_m(ch1_xt, ch2_xt, icS1ToS2Len_xf, icReadUtfBuf_xf, icUtfBufToCh32_xf, icCh32ToUtfBuf_xf) \
        ic_if_return(!dst, icS1ToS2Len_xf(pInfo, bg, ed)); /*若dst为NULL，返回所需的长度。*/ \
        ic_line_x2(const ch1_xt* it = bg, ch2_xt* dstIt = dst); \
        while (it != ed) { \
            IC_TRANSLATED_CHAR_INFO info = icReadUtfBuf_xf(it, ed); \
            ic_if_do_and_return(info.result != ic_tcr_ok_v, H_icConvertTCIToTSI(pInfo, info, it - bg), 0); \
            size_t tLen = (size_t)info.srcLenOrResidualLen; \
            dstIt += icCh32ToUtfBuf_xf(dstIt, icUtfBufToCh32_xf(it, tLen)); \
            it    += tLen; \
        } \
        ic_do_and_return(H_icMakeTSI(pInfo, ic_tcr_ok_v, 0, 0, 0, 0), dstIt - dst)

    ic_core_dcl size_t ic_call icS8ToS16(ch16_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch8_p bg, cch8_p ed) ic_noexc {
        icS1ToS2_m(ch8_t, ch16_t, icS8ToS16Len, icReadUtf8Buf, icUtf8BufToCh32, icCh32ToUtfBuf16);
    }

    ic_core_dcl size_t ic_call icS8ToS32(ch32_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch8_p bg, cch8_p ed) ic_noexc {
        icS1ToS2_m(ch8_t, ch32_t, icS8ToS32Len, icReadUtf8Buf, icUtf8BufToCh32, icCh32ToUtfBuf32);
    }

    ic_core_dcl size_t ic_call icS16ToS8(ch8_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch16_p bg, cch16_p ed) ic_noexc {
        icS1ToS2_m(ch16_t, ch8_t, icS16ToS8Len, icReadUtf16Buf, icUtf16BufToCh32, icCh32ToUtfBuf8);
    }

    ic_core_dcl size_t ic_call icS16ToS32(ch32_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch16_p bg, cch16_p ed) ic_noexc {
        icS1ToS2_m(ch16_t, ch32_t, icS16ToS32Len, icReadUtf16Buf, icUtf16BufToCh32, icCh32ToUtfBuf32);
    }

    ic_core_dcl size_t ic_call icS32ToS8(ch8_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch32_p bg, cch32_p ed) ic_noexc {
        icS1ToS2_m(ch32_t, ch8_t, icS32ToS8Len, icReadUtf32Buf, icUtf32BufToCh32, icCh32ToUtfBuf8);
    }

    ic_core_dcl size_t ic_call icS32ToS16(ch16_p dst, IC_TRANSLATED_STRING_INFO* pInfo, cch32_p bg, cch32_p ed) ic_noexc {
        icS1ToS2_m(ch32_t, ch16_t, icS32ToS16Len, icReadUtf32Buf, icUtf32BufToCh32, icCh32ToUtfBuf16);
    }
    #undef icS1ToS2_m