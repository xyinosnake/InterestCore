
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("declarations")
    ic_core_dcl bool ic_call icSameStrSizeCI8 (cch8_p  s1, size_t sz1, cch8_p  s2, size_t sz2) ic_noexc; //CI: case insensitive.
    ic_core_dcl bool ic_call icSameStrSizeCI16(cch16_p s1, size_t sz1, cch16_p s2, size_t sz2) ic_noexc;
    ic_core_dcl bool ic_call icSameStrSizeCI32(cch32_p s1, size_t sz1, cch32_p s2, size_t sz2) ic_noexc;

    ic_inl bool ic_call icSameStrCI8 (cch8_p  s1Bg, cch8_p  s1Ed, cch8_p  s2Bg, cch8_p  s2Ed) ic_noexc;
    ic_inl bool ic_call icSameStrCI16(cch16_p s1Bg, cch16_p s1Ed, cch16_p s2Bg, cch16_p s2Ed) ic_noexc;
    ic_inl bool ic_call icSameStrCI32(cch32_p s1Bg, cch32_p s1Ed, cch32_p s2Bg, cch32_p s2Ed) ic_noexc;

    ic_core_dcl ch8_p  ic_call icStrToLower8 (ch8_p  dst, cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl ch16_p ic_call icStrToLower16(ch16_p dst, cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl ch32_p ic_call icStrToLower32(ch32_p dst, cch32_p bg, cch32_p ed) ic_noexc;

    ic_core_dcl ch8_p  ic_call icStrToUpper8 (ch8_p  dst, cch8_p  bg, cch8_p  ed) ic_noexc;
    ic_core_dcl ch16_p ic_call icStrToUpper16(ch16_p dst, cch16_p bg, cch16_p ed) ic_noexc;
    ic_core_dcl ch32_p ic_call icStrToUpper32(ch32_p dst, cch32_p bg, cch32_p ed) ic_noexc;

    ic_inl bool ic_call icIsLower8 (ch8_t  c) ic_noexc;
    ic_inl bool ic_call icIsLower16(ch16_t c) ic_noexc;
    ic_inl bool ic_call icIsLower32(ch32_t c) ic_noexc;
    ic_inl bool ic_call icIsUpper8 (ch8_t  c) ic_noexc;
    ic_inl bool ic_call icIsUpper16(ch16_t c) ic_noexc;
    ic_inl bool ic_call icIsUpper32(ch32_t c) ic_noexc;

    ic_inl ch8_t  ic_call icToLower8 (ch8_t  c) ic_noexc;
    ic_inl ch16_t ic_call icToLower16(ch16_t c) ic_noexc;
    ic_inl ch32_t ic_call icToLower32(ch32_t c) ic_noexc;
    ic_inl ch8_t  ic_call icToUpper8 (ch8_t  c) ic_noexc;
    ic_inl ch16_t ic_call icToUpper16(ch16_t c) ic_noexc;
    ic_inl ch32_t ic_call icToUpper32(ch32_t c) ic_noexc;

ic_info("inlines")
    ic_inl bool ic_call icSameStrCI8(cch8_p s1Bg, cch8_p s1Ed, cch8_p s2Bg, cch8_p s2Ed) ic_noexc {
        return icSameStrSizeCI8(s1Bg, s1Ed - s1Bg, s2Bg, s2Ed - s2Bg);
    }

    ic_inl bool ic_call icSameStrCI16(cch16_p s1Bg, cch16_p s1Ed, cch16_p s2Bg, cch16_p s2Ed) ic_noexc {
        return icSameStrSizeCI16(s1Bg, s1Ed - s1Bg, s2Bg, s2Ed - s2Bg);
    }

    ic_inl bool ic_call icSameStrCI32(cch32_p s1Bg, cch32_p s1Ed, cch32_p s2Bg, cch32_p s2Ed) ic_noexc {
        return icSameStrSizeCI32(s1Bg, s1Ed - s1Bg, s2Bg, s2Ed - s2Bg);
    }

    ic_inl bool ic_call icIsLower8(ch8_t c) ic_noexc {
        return (c >= (ch8_t)'a' && c <= (ch8_t)'z');
    }

    ic_inl bool ic_call icIsLower16(ch16_t c) ic_noexc {
        return (c >= (ch16_t)'a' && c <= (ch16_t)'z');
    }

    ic_inl bool ic_call icIsLower32(ch32_t c) ic_noexc {
        return (c >= (ch32_t)'a' && c <= (ch32_t)'z');
    }

    ic_inl bool ic_call icIsUpper8(ch8_t c) ic_noexc {
        return (c >= (ch8_t)'A' && c <= (ch8_t)'Z');
    }

    ic_inl bool ic_call icIsUpper16(ch16_t c) ic_noexc {
        return (c >= (ch16_t)'A' && c <= (ch16_t)'Z');
    }

    ic_inl bool ic_call icIsUpper32(ch32_t c) ic_noexc {
        return (c >= (ch32_t)'A' && c <= (ch32_t)'Z');
    }
    
    ic_inl ch8_t ic_call icToLower8(ch8_t c) ic_noexc {
        return icIsUpper8(c) ? (c - (ch8_t)'A' + (ch8_t)'a') : c;
    }

    ic_inl ch16_t ic_call icToLower16(ch16_t c) ic_noexc {
        return icIsUpper16(c) ? (c - (ch16_t)'A' + (ch16_t)'a') : c;
    }

    ic_inl ch32_t ic_call icToLower32(ch32_t c) ic_noexc {
        return icIsUpper32(c) ? (c - (ch32_t)'A' + (ch32_t)'a') : c;
    }

    ic_inl ch8_t ic_call icToUpper8(ch8_t c) ic_noexc {
        return icIsLower8(c) ? (c - (ch8_t)'a' + (ch8_t)'A') : c;
    }

    ic_inl ch16_t ic_call icToUpper16(ch16_t c) ic_noexc {
        return icIsLower16(c) ? (c - (ch16_t)'a' + (ch16_t)'A') : c;
    }

    ic_inl ch32_t ic_call icToUpper32(ch32_t c) ic_noexc {
        return icIsLower32(c) ? (c - (ch32_t)'a' + (ch32_t)'A') : c;
    }