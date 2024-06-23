
#pragma once

#include"./icX64Headers.h"
#include"./icX64Macros.h"

ic_info("128")
    ic_alias(ic128_u8x16_t, __m128i);
    ic_alias(ic128_u16x8_t, __m128i);
    ic_alias(ic128_u32x4_t, __m128i);
    ic_alias(ic128_u64x2_t, __m128i);
    ic_alias(ic128_i8x16_t, __m128i);
    ic_alias(ic128_i16x8_t, __m128i);
    ic_alias(ic128_i32x4_t, __m128i);
    ic_alias(ic128_i64x2_t, __m128i);
    ic_alias(ic128_f32x4_t, __m128);
    ic_alias(ic128_f64x2_t, __m128d);

ic_info("256")
    ic_alias(ic256_u8x32_t,  __m256i);
    ic_alias(ic256_u16x16_t, __m256i);
    ic_alias(ic256_u32x8_t,  __m256i);
    ic_alias(ic256_u64x4_t,  __m256i);
    ic_alias(ic256_i8x32_t,  __m256i);
    ic_alias(ic256_i16x16_t, __m256i);
    ic_alias(ic256_i32x8_t,  __m256i);
    ic_alias(ic256_i64x4_t,  __m256i);
    ic_alias(ic256_f32x8_t,  __m256);
    ic_alias(ic256_f64x4_t,  __m256d);

ic_info("512")
    #if IC_AVX512
        ic_alias(ic512_u8x64_t,  __m512i);
        ic_alias(ic512_u16x32_t, __m512i);
        ic_alias(ic512_u32x16_t, __m512i);
        ic_alias(ic512_u64x8_t,  __m512i);
        ic_alias(ic512_i8x64_t,  __m512i);
        ic_alias(ic512_i16x32_t, __m512i);
        ic_alias(ic512_i32x16_t, __m512i);
        ic_alias(ic512_i64x8_t,  __m512i);
        ic_alias(ic512_f32x16_t, __m512);
        ic_alias(ic512_f64x8_t,  __m512d);
    #endif
