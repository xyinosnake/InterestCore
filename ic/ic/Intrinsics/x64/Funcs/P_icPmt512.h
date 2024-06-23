
#pragma once

#include"../icX64Headers.h"
#include"../icX64Macros.h"
#include"../icX64Types.h"

ic_info("512")
#if IC_AVX512
    #define icLoad512         _mm512_load_si512
    #define icLoad512F32x16   _mm512_load_ps
    #define icLoad512F64x8    _mm512_load_pd
    #define icLoadU512        _mm512_loadu_si512
    #define icLoadU512F32x16  _mm512_loadu_ps
    #define icLoadU512F64x8   _mm512_loadu_pd
    #define icStore512        _mm512_store_si512
    #define icStore512F32x16  _mm512_store_ps
    #define icStore512F64x8   _mm512_store_pd
    #define icStoreU512       _mm512_storeu_si512
    #define icStoreU512F32x16 _mm512_storeu_ps
    #define icStoreU512F64x8  _mm512_storeu_pd
    #define icAdd512U8x64     _mm512_add_epi8 
    #define icAdd512U16x32    _mm512_add_epi16
    #define icAdd512U32x16    _mm512_add_epi32
    #define icAdd512U64x8     _mm512_add_epi64
    #define icAdd512I8x64     _mm512_add_epi8 
    #define icAdd512I16x32    _mm512_add_epi16
    #define icAdd512I32x16    _mm512_add_epi32
    #define icAdd512I64x8     _mm512_add_epi64
    #define icAdd512F32x16    _mm512_add_ps
    #define icAdd512F64x8     _mm512_add_pd
    #define icSub512U8x64     _mm512_sub_epi8
    #define icSub512U16x32    _mm512_sub_epi16
    #define icSub512U32x16    _mm512_sub_epi32
    #define icSub512U64x8     _mm512_sub_epi64
    #define icSub512I8x64     _mm512_sub_epi8
    #define icSub512I16x32    _mm512_sub_epi16
    #define icSub512I32x16    _mm512_sub_epi32
    #define icSub512I64x8     _mm512_sub_epi64
    #define icSub512F32x16    _mm512_sub_ps
    #define icSub512F64x8     _mm512_sub_pd
    #define icMul512I16x32    _mm512_mullo_epi16
    #define icMul512I32x16    _mm512_mullo_epi32
    #define icMul512I64x8     _mm512_mullo_epi64
    #define icMul512F32x16    _mm512_mul_ps
    #define icMul512F64x8     _mm512_mul_pd
    #define icDiv512U8x64     _mm512_div_epu8
    #define icDiv512U16x32    _mm512_div_epu16
    #define icDiv512U32x16    _mm512_div_epu32
    #define icDiv512U64x8     _mm512_div_epu64
    #define icDiv512I8x64     _mm512_div_epi8
    #define icDiv512I16x32    _mm512_div_epi16
    #define icDiv512I32x16    _mm512_div_epi32
    #define icDiv512I64x8     _mm512_div_epi64
    #define icDiv512F32x16    _mm512_div_ps
    #define icDiv512F64x8     _mm512_div_pd
    #define icAnd512          _mm512_and_si512
    #define icAnd512F32x16    _mm512_and_ps
    #define icAnd512F64x8     _mm512_and_pd
    #define icOr512           _mm512_or_si512
    #define icOr512F32x16     _mm512_or_ps
    #define icOr512F64x8      _mm512_or_pd
    #define icXor512          _mm512_xor_si512
    #define icXor512F32x16    _mm512_xor_ps
    #define icXor512F64x8     _mm512_xor_pd
#endif