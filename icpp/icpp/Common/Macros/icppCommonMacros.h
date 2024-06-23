
#pragma once

#include"../../../../ic/ic/Common/Macros/icCommonMacros.h"

#include"./icppLink.h"
#include"./icppTN.h"
#include"./icppNamespaceN.h"
#include"./icppNullRef.h"
#include"./icppTypeOf.h"
#include"./icppUsingN.h"
#include"./icppTraits.h"

ic_info("icpp alias")
    #define icpp_alias(Type, ...)               using Type = __VA_ARGS__

ic_info("静态判断")
    #ifndef ICPP_NO_STATIC_IF
        #define icpp_static_if   if constexpr
    #else
        #define icpp_static_if   if
    #endif

ic_info("异常")
    #define icpp_except(...)

ic_info("static if...")
    #define icpp_static_if_do(cb, cd)                 icpp_static_if(cb) { cd;  }
    #define icpp_static_if_else_do(cb, cda, cdb)      icpp_static_if(cb) { cda; } else { cdb; }
    #define icpp_static_if_return(cb, cr)             icpp_static_if(cb) { return cr;  }
    #define icpp_static_if_else_return(cb, cra, crb)  icpp_static_if(cb) { return cra; } else { return crb; }

ic_info("静态类型错误")
    struct H_icppNeverBe {};
    #define icpp_static_type_error(dType, msg)        static_assert(::std::is_same_v<dType, H_icppNeverBe>, msg)

ic_info("如果...交换")
    #define icpp_if_swap(b, va, vb) if (b) { auto H_icppTempVal = va; va = vb; vb = H_icppTempVal; } // 如果条件b为真，就交换va和vb的值。

ic_info("C++迭代区间")
    #define icpp_rangeof(c)       c.begin(), c.end()

ic_info("Unicode")
    #define icpp_utf8(s)         u8##s
    #define icpp_utf16(s)         u##s
    #define icpp_utf32(s)         U##s