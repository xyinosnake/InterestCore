
#pragma once

#include"../icppCommonHeaders.h"
#include"../Macros/icppCommonMacros.h"
#include"../../../../ic/ic/Common/Types/icCommonTypes.h"
#include"./P_icppIOFTypesBase.h"

#define icpp_define_iof_t(iof_xt) \
    icpp_t1(value_xt) struct iof_xt: iof_types_base { \
        value_xt value; \
                 explicit ic_inl         ic_call operator value_xt() { return value; } \
        icpp_t1(type2_xt) ic_inl iof_xt& ic_call operator=(type2_xt t) ic_noexc { value = t; } \
                          ic_inl ic_call iof_xt() ic_noexc {} \
        icpp_t1(type2_xt) ic_inl ic_call iof_xt(type2_xt t) ic_noexc { value = t; } \
    };

icpp_ns_x2(icpp, iof_types)
    icpp_define_iof_t(hex);
    icpp_define_iof_t(HEX);
    icpp_define_iof_t(bin);
icpp_end_ns_x2

icpp_ns_x1(icpp)
    ic_info("hex")
        icpp_alias(hex8_t,  iof_types::hex<u8_t>);
        icpp_alias(hex16_t, iof_types::hex<u16_t>);
        icpp_alias(hex32_t, iof_types::hex<u32_t>);
        icpp_alias(hex64_t, iof_types::hex<u64_t>);
    ic_info("HEX")
        icpp_alias(HEX8_t,  iof_types::HEX<u8_t>);
        icpp_alias(HEX16_t, iof_types::HEX<u16_t>);
        icpp_alias(HEX32_t, iof_types::HEX<u32_t>);
        icpp_alias(HEX64_t, iof_types::HEX<u64_t>);
    ic_info("hex HEX size ptr")
        icpp_alias(hex_size_t, iof_types::hex<size_t>);
        icpp_alias(HEX_size_t, iof_types::HEX<size_t>);
        icpp_alias(hex_ptr_t,  iof_types::hex<size_t>);
        icpp_alias(HEX_ptr_t,  iof_types::HEX<size_t>);

    ic_info("bin")
        icpp_alias(bin8_t,  iof_types::bin<u8_t>);
        icpp_alias(bin16_t, iof_types::bin<u16_t>);
        icpp_alias(bin32_t, iof_types::bin<u32_t>);
        icpp_alias(bin64_t, iof_types::bin<u64_t>);
    ic_info("bin size ptr")
        icpp_alias(bin_size_t, iof_types::bin<size_t>);
        icpp_alias(bin_ptr_t,  iof_types::bin<size_t>);
icpp_end_ns_x1;