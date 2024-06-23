#ifndef IC_CORE_WAVE_FUNCS
#define IC_CORE_WAVE_FUNCS

#include"./icCoreWaveFuncs.h"
#include"../../Math/icCoreMath.h"

ic_info("definitions")
	#define icGenSineWaveSampleF_m(flo_xt, sin_xf) \
		ic_assert((phase >= (flo_xt)0.0) && (phase <= (flo_xt)1.0), "condition: (phase >= (flo_xt)0.0) && (phase <= (flo_xt)1.0)"); \
		ic_assert(frequency > (flo_xt)0.0, "condition: Frequency > (flo_xt)0.0"); \
		ic_assert(sampleRate > 0, "condition: sampleRate > 0"); \
		ic_assert((volume >= (flo_xt)0.0) && ((volume <= (flo_xt)0.0)), "condition: (volume >= (flo_xt)0.0) && ((volume <= (flo_xt)0.0))"); \
		ic_stv_x4(flo_xt, pi = (flo_xt)ic_pi, pi_2 = pi * (flo_xt)2.0, inc	= pi_2 / (flo_xt)sampleRate * frequency, rd = pi_2 * phase); \
		flo_xt* it = bg; \
		while (it != ed) { \
			*it++ = volume * sin_xf(rd); \
			ic_if_do((rd += inc) >= pi_2, rd -= pi_2); \
		} \
		return rd / pi_2

	ic_core_dcl flo32_t ic_call icGenSineWaveSampleF32(flo32_t* bg, flo32_t* ed, size_t sampleRate, flo32_t frequency, flo32_t phase, flo32_t volume) ic_noexc {
		icGenSineWaveSampleF_m(flo32_t, icSinF32);
	}

	ic_core_dcl flo64_t ic_call icGenSineWaveSampleF64(flo64_t* bg, flo64_t* ed, size_t sampleRate, flo64_t frequency, flo64_t phase, flo64_t volume) ic_noexc {
		icGenSineWaveSampleF_m(flo64_t, icSinF64);
	}
	#undef icGenSineWaveSampleF_m
	#define icGenTriangularWaveSampleF_m(flo_xt) \
		ic_assert((phase >= (flo_xt)0.0) && (phase <= (flo_xt)1.0), "condition: (phase >= (flo_xt)0.0) && (phase <= (flo_xt)1.0)"); \
		ic_assert(frequency > (flo_xt)0.0, "condition: Frequency > (flo_xt)0.0"); \
		ic_assert(sampleRate > 0, "condition: sampleRate > 0"); \
		ic_assert((volume >= (flo_xt)0.0) && ((volume <= (flo_xt)0.0)), "condition: (volume >= (flo_xt)0.0) && ((volume <= (flo_xt)0.0))"); \
		ic_stv_x4(flo_xt, oldPh = phase,  \
			dis = (flo_xt)sampleRate / frequency,  /* 单位周期 */ \
			inc = (flo_xt)2.0 / (dis / (flo_xt)2), /* 单位增值（-1.0起） */ \
			val \
		); \
		ic_if_do((phase += (flo_xt)0.25) >= (flo_xt)1.0, phase -= (flo_xt)1.0); \
		ic_if_do(phase < (flo_xt)0.5, val = inc * (phase * dis) + (flo_xt)-1.0) \
		ic_else_do_x2(inc *= (flo_xt)-1.0, val = inc * ((phase - (flo_xt)0.5) * dis) + (flo_xt)1.0); \
		flo_xt* it = bg; \
		while (it != ed) { \
			ic_do_x2(*it = val, val += inc); \
			ic_if_do_x2(val > (flo_xt)1.0, val = (flo_xt)1.0 - (val - (flo_xt)1.0), inc *= (flo_xt)-1.0) else \
			ic_if_do_x2(val < (flo_xt)-1.0, val = (flo_xt)-1.0 + ((flo_xt)-1.0 - val), inc *= (flo_xt)-1.0); \
			++it; \
		} \
		oldPh += ((flo_xt)(ed - bg) / dis); /* 重新计算相位 */ \
		oldPh -= (flo_xt)(int)oldPh; \
		return oldPh

	ic_core_dcl flo32_t ic_call icGenTriangularWaveSampleF32(flo32_t* bg, flo32_t* ed, size_t sampleRate, flo32_t frequency, flo32_t phase, flo32_t volume) ic_noexc {
		icGenTriangularWaveSampleF_m(flo32_t);
	}

	ic_core_dcl flo64_t ic_call icGenTriangularWaveSampleF64(flo64_t* bg, flo64_t* ed, size_t sampleRate, flo64_t frequency, flo64_t phase, flo64_t volume) ic_noexc {
		icGenTriangularWaveSampleF_m(flo64_t);
	}
	#undef icGenTriangularWaveSampleF_m

	#define icGenSquareWaveSampleF_m(flo_xt) \
		ic_assert((phase >= (flo_xt)0.0) && (phase <= (flo_xt)1.0), "condition: (phase >= (flo_xt)0.0) && (phase <= (flo_xt)1.0)"); \
		ic_assert(frequency > (flo_xt)0.0, "condition: Frequency > (flo_xt)0.0"); \
		ic_assert(sampleRate > 0, "condition: sampleRate > 0"); \
		ic_assert((volume >= (flo_xt)0.0) && ((volume <= (flo_xt)0.0)), "condition: (volume >= (flo_xt)0.0) && ((volume <= (flo_xt)0.0))"); \
		ic_stv_x3(flo_xt, dis = (flo_xt)sampleRate / frequency, /* 单位周期 */ halfDis = dis / (flo_xt)2.0, phFm = dis * phase); \
		while (bg != ed) { \
			ic_if_do(phFm >= dis, phFm -= dis) \
			ic_if_else_do(phFm < halfDis, *bg = +volume, *bg = -volume) \
			ic_do_x2(phFm += (flo_xt)1.0, ++bg); \
		} \
		return phFm / dis

	ic_core_dcl flo32_t ic_call icGenSquareWaveSampleF32(flo32_t* bg, flo32_t* ed, size_t sampleRate, flo32_t frequency, flo32_t phase, flo32_t volume) ic_noexc {
		icGenSquareWaveSampleF_m(flo32_t);
	}

	ic_core_dcl flo64_t ic_call icGenSquareWaveSampleF64(flo64_t* bg, flo64_t* ed, size_t sampleRate, flo64_t frequency, flo64_t phase, flo64_t volume) ic_noexc {
		icGenSquareWaveSampleF_m(flo64_t);
	}
	#undef icGenSquareWaveSampleF_m
#endif