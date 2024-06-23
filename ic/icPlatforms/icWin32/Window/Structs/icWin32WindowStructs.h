
#pragma once

#include"../../icWin32Headers.h"
#include"../../../../icCore/icCore.h"
#include"../../Common/Types/icWin32CommonTypes.h"

ic_info("declarations")
    ic_dcl_struct(IC_WIN32_WND_MSG_MAP);
    ic_dcl_struct(IC_WIN32_WND_MSG_MAP_INFO);
    ic_dcl_struct(IC_WIN32_WND_REGISTER_A);
    ic_dcl_struct(IC_WIN32_WND_REGISTER_W);
    ic_dcl_struct(IC_WIN32_WND);
    ic_dcl_struct(IC_WIN32_WND_MSG_MAP_INFO_SEG);


ic_info("alias - For Win32 short style")
    ic_alias(WNDMSGMAP,        IC_WIN32_WND_MSG_MAP);
    ic_alias(WNDMSGMAPINFO,    IC_WIN32_WND_MSG_MAP_INFO);
    ic_alias(WNDREGISTERA,     IC_WIN32_WND_REGISTER_A);
    ic_alias(WNDREGISTERW,     IC_WIN32_WND_REGISTER_W);
    ic_alias(WND,              IC_WIN32_WND);
    ic_alias(WNDMSGMAPINFOSEG, IC_WIN32_WND_MSG_MAP_INFO_SEG);

ic_info("definitions")
    struct IC_WIN32_WND_MSG_MAP {
        IC_WIN32_MSG_FUNC* msgFuncs;
        UINT16*            msgMap;
        UINT16             leftMsg;
        UINT16             rightMsg; // [left_msg, right_msg)
    };

    struct IC_WIN32_WND_MSG_MAP_INFO {
        UINT16            msg;  // 0x0000 - 0xFFFF
        IC_WIN32_MSG_FUNC func;
    };

    struct IC_WIN32_WND_REGISTER_A {
        HINSTANCE hInstance;
        LPCSTR    lpszClassName;
    };

    struct IC_WIN32_WND_REGISTER_W {
        HINSTANCE hInstance;
        LPCWSTR   lpszClassName;
    };

    struct IC_WIN32_WND {
        HWND	                    hWnd;
        WNDPROC                     fDefProc;
        const IC_WIN32_WND_MSG_MAP* pSysMsgMap;
        const IC_WIN32_WND_MSG_MAP* pUsrMsgMap;
        const IC_WIN32_WND_MSG_MAP* pAppMsgMap;
        const IC_WIN32_WND_MSG_MAP* pStrMsgMap;
    };

    struct IC_WIN32_WND_MSG_MAP_INFO_SEG {
        const IC_WIN32_WND_MSG_MAP_INFO* pInfos;
        SIZE_T		                     uCount; // 0 - 65536
    };