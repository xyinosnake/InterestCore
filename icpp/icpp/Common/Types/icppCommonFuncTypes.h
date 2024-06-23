
#pragma once

#include"../icppCommonHeaders.h"
#include"../Macros/icppCommonMacros.h"
#include"../../../../ic/ic/Common/Types/icCommonTypes.h"

ic_info("Func Types Decs") icpp_ns_x1(icpp)
    icpp_alias(operate_f,   ::ic_operate_f);
    icpp_alias(alloc_f,     ::ic_alloc_f);
    icpp_alias(dealloc_f,   ::ic_dealloc_f);
    icpp_alias(realloc_f,   ::ic_realloc_f);
    icpp_alias(construct_f, ::ic_construct_f);
    icpp_alias(destruct_f,  ::ic_destruct_f);
    icpp_alias(thread_f,    ::ic_thread_f);
icpp_end_ns_x1;