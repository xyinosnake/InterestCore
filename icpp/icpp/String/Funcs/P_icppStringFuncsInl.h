
#pragma once

#include"./icppStringFuncs.h"
#include"../../Common/Types/icppCommonTypes.h"
#include"../../Common/Traits/icppCommonTraits.h"
#include"../../String/Objs/UCStr/icppUCStr.h"
#include"../../../../ic/icCore/String/icCoreString.h"

ic_info("definitions") icpp_ns_x1(icpp)
    icpp_t1(ch_xt) ic_inl ch_xt ic_call toLower(ch_xt c) ic_noexc {
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), (ch8_t )icToLower8 ((ch8_t )c)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), (ch16_t)icToLower16((ch16_t)c)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), (ch32_t)icToLower32((ch32_t)c))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));        
    }

    icpp_t1(ch_xt) ic_inl ch_xt ic_call toUpper(ch_xt c) ic_noexc {
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), (ch8_t )icToUpper8 ((ch8_t )c)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), (ch16_t)icToUpper16((ch16_t)c)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), (ch32_t)icToUpper32((ch32_t)c))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

    icpp_t1(ch_xt) ic_inl bool ic_call isLower(ch_xt c) ic_noexc {
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), icIsLower8 ((ch8_t )c)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), icIsLower16((ch16_t)c)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), icIsLower32((ch32_t)c))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

    icpp_t1(ch_xt) ic_inl bool ic_call isUpper(ch_xt c) ic_noexc {
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), icIsUpper8 ((ch8_t )c)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), icIsUpper16((ch16_t)c)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), icIsUpper32((ch32_t)c))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

    icpp_t1(ch_xt) ic_inl ch_xt* ic_call strToLower(ch_xt* dst, const ch_xt* bg, const ch_xt* ed) ic_noexc {
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), (ch_xt*)icStrToLower8 ((ch_xt*)dst, (const ch_xt*)bg, (const ch_xt*)ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), (ch_xt*)icStrToLower16((ch_xt*)dst, (const ch_xt*)bg, (const ch_xt*)ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), (ch_xt*)icStrToLower32((ch_xt*)dst, (const ch_xt*)bg, (const ch_xt*)ed))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

    icpp_t1(ch_xt) ic_inl ch_xt* ic_call strToUpper(ch_xt* dst, const ch_xt* bg, const ch_xt* ed) ic_noexc {
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), (ch_xt*)icStrToUpper8 ((ch_xt*)dst, (const ch_xt*)bg, (const ch_xt*)ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), (ch_xt*)icStrToUpper16((ch_xt*)dst, (const ch_xt*)bg, (const ch_xt*)ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), (ch_xt*)icStrToUpper32((ch_xt*)dst, (const ch_xt*)bg, (const ch_xt*)ed))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

    icpp_t1(ch_xt) ic_inl size_t ic_call strLen(const ch_xt* cs) ic_noexc {
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), icStrLen8 ((cch8_p )cs)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), icStrLen16((cch16_p)cs)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), icStrLen32((cch32_p)cs))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

    icpp_t1(ch_xp) ic_inl ch_xp ic_call strEnd(ch_xp cs) ic_noexc {
        return cs + strLen(cs);
    }

    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipSpaces(ch_xp bg, ch_xp ed) ic_noexcept {
        icpp_alias(ch_xt, icpp_typeof(*bg));
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), icSkipSpaces8 ((cch8_p )bg, (cch8_p )ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), icSkipSpaces16((cch16_p)bg, (cch16_p)ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), icSkipSpaces32((cch32_p)bg, (cch32_p)ed))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipSpacesBackward(ch_xp bg, ch_xp ed) ic_noexcept {
        icpp_alias(ch_xt, icpp_typeof(*bg));
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), icSkipSpacesBackward8 ((cch8_p )bg, (cch8_p )ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), icSkipSpacesBackward16((cch16_p)bg, (cch16_p)ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), icSkipSpacesBackward32((cch32_p)bg, (cch32_p)ed))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipGraphs(ch_xp bg, ch_xp ed) ic_noexcept {
        icpp_alias(ch_xt, icpp_typeof(*bg));
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), icSkipGraphs8 ((cch8_p )bg, (cch8_p )ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), icSkipGraphs16((cch16_p)bg, (cch16_p)ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), icSkipGraphs32((cch32_p)bg, (cch32_p)ed))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipGraphsBackward(ch_xp bg, ch_xp ed) ic_noexcept {
        icpp_alias(ch_xt, icpp_typeof(*bg));
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch8_t ), icSkipGraphsBackward8 ((cch8_p )bg, (cch8_p )ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch16_t), icSkipGraphsBackward16((cch16_p)bg, (cch16_p)ed)) else
        icpp_static_if_return(sizeof(ch_xt) == sizeof(ch32_t), icSkipGraphsBackward32((cch32_p)bg, (cch32_p)ed))
        ic_else_do(icpp_static_type_error(ch_xt, "wrong size!"));
    }

icpp_end_ns_x1