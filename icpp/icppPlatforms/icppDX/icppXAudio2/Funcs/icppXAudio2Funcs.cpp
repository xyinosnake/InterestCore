#ifndef ICPP_XAUDIO2_FUNCS
#define ICPP_XAUDIO2_FUNCS

#include"./icppXAudio2Funcs.h"

ic_info("definitions")
    icpp_xaudio2_dcl void ic_call icppXAudio2CheckDestroyVoiceSetNull(IXAudio2Voice*& pRefVoice) ic_noexc {
        IXAudio2Voice* pVoice = pRefVoice;
        ic_if_do_x2(pVoice, pVoice->DestroyVoice(), pRefVoice = NULL);
    }

    icpp_xaudio2_dcl void ic_call icppXAudio2Gen_XAUDIO2_BUFFER(
        XAUDIO2_BUFFER* pBuffer,
        cvoid_p         WavBg,
        size_t          WavBtLen,
        UINT32          Flags,
        size_t          PlayBegin,
        size_t          PlayLength,
        size_t          LoopBegin,
        size_t          LoopLength,
        size_t          LoopCount,
        void_p          pContext
    ) ic_noexc {
            pBuffer->Flags      = Flags;
            pBuffer->AudioBytes = (size_t)WavBtLen;
            pBuffer->pAudioData = (BYTE*)WavBg;
            pBuffer->PlayBegin  = (size_t)PlayBegin;
            pBuffer->PlayLength = (size_t)PlayLength;
            pBuffer->LoopBegin  = (size_t)LoopBegin;
            pBuffer->LoopLength = (size_t)LoopLength;
            pBuffer->LoopCount  = (size_t)LoopCount;
            pBuffer->pContext   = pContext;
        /*
        XAudio2Buffer.Flags      = 0;			可以设为0或XAUDIO2_END_OF_STREAM，当设为后者时，
                                                将使XAudio2播放完该数据块后自动停止，不再播放下一个数据块
        XAudio2Buffer.AudioBytes = BufferSize;  音频数据的长度，按字节算
        XAudio2Buffer.pAudioData = pBuffer;		具体音频数据的地址，unsigned char pBuffer[]
        XAudio2Buffer.PlayBegin  = 0;			起始播放地址
        XAudio2Buffer.PlayLength = 0;			播放长度，0为整数据块
        XAudio2Buffer.LoopBegin  = 0;			循环起始位置
        XAudio2Buffer.LoopLength = 0;			循环长度，按字节算
        XAudio2Buffer.LoopCount  = 0;			循环次数，0为不循环，255为无限循环
        XAudio2Buffer.pContext   = NULL;		这里的pContext用来标识该数据块，供回调用，可以是NULL
        */
    }

    icpp_xaudio2_dcl HRESULT ic_call icppXAudio2PlayBuffer(
        IXAudio2SourceVoice* sv, 
	    cvoid_p              Data, 
	    UINT32               DataBtLen
    ) ic_noexc {
        HRESULT		   r;
        XAUDIO2_BUFFER buf;
        icppXAudio2Gen_XAUDIO2_BUFFER(&buf, Data, DataBtLen, 0, 0, 0, 0, 0, 0, NULL);
        ic_if_goto(FAILED(r), posEnd);
        r = sv->SubmitSourceBuffer(&buf);
        ic_if_goto(FAILED(r), posEnd);
        r = sv->Start();
    posEnd:
        return r;
    }

    icpp_xaudio2_dcl HRESULT ic_call icppXAudio2PlayBufferEx(
        IXAudio2SourceVoice* sv, 
	    cvoid_p              Data, 
	    UINT32               DataBtLen,
        FLOAT                TotalVolume,
        cflo32_p             pVolumesEachChannel,
        UINT32               nChannelsCount
    ) ic_noexc {
        HRESULT		   r;
        XAUDIO2_BUFFER buf;
        icppXAudio2Gen_XAUDIO2_BUFFER(&buf, Data, DataBtLen, 0, 0, 0, 0, 0, 0, NULL);
        r = sv->SetVolume(TotalVolume);
        ic_if_goto(FAILED(r), posEnd);
        ic_if_do_x2(pVolumesEachChannel,
            r = sv->SetChannelVolumes(nChannelsCount, pVolumesEachChannel, 0),
            ic_if_goto(FAILED(r), posEnd));
        r = sv->SubmitSourceBuffer(&buf);
        ic_if_goto(FAILED(r), posEnd);
        r = sv->Start();
    posEnd:
        return r;
    }

    icpp_xaudio2_dcl HRESULT ic_call icppXAudio2CreateSourceVoiceToSubmixVoice(
        IXAudio2SourceVoice**       ppXAudio2SourceVoice, 
        IXAudio2*			        pXAudio2,
        IXAudio2SubmixVoice*        pXAudio2SubmixVoice,
        const WAVEFORMATEX*         pSourceFormat,
        UINT32                      Flags,
        float                       MaxFrequencyRatio,
        IXAudio2VoiceCallback*      pCallback,
        const XAUDIO2_EFFECT_CHAIN* pEffectChain
    ) ic_noexc {
        XAUDIO2_SEND_DESCRIPTOR SFXSend     = { 0, pXAudio2SubmixVoice };
        XAUDIO2_VOICE_SENDS     SFXSendList = { 1, &SFXSend };
        return pXAudio2->CreateSourceVoice(ppXAudio2SourceVoice, pSourceFormat,
            Flags, MaxFrequencyRatio, pCallback, &SFXSendList, pEffectChain);
    }
#endif