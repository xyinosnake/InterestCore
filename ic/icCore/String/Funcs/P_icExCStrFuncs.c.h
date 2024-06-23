
#pragma once

#include"./P_icExCStrFuncs.h"

ic_info("macros")
    #ifdef IC_CE_MSC
        #define vsnwprintf _vsnwprintf
    #endif

ic_info("definitions")
    #define icSNPrintfAlloc_m(ch_xt, vsnprintf_xf) \
            va_list vl; \
            va_start(vl, fm); \
                size_t sz  = vsnprintf_xf(NULL, 0, fm, vl) + 1; \
                size_t cap = sz + 1; \
                ch_xt* buf = (ch_xt*)fAlloc(sizeof(ch_xt) * cap); \
                ic_if_do_and_goto(!buf, ic_if_do(pSz, *pSz = 0), posEnd); \
                vsnprintf_xf(buf, cap, fm, vl); \
                ic_if_do(pSz, *pSz = sz) \
        posEnd: \
            va_end(vl); \
            return buf

    ic_core_dcl nch_p ic_call icSNPrintfAllocN(ic_alloc_f fAlloc, size_t* pSz, cnch_p fm, ...) ic_noexc {
        icSNPrintfAlloc_m(nch_t, vsnprintf);
    }

    ic_core_dcl wch_p ic_call icSNPrintfAllocW(ic_alloc_f fAlloc, size_t* pSz, cwch_p fm, ...) ic_noexc {
        icSNPrintfAlloc_m(wch_t, vsnwprintf);
    }
    #undef icSNPrintfAlloc_m
    #define icSNPrintfBufferedAlloc_m(ch_xt, vsnprintf_xf) \
        va_list vl; \
            va_start(vl, fm); \
                size_t sz  = vsnprintf_xf(NULL, 0, fm, vl) + 1; \
                size_t cap = sz + 1; \
                ch_xt* buf; \
                ic_if_do_and_goto(cap <= staticCap, buf = staticBuf, posWrite); \
                buf = (ch_xt*)fAlloc(sizeof(ch_xt) * cap); \
                ic_if_do_and_goto(!buf, ic_if_do(pSz, *pSz = 0), posEnd); \
        posWrite: \
                vsnprintf_xf(buf, cap, fm, vl); \
                ic_if_do(pSz, *pSz = sz) \
        posEnd: \
            va_end(vl); \
            return buf

    ic_core_dcl nch_p ic_call icSNPrintfBufferedAllocN(nch_p staticBuf, size_t staticCap, ic_alloc_f fAlloc, size_t* pSz, cnch_p fm, ...) ic_noexc {
        icSNPrintfBufferedAlloc_m(nch_t, vsnprintf);
    }

    ic_core_dcl wch_p ic_call icSNPrintfBufferedAllocW(wch_p staticBuf, size_t staticCap, ic_alloc_f fAlloc, size_t* pSz, cwch_p fm, ...) ic_noexc {
        icSNPrintfBufferedAlloc_m(wch_t, vsnwprintf);
    }
    #undef icSNPrintfBufferedAlloc_m