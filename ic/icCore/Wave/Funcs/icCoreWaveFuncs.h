
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("declarations")
    ic_core_dcl flo32_t ic_call icGenSineWaveSampleF32(flo32_t* bg, flo32_t* ed, size_t sampleRate, flo32_t frequency, flo32_t phase, flo32_t volume) ic_noexc;
    ic_core_dcl flo64_t ic_call icGenSineWaveSampleF64(flo64_t* bg, flo64_t* ed, size_t sampleRate, flo64_t frequency, flo64_t phase, flo64_t volume) ic_noexc;
    ic_core_dcl flo32_t ic_call icGenTriangularWaveSampleF32(flo32_t* bg, flo32_t* ed, size_t sampleRate, flo32_t frequency, flo32_t phase, flo32_t volume) ic_noexc;
    ic_core_dcl flo64_t ic_call icGenTriangularWaveSampleF64(flo64_t* bg, flo64_t* ed, size_t sampleRate, flo64_t frequency, flo64_t phase, flo64_t volume) ic_noexc;
    ic_core_dcl flo32_t ic_call icGenSquareWaveSampleF32(flo32_t* bg, flo32_t* ed, size_t sampleRate, flo32_t frequency, flo32_t phase, flo32_t volume) ic_noexc;
    ic_core_dcl flo64_t ic_call icGenSquareWaveSampleF64(flo64_t* bg, flo64_t* ed, size_t sampleRate, flo64_t frequency, flo64_t phase, flo64_t volume) ic_noexc;