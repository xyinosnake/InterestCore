
#pragma once

#include"../../Common/Macros/icppCommonMacros.h"
#include"../../Common/Types/icppCommonTypes.h"
#include"../../Common/Traits/icppCommonTraits.h"
#include"../../../../ic/icCore/File/Funcs/icCoreFileFuncs.h"
#include"../Objs/declarations.h"

ic_info("declarations") icpp_ns_x1(icpp)
    ic_inl icppFile* ic_call createFileN(cnch_p fName, ic_file_e e) ic_noexc;
    ic_inl icppFile* ic_call createFileW(cwch_p fName, ic_file_e e) ic_noexc;
    icpp_t1(ch_xt)
        ic_inl icppFile* ic_call createFileG(const ch_xt* fName, ic_file_e e) ic_noexc;
icpp_end_ns_x1

ic_info("definitions inl ns") icpp_ns_x1(icpp)
    ic_inl icppFile* ic_call createFileN(cnch_p fName, ic_file_e e) ic_noexc {
        return (icppFile*)icCreateFileN(fName, e);
    }

    ic_inl icppFile* ic_call createFileW(cwch_p fName, ic_file_e e) ic_noexc {
        return (icppFile*)icCreateFileW(fName, e);
    }

    icpp_t1(ch_xt) ic_inl icppFile* ic_call createFileG(const ch_xt* fName, ic_file_e e) ic_noexc {
        icpp_static_if(sizeof(ch_xt) == sizeof(nch_t)) {
            return (icppFile*)icCreateFileN((cnch_p)fName, e);
        } else
        icpp_static_if(sizeof(ch_xt) == sizeof(wch_t)) {
            return (icppFile*)icCreateFileW((cwch_p)fName, e);
        } else {
            return nullptr;
        }
    }
icpp_end_ns_x1