
#pragma once

#include"../icppXAudio2Headers.h"
#include"../Macros/icppXAudio2Macros.h"

ic_info("declarations")
    ic_inl HRESULT ic_call icppXAudio2Create(
        IXAudio2**        ppXAudio2,
        UINT32            Flags            ic_dfv(0), 
        XAUDIO2_PROCESSOR XAudio2Processor ic_dfv(XAUDIO2_USE_DEFAULT_PROCESSOR)
    ) ic_noexc;
    ic_inl HRESULT ic_call icppXAudio2CreateMasteringVoice(IXAudio2MasteringVoice** ppMV, IXAudio2* pXAudio2, 
        UINT32                      InputChannels   ic_dfv(XAUDIO2_DEFAULT_CHANNELS),
        UINT32                      InputSampleRate ic_dfv(XAUDIO2_DEFAULT_SAMPLERATE),
        UINT32                      Flags           ic_dfv(0), 
        LPCWSTR                     szDeviceId      ic_dfv(NULL), 
        const XAUDIO2_EFFECT_CHAIN* pEffectChain    ic_dfv(NULL), 
        AUDIO_STREAM_CATEGORY       StreamCategory  ic_dfv(AudioCategory_GameEffects)
    ) ic_noexc;
    
    ic_inl           void ic_call icppXAudio2CheckDestroyVoice(IXAudio2Voice* pVoice) ic_noexc;
    icpp_xaudio2_dcl void ic_call icppXAudio2CheckDestroyVoiceSetNull(IXAudio2Voice*& pRefVoice) ic_noexc;
    icpp_xaudio2_dcl void ic_call icppXAudio2Gen_XAUDIO2_BUFFER(
        XAUDIO2_BUFFER* pBuffer,
        cvoid_p         WavBg,
        size_t          WavBtLen,			  //字节长度
        UINT32          Flags	   ic_dfv(0), //EndOfStream ? XAUDIO2_END_OF_STREAM : 0
        size_t          PlayBegin  ic_dfv(0),
        size_t          PlayLength ic_dfv(0),
        size_t          LoopBegin  ic_dfv(0),
        size_t          LoopLength ic_dfv(0),
        size_t          LoopCount  ic_dfv(0),
        void*           pContext   ic_dfv(NULL)
    ) ic_noexc;

    icpp_xaudio2_dcl HRESULT ic_call icppXAudio2PlayBuffer(
        IXAudio2SourceVoice* sv, 
	    cvoid_p              Data, 
	    UINT32               DataBtLen
    ) ic_noexc;

    icpp_xaudio2_dcl HRESULT ic_call icppXAudio2PlayBufferEx(
	    IXAudio2SourceVoice* sv, 
	    cvoid_p              Data, 
	    UINT32               DataBtLen,
	    FLOAT                TotalVolume		 ic_dfv(1.0f),
	    cflo32_p             pVolumesEachChannel ic_dfv(NULL),
	    UINT32               nChannelsCount	     ic_dfv(0)
    ) ic_noexc;

    icpp_xaudio2_dcl HRESULT ic_call icppXAudio2CreateSourceVoiceToSubmixVoice(
	    IXAudio2SourceVoice**       ppXAudio2SourceVoice, 
	    IXAudio2*			        pXAudio2,
	    IXAudio2SubmixVoice*        pXAudio2SubmixVoice,
	    const WAVEFORMATEX*         pSourceFormat,
		UINT32                      Flags				   ic_dfv(0),
	    float                       MaxFrequencyRatio      ic_dfv(XAUDIO2_DEFAULT_FREQ_RATIO),
		IXAudio2VoiceCallback*      pCallback			   ic_dfv(NULL),
	    const XAUDIO2_EFFECT_CHAIN* pEffectChain		   ic_dfv(NULL)
    ) ic_noexc;

ic_info("inl definitions")
    ic_inl HRESULT ic_call icppXAudio2Create(IXAudio2** ppXAudio2, UINT32 Flags, XAUDIO2_PROCESSOR XAudio2Processor) ic_noexc {
        return XAudio2Create(ppXAudio2, Flags, XAudio2Processor);
    }

    ic_inl HRESULT ic_call icppXAudio2CreateMasteringVoice(IXAudio2MasteringVoice** ppMV, IXAudio2* pXAudio2, UINT32 InputChannels, 
        UINT32 InputSampleRate, UINT32 Flags, LPCWSTR szDeviceId, const XAUDIO2_EFFECT_CHAIN* pEffectChain, AUDIO_STREAM_CATEGORY StreamCategory) ic_noexc {
        return pXAudio2->CreateMasteringVoice(ppMV, InputChannels, InputSampleRate, Flags, szDeviceId, pEffectChain, StreamCategory);
    }

    ic_inl void ic_call icppXAudio2CheckDestroyVoice(IXAudio2Voice* pVoice) ic_noexc {
        ic_if_do(pVoice, pVoice->DestroyVoice());
    }