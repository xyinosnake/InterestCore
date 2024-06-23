
#pragma once

#include"../icX64Headers.h"
#include"../icX64Macros.h"
#include"../icX64Types.h"

ic_info("256")
    #define icLoad256        _mm256_load_si256
    #define icLoad256F32x8   _mm256_load_ps
    #define icLoad256F64x4   _mm256_load_pd
    #define icLoadU256       _mm256_loadu_si256
    #define icLoadU256F32x8  _mm256_loadu_ps
    #define icLoadU256F64x4  _mm256_loadu_pd
    #define icStore256       _mm256_store_si256
    #define icStore256F32x8  _mm256_store_ps
    #define icStore256F64x4  _mm256_store_pd
    #define icStoreU256      _mm256_storeu_si256
    #define icStoreU256F32x8 _mm256_storeu_ps
    #define icStoreU256F64x4 _mm256_storeu_pd
    #define icAdd256U8x32    _mm256_add_epi8
    #define icAdd256U16x16   _mm256_add_epi16
    #define icAdd256U32x8    _mm256_add_epi32
    #define icAdd256U64x4    _mm256_add_epi64
    #define icAdd256I8x32    _mm256_add_epi8 
    #define icAdd256I16x16   _mm256_add_epi16
    #define icAdd256I32x8    _mm256_add_epi32
    #define icAdd256I64x4    _mm256_add_epi64
    #define icAdd256F32x8    _mm256_add_ps
    #define icAdd256F64x4    _mm256_add_pd
    #define icSub256U8x32    _mm256_sub_epi8
    #define icSub256U16x16   _mm256_sub_epi16
    #define icSub256U32x8    _mm256_sub_epi32
    #define icSub256U64x4    _mm256_sub_epi64
    #define icSub256I8x32    _mm256_sub_epi8 
    #define icSub256I16x16   _mm256_sub_epi16
    #define icSub256I32x8    _mm256_sub_epi32
    #define icSub256I64x4    _mm256_sub_epi64
    #define icSub256F32x8    _mm256_sub_ps
    #define icSub256F64x4    _mm256_sub_pd
    #define icMul256I16x8    _mm256_mullo_epi16
    #define icMul256I32x4    _mm256_mullo_epi32
    #define icMul256I64x2    _mm256_mullo_epi64
    #define icMul256F32x4    _mm256_mul_ps
    #define icMul256F64x2    _mm256_mul_pd
    #define icDiv256U8x32    _mm256_div_epu8
    #define icDiv256U16x16   _mm256_div_epu16
    #define icDiv256U32x8    _mm256_div_epu32
    #define icDiv256U64x4    _mm256_div_epu64
    #define icDiv256I8x32    _mm256_div_epi8
    #define icDiv256I16x16   _mm256_div_epi16
    #define icDiv256I32x8    _mm256_div_epi32
    #define icDiv256I64x4    _mm256_div_epi64
    #define icDiv256F32x8    _mm256_div_ps
    #define icDiv256F64x4    _mm256_div_pd
    #define icAnd256         _mm256_and_si256
    #define icAnd256F32x8    _mm256_and_ps
    #define icAnd256F64x4    _mm256_and_pd
    #define icOr256          _mm256_or_si256
    #define icOr256F32x8     _mm256_or_ps
    #define icOr256F64x4     _mm256_or_pd
    #define icXor256         _mm256_xor_si256
    #define icXor256F32x4    _mm256_xor_ps
    #define icXor256F64x2    _mm256_xor_pd