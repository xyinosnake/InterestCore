#ifndef ICPP_DINPUT_FUNCS
#define ICPP_DINPUT_FUNCS

#include"./icppDInputFuncs.h"

/*
说明：
    复合函数。

    RefGuid：
        GUID_SysKeyboard;
        GUID_SysMouse;

    DIDATAFORMAT：
        c_dfDIKeyboard
        c_dfDIMouse
        c_dfDIMouse2
*/

ic_info("definitions")
    icpp_dinput_dcl HRESULT ic_call icppDInputCreate(IDirectInput8W** ppDI, HINSTANCE hIns) ic_noexc {
        ic_if_do(hIns == NULL, hIns = GetModuleHandleW(NULL)); //获取默认实例句柄
        return DirectInput8Create(hIns, DIRECTINPUT_VERSION, IID_IDirectInput8W, (void**)ppDI, NULL);
    }

    icpp_dinput_dcl HRESULT ic_call icppDInputCreateDevice(
        IDirectInputDevice8W** ppDev,
        IDirectInput8W*        pDI,
        HWND                   hWnd,
        REFGUID                RefGuid,
        const DIDATAFORMAT*    pFormat,
        DWORD                  dwLevel,
        BOOL                   bAcquire
    ) ic_noexc {
        IDirectInputDevice8W* pDev;
        HRESULT r = pDI->CreateDevice(RefGuid, &pDev, NULL);
        *ppDev = pDev;
        ic_if_goto(FAILED(r), End);
        r = pDev->SetDataFormat(pFormat);
        ic_if_goto(FAILED(r), End);
        r = pDev->SetCooperativeLevel(hWnd, dwLevel);
        ic_if_goto(FAILED(r), End);
        ic_if_do(bAcquire, r = pDev->Acquire());
    End:
        return r;
    }

    icpp_dinput_dcl HRESULT ic_call icppDInputCreateKeyboard(IDirectInputDevice8W** ppKeyboard, IDirectInput8W* pDI, HWND hWnd, DWORD dwLevel) ic_noexc {
        return icppDInputCreateDevice(ppKeyboard, pDI, hWnd, GUID_SysKeyboard, &c_dfDIKeyboard, dwLevel, TRUE);
    }

    icpp_dinput_dcl HRESULT ic_call icppDInputCreateMouse(IDirectInputDevice8W** ppMouse, IDirectInput8W* pDI, HWND hWnd, DWORD dwLevel) ic_noexc {
        return icppDInputCreateDevice(ppMouse, pDI, hWnd, GUID_SysMouse, &c_dfDIMouse, dwLevel, TRUE);
    }
#endif