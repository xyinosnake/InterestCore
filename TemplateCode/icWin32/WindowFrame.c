#include<InterestCore/ic/ic/ic.h>

ic_info("dcl")
	void ic_call appCreateWndMsgMap(IC_WIN32_WND_MSG_MAP* pMsgMap) ic_noexc;
	ic_win32_def_msg_f(wmPaint,   hWnd, pData, wPrm, lPrm);
	ic_win32_def_msg_f(wmDestroy, hWnd, pData, wPrm, lPrm);
	ic_win32_def_WinMain(hInstance, szCmdLine, iCmdShow);

ic_info("def")
	ic_win32_def_WinMain(hInstance, szCmdLine, iCmdShow) {
		IC_WIN32_WND_REGISTER_W reg;
		IC_WIN32_WND_MSG_MAP    msgMap;
		IC_WIN32_WND            wnd;
		icInit((ic_init_flags_e)(ic_itf_win32_WinMain_default));
			icWin32InitWnd(&wnd, &msgMap);
			icWin32RegWndW(&reg, icWin32WndFuncW, L"icWin32WindowFrame", hInstance);
				appCreateWndMsgMap(&msgMap);
					icWin32CreateWndW(&wnd, reg.lpszClassName);
					int r = (int)icWin32ShowRunWndW(wnd.hWnd, iCmdShow);
				icWin32DestroyWndMsgMap(&msgMap, icDealloc);
			icWin32UnregWndW(&reg);
		icCoreUninit();
		return r;
	}

	void ic_call appCreateWndMsgMap(IC_WIN32_WND_MSG_MAP* pMsgMap) ic_noexc {
		ic_win32_def_msg_map_infos(msgMapInfos) {
			icWin32RegMsgFunc(WM_PAINT,   wmPaint),
			icWin32RegMsgFunc(WM_DESTROY, wmDestroy)
		};
		icWin32CreateWndMsgMap(pMsgMap, msgMapInfos, icArrayLen(msgMapInfos), icAlloc);
	}

	ic_win32_def_msg_f(wmPaint, hWnd, pData, wPrm, lPrm) {
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);
		FillRect(ps.hdc, &ps.rcPaint, (HBRUSH)GetStockObject(GRAY_BRUSH));
		EndPaint(hWnd, &ps);
		return 0;
	}

	ic_win32_def_msg_f(wmDestroy, hWnd, pData, wPrm, lPrm) {
		PostQuitMessage(0);
		return 0;
	}