
#pragma once

#include"../Macros/icppDInputMacros.h"
#include"../Structs/icppDInputStructs.h"
#include"../icppDInputHeaders.h"

ic_info("declarations")
    icpp_dinput_dcl HRESULT ic_call icppDInputCreate(IDirectInput8W** ppDI, HINSTANCE hIns ic_dfv(NULL)) ic_noexc;
    icpp_dinput_dcl HRESULT ic_call icppDInputCreateDevice(
        IDirectInputDevice8W** ppDev,
        IDirectInput8W*        pDI,
        HWND                   hWnd,
        REFGUID                RefGuid,
        const DIDATAFORMAT*    pFormat,
        DWORD                  dwLevel  ic_dfv(ICPP_DINPUT_COOPERATIVE_LEVEL_0),
        BOOL                   bAcquire ic_dfv(TRUE)
    ) ic_noexc;

    icpp_dinput_dcl HRESULT ic_call icppDInputCreateKeyboard(IDirectInputDevice8W** ppKeyboard, IDirectInput8W* pDI, HWND hWnd, DWORD dwLevel ic_dfv(ICPP_DINPUT_COOPERATIVE_LEVEL_0)) ic_noexc;
    icpp_dinput_dcl HRESULT ic_call icppDInputCreateMouse   (IDirectInputDevice8W** ppMouse,    IDirectInput8W* pDI, HWND hWnd, DWORD dwLevel ic_dfv(ICPP_DINPUT_COOPERATIVE_LEVEL_0)) ic_noexc;
    ic_inl HRESULT ic_call icppDInputFlushDeviceStates(IDirectInputDevice8W* pDev, void* pStates, DWORD btSzOfStates) ic_noexc;
    ic_inl HRESULT ic_call icppDInputFlushKeyboardStates(IDirectInputDevice8W* pKeyboard, ICPP_DINPUT_KEYBOARD_STATES* pStates) ic_noexc;
    ic_inl HRESULT ic_call icppDInputFlushMouseStates(IDirectInputDevice8W* pMouse, DIMOUSESTATE* pStates) ic_noexc;
    ic_inl HRESULT ic_call icppDInputFlushMouseStates2(IDirectInputDevice8W* pMouse, DIMOUSESTATE2* pStates2) ic_noexc;

ic_info("declarations inl")
    ic_inl POINT ic_call icppDInputComputeMousePosition(POINT oldPos, LONG lX, LONG lY) ic_noexc;

ic_info("definitions inl")
    ic_inl POINT ic_call icppDInputComputeMousePosition(POINT oldPos, LONG lX, LONG lY) ic_noexc {
        oldPos.x += lX;
        oldPos.y += lY;
        return oldPos;
    }

    ic_inl HRESULT ic_call icppDInputFlushDeviceStates(IDirectInputDevice8W* pDev, void* pStates, DWORD btSzOfStates) ic_noexc {
        return pDev->GetDeviceState(btSzOfStates, pStates);
    }

    ic_inl HRESULT ic_call icppDInputFlushKeyboardStates(IDirectInputDevice8W* pKeyboard, ICPP_DINPUT_KEYBOARD_STATES* pStates) ic_noexc {
        return icppDInputFlushDeviceStates(pKeyboard, pStates, sizeof(ICPP_DINPUT_KEYBOARD_STATES)); //该函数比GetAsyncKeyState()快10倍（已测试）！
    }

    ic_inl HRESULT ic_call icppDInputFlushMouseStates(IDirectInputDevice8W* pMouse, DIMOUSESTATE* pStates) ic_noexc {
        return icppDInputFlushDeviceStates(pMouse, pStates, sizeof(DIMOUSESTATE));
    }

    ic_inl HRESULT ic_call icppDInputFlushMouseStates2(IDirectInputDevice8W* pMouse, DIMOUSESTATE2* pStates2) ic_noexc {
        return icppDInputFlushDeviceStates(pMouse, pStates2, sizeof(DIMOUSESTATE2));
    }