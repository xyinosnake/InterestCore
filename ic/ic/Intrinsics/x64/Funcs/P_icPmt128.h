
#pragma once

#include"../icX64Headers.h"
#include"../icX64Macros.h"
#include"../icX64Types.h"

ic_info("128")
    #define icLoad128        _mm_load_si128
    #define icLoad128F32x4   _mm_load_ps
    #define icLoad128F64x2   _mm_load_pd
    #define icLoadU128       _mm_loadu_si128
    #define icLoadU128F32x4  _mm_loadu_ps
    #define icLoadU128F64x2  _mm_loadu_pd
    #define icStore128       _mm_store_si128
    #define icStore128F32x4  _mm_store_ps
    #define icStore128F64x2  _mm_store_pd
    #define icStoreU128      _mm_storeu_si128
    #define icStoreU128F32x4 _mm_storeu_ps
    #define icStoreU128F64x2 _mm_storeu_pd
    #define icAdd128U8x16    _mm_add_epi8
    #define icAdd128U16x8    _mm_add_epi16
    #define icAdd128U32x4    _mm_add_epi32
    #define icAdd128U64x2    _mm_add_epi64
    #define icAdd128I8x16    _mm_add_epi8
    #define icAdd128I16x8    _mm_add_epi16
    #define icAdd128I32x4    _mm_add_epi32
    #define icAdd128I64x2    _mm_add_epi64
    #define icAdd128F32x4    _mm_add_ps
    #define icAdd128F64x2    _mm_add_pd
    #define icSub128U8x16    _mm_sub_epi8
    #define icSub128U16x8    _mm_sub_epi16
    #define icSub128U32x4    _mm_sub_epi32
    #define icSub128U64x2    _mm_sub_epi64
    #define icSub128I8x16    _mm_sub_epi8
    #define icSub128I16x8    _mm_sub_epi16
    #define icSub128I32x4    _mm_sub_epi32
    #define icSub128I64x2    _mm_sub_epi64
    #define icSub128F32x4    _mm_sub_ps
    #define icSub128F64x2    _mm_sub_pd
    #define icMul128I16x8    _mm_mullo_epi16
    #define icMul128I32x4    _mm_mullo_epi32
    #define icMul128I64x2    _mm_mullo_epi64
    #define icMul128F32x4    _mm_mul_ps
    #define icMul128F64x2    _mm_mul_pd
    #define icDiv128U8x16    _mm_div_epu8
    #define icDiv128U16x8    _mm_div_epu16
    #define icDiv128U32x4    _mm_div_epu32
    #define icDiv128U64x2    _mm_div_epu64
    #define icDiv128I8x16    _mm_div_epi8
    #define icDiv128I16x8    _mm_div_epi16
    #define icDiv128I32x4    _mm_div_epi32
    #define icDiv128I64x2    _mm_div_epi64
    #define icDiv128F32x4    _mm_div_ps
    #define icDiv128F64x2    _mm_div_pd
    #define icAnd128         _mm_and_si128
    #define icAnd128F32x4    _mm_and_ps
    #define icAnd128F64x2    _mm_and_pd
    #define icOr128          _mm_or_si128
    #define icOr128F32x4     _mm_or_ps
    #define icOr128F64x2     _mm_or_pd
    #define icXor128         _mm_xor_si128
    #define icXor128F32x4    _mm_xor_ps
    #define icXor128F64x2    _mm_xor_pd