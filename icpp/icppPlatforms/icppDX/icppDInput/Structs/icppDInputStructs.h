
#pragma once

#include"../Macros/icppDInputMacros.h"
#include"../Enums/icppDInputEnums.h"

ic_info("declarations")
    ic_dcl_struct(ICPP_DINPUT_KEYBOARD_STATES);

ic_info("definitions")
    struct ICPP_DINPUT_KEYBOARD_STATES {
        BYTE states[256];
    };

    ic_inl BYTE ic_call icppDInputGetKeyboardState(ICPP_DINPUT_KEYBOARD_STATES* pStates, icpp_dik_e e) ic_noexc {
        return pStates->states[e];
    }