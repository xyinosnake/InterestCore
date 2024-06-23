
#ifndef IC_WIN32_WINDOWS_FUNCS
#define IC_WIN32_WINDOWS_FUNCS

#include"./icWin32WindowFuncs.h"

ic_info("definitions")
    ic_win32_dcl BOOL ic_call icWin32GetClientSize(SIZE* pSz, HWND hWnd) ic_noexc {
        RECT rc;
        BOOL b = GetClientRect(hWnd, &rc);
        ic_if_do_x2(b, pSz->cx = rc.right - rc.left, pSz->cy = rc.bottom - rc.top);
        return b;
    }

    #define icWin32ShowRunWnd_m(GetMessage_xf, DispatchMessage_xf) \
        MSG msg; \
        ShowWindow(hWnd, nCmdShow); \
        UpdateWindow(hWnd); \
        ic_while_do_x2(GetMessage_xf(&msg, hWndMsgFrom, wMsgFilterMin, wMsgFilterMax),  \
            TranslateMessage(&msg), DispatchMessage_xf(&msg)); \
        return msg.wParam
    ic_win32_dcl WPARAM ic_call icWin32ShowRunWndW(HWND hWnd, int nCmdShow, UINT wMsgFilterMin, UINT wMsgFilterMax, HWND hWndMsgFrom) ic_noexc {
        icWin32ShowRunWnd_m(GetMessageW, DispatchMessageW);
    }

    ic_win32_dcl WPARAM ic_call icWin32ShowRunWndA(HWND hWnd, int nCmdShow, UINT wMsgFilterMin, UINT wMsgFilterMax, HWND hWndMsgFrom) ic_noexc {
        icWin32ShowRunWnd_m(GetMessageA, DispatchMessageA);
    }
    #undef icWin32ShowRunWnd_m

    ic_win32_dcl BOOL ic_call icWin32GetMinAndMaxMsg(
        uint16_p                         pMinVal,
        uint16_p                         pMaxVal,
        const IC_WIN32_WND_MSG_MAP_INFO* pMsgMapInfo,
        const uint32_t                   uCount
    ) ic_noexc {
        ic_if_return(!pMsgMapInfo || !uCount, FALSE);
        ic_stv_x3(uint16_t, minVal, maxVal, TempVal);
        ic_stv_x2(const IC_WIN32_WND_MSG_MAP_INFO*, it = pMsgMapInfo, ed = pMsgMapInfo + uCount);
        ic_do_x3(TempVal = it->msg, minVal = TempVal, maxVal = TempVal);
        ++it;
        while (it != ed) {
            TempVal = it->msg;
            ic_if_do(TempVal < minVal, minVal = TempVal);
            ic_if_do(TempVal > maxVal, maxVal = TempVal);
            ++it;
        };
        ic_do_x2(*pMinVal = minVal, *pMaxVal = maxVal);
        return TRUE;
    }

    ic_win32_dcl BOOL ic_call icWin32CreateWndMsgMap(
        IC_WIN32_WND_MSG_MAP*            pMsgMap,
        const IC_WIN32_WND_MSG_MAP_INFO* pMsgMapInfo,
        uint32_t                         msgMapInfoCount,
        ic_alloc_f                       allocate
    ) ic_noexc {
        ic_assert(msgMapInfoCount <= 65536, "msgMapInfoCount不能大于65536！");
        uint16_t minVal, maxVal;
        ic_if_do_and_return(!icWin32GetMinAndMaxMsg(&minVal, &maxVal, pMsgMapInfo, msgMapInfoCount),
            ic_do_x4(pMsgMap->leftMsg = 0, pMsgMap->rightMsg = 0, pMsgMap->msgFuncs = NULL, pMsgMap->msgMap = NULL), TRUE);
        pMsgMap->leftMsg   = minVal;
        pMsgMap->rightMsg  = maxVal + 1;
        size_t             btSzOfFuncs  = sizeof(IC_WIN32_MSG_PROC*) * (size_t)msgMapInfoCount;
        size_t             btSzOfMsgMap = sizeof(uint16_t) * (size_t)(maxVal - minVal + 1);
        void*              pData        = allocate(btSzOfFuncs + btSzOfMsgMap); //同时分配指针与映射体
        IC_WIN32_MSG_PROC* newMsgFuncs  = (IC_WIN32_MSG_PROC*)pData; //起始位置为消息函数位置。
        ic_if_do_and_return(!pData, pMsgMap->msgFuncs = newMsgFuncs, FALSE);
        uint16_t* pNewMsgMap = (uint16_t*)icAddPtr(pData, btSzOfFuncs);
        memset(pNewMsgMap, 0xFFFFFFFF, btSzOfMsgMap); //序号默认化。P2D_DEFAULT_MESSAGE_FUNCTION
        uint16_t                         tempVal;
        const IC_WIN32_WND_MSG_MAP_INFO* pTempMsgMapInfo;
        for (uint32_t n = 0; n < msgMapInfoCount; ++n) {
            pTempMsgMapInfo     = pMsgMapInfo + n;
            newMsgFuncs[n]      = pTempMsgMapInfo->func;
            tempVal             = pTempMsgMapInfo->msg - minVal;
            pNewMsgMap[tempVal] = (uint16_t)n;
        }
        ic_do_x2(pMsgMap->msgFuncs = newMsgFuncs, pMsgMap->msgMap = pNewMsgMap);
        return TRUE;
    }

    ic_win32_dcl void ic_call icWin32DestroyWndMsgMap(IC_WIN32_WND_MSG_MAP* pMsgMap, ic_dealloc_f dealloc) ic_noexc {
        dealloc(pMsgMap->msgFuncs);
        pMsgMap->msgFuncs = NULL;
    }

    #define icWin32Gen_WNDCLASSEX_m(char_xt, GetModuleHandle_xf, LoadCursor_xf) \
        ic_if_do(!hInstance, hInstance = GetModuleHandle_xf(NULL)); /* default instance */ \
        ic_if_do(!hCursor,   hCursor   = LoadCursor_xf(NULL, (const char_xt*)IDC_ARROW)); /* default cursor */ \
        pWNDCLASS->cbSize        = sizeof(WNDCLASSEXW); \
        pWNDCLASS->style         = ClassStyle; \
        pWNDCLASS->lpfnWndProc   = lpfnWndProc; \
        pWNDCLASS->cbClsExtra    = cbClsExtra; \
        pWNDCLASS->cbWndExtra    = cbWndExtra; \
        pWNDCLASS->hInstance     = hInstance; \
        pWNDCLASS->hIcon         = hIcon; \
        pWNDCLASS->hIconSm       = hIconSm; \
        pWNDCLASS->hCursor       = hCursor; \
        pWNDCLASS->hbrBackground = hbrBackground; \
        pWNDCLASS->lpszMenuName  = lpszMenuName; \
        pWNDCLASS->lpszClassName = lpszClassName

    ic_win32_dcl void ic_call icWin32Gen_WNDCLASSEXW(
        WNDCLASSEXW* pWNDCLASS,
        WNDPROC      lpfnWndProc,
        const WCHAR* lpszClassName,
        HINSTANCE    hInstance, 
        UINT         ClassStyle,
        HICON        hIcon, 
        HICON        hIconSm,
        HCURSOR      hCursor,
        const WCHAR* lpszMenuName,
        int          cbClsExtra, 
        int          cbWndExtra,
        HBRUSH       hbrBackground
    ) ic_noexc {
        icWin32Gen_WNDCLASSEX_m(WCHAR, GetModuleHandleW, LoadCursorW);
    }

    ic_win32_dcl void ic_call icWin32Gen_WNDCLASSEXA(
        WNDCLASSEXA* pWNDCLASS,
        WNDPROC      lpfnWndProc,
        const CHAR*  lpszClassName,
        HINSTANCE    hInstance, 
        UINT         ClassStyle,
        HICON        hIcon, 
        HICON        hIconSm,
        HCURSOR      hCursor,
        const CHAR*  lpszMenuName,
        int          cbClsExtra, 
        int          cbWndExtra,
        HBRUSH       hbrBackground
    ) ic_noexc {
        icWin32Gen_WNDCLASSEX_m(CHAR, GetModuleHandleA, LoadCursorA);
    }
    #undef icWin32Gen_WNDCLASSEX_m
    #define icWin32RegWnd_m(WNDCLASSEX_xt, icWin32Gen_WNDCLASSEX_xf, RegisterClassEx_xf) \
        WNDCLASSEX_xt wnd; \
        icWin32Gen_WNDCLASSEX_xf(&wnd, lpfnWndProc, \
            lpszClassName, hInstance, ClassStyle, hIcon, hIconSm, hCursor, \
            lpszMenuName, cbClsExtra, cbWndExtra, hbrBackground); \
        lpWndRegister->lpszClassName = wnd.lpszClassName; \
        lpWndRegister->hInstance     = wnd.hInstance; \
        return RegisterClassEx_xf(&wnd)

    ic_win32_dcl ATOM ic_call icWin32RegWndA(
        IC_WIN32_WND_REGISTER_A* lpWndRegister,
        WNDPROC                  lpfnWndProc,
        const CHAR*              lpszClassName,
        HINSTANCE                hInstance,
        UINT                     ClassStyle,
        HICON                    hIcon,
        HICON                    hIconSm,
        HCURSOR                  hCursor,
        const CHAR*              lpszMenuName,
        int                      cbClsExtra,
        int                      cbWndExtra,
        HBRUSH                   hbrBackground
    ) ic_noexc {
        icWin32RegWnd_m(WNDCLASSEXA, icWin32Gen_WNDCLASSEXA, RegisterClassExA);
    }

    ic_win32_dcl ATOM ic_call icWin32RegWndW(
        IC_WIN32_WND_REGISTER_W* lpWndRegister,
        WNDPROC                  lpfnWndProc,
        const WCHAR*             lpszClassName,
        HINSTANCE                hInstance,
        UINT                     ClassStyle,
        HICON                    hIcon,
        HICON                    hIconSm,
        HCURSOR                  hCursor,
        const WCHAR*             lpszMenuName,
        int                      cbClsExtra,
        int                      cbWndExtra,
        HBRUSH                   hbrBackground
    ) ic_noexc {
        icWin32RegWnd_m(WNDCLASSEXW, icWin32Gen_WNDCLASSEXW, RegisterClassExW);
    }
    #undef icWin32RegWnd_m
    #define icWin32UnregWnd_m(char_xt, UnregisterClass_xf) \
        const char_xt* className = lpWndRegister->lpszClassName; \
        if (className) { \
            BOOL b = UnregisterClass_xf(className, lpWndRegister->hInstance); \
            ic_if_do_x2(b, lpWndRegister->lpszClassName = NULL, lpWndRegister->hInstance = NULL); \
            return b; \
        } \
        return TRUE
    ic_win32_dcl BOOL ic_call icWin32UnregWndA(IC_WIN32_WND_REGISTER_A* lpWndRegister) ic_noexc {
        icWin32UnregWnd_m(CHAR, UnregisterClassA);
    }

    ic_win32_dcl BOOL ic_call icWin32UnregWndW(IC_WIN32_WND_REGISTER_W* lpWndRegister) ic_noexc {
        icWin32UnregWnd_m(WCHAR, UnregisterClassW);
    }
    #undef icWin32UnregWnd_m
    #define icWin32CreateWnd_m(icWin32CreateHWND_xf) \
        pWnd->fDefProc = defProc; \
        HWND hWnd = icWin32CreateHWND_xf(lpClassName, lpWindowTitle, hInstance, dwStyle, \
                dwExStyle, ptPos, WindowSize, hWndParent, hMenu, pWnd); \
        return hWnd != NULL

    ic_win32_dcl BOOL ic_call icWin32CreateWndA(
        IC_WIN32_WND* pWnd,
        const CHAR*   lpClassName,
        const CHAR*   lpWindowTitle,
        HINSTANCE     hInstance,
        DWORD         dwStyle,
        DWORD         dwExStyle,
        POINT         ptPos,
        SIZE          WindowSize,
        HWND          hWndParent,
        HMENU         hMenu,
        WNDPROC       defProc
    ) ic_noexc {
        icWin32CreateWnd_m(icWin32CreateHWNDA);
    }

    ic_win32_dcl BOOL ic_call icWin32CreateWndW(
        IC_WIN32_WND* pWnd,
        const WCHAR*  lpClassName,
        const WCHAR*  lpWindowTitle,
        HINSTANCE     hInstance,
        DWORD         dwStyle,
        DWORD         dwExStyle,
        POINT         ptPos,
        SIZE          WindowSize,
        HWND          hWndParent,
        HMENU         hMenu,
        WNDPROC       defProc
    ) ic_noexc {
        icWin32CreateWnd_m(icWin32CreateHWNDW);
    }
    #undef icWin32CreateWnd_m

    ic_hide LRESULT ic_call H_icWin32InternalWndFunc(HWND hWnd, const UINT Msg, WPARAM wParam, LPARAM lParam, IC_WIN32_WND* DataPtr) ic_noexc {
        const IC_WIN32_WND_MSG_MAP* pMessageMap;
        ic_stv_x3(uint16_t, leftMsg, rightMsg, number);
             ic_if_do(Msg < WM_USER, pMessageMap = DataPtr->pSysMsgMap)
        else ic_if_do(Msg < WM_APP,  pMessageMap = DataPtr->pUsrMsgMap)
        else ic_if_do(Msg < 0xC000,  pMessageMap = DataPtr->pAppMsgMap)
        else ic_if_do(Msg < 0xFFFF,  pMessageMap = DataPtr->pStrMsgMap)
        ic_else_goto(posDefFunc);
        ic_if_goto(!pMessageMap, posDefFunc);
        leftMsg  = pMessageMap->leftMsg;
        rightMsg = pMessageMap->rightMsg;
        if (icValInItv(Msg, (UINT)leftMsg, (UINT)rightMsg)) {
            number = pMessageMap->msgMap[Msg - leftMsg];
            ic_if_return(number != 0xFFFF, pMessageMap->msgFuncs[number](hWnd, DataPtr, wParam, lParam));
        }
        ic_label_return(posDefFunc, DataPtr->fDefProc(hWnd, Msg, wParam, lParam));
    }
    #define icWin32WndFunc_m(GetWindowLongPtr_xf, CREATESTRUCT_xt, SetWindowLongPtr_xf, DefWindowProc_xf) \
        IC_WIN32_WND* DataPtr = (IC_WIN32_WND*)GetWindowLongPtr_xf(hWnd, GWLP_USERDATA); \
        if (DataPtr) { \
        SysPos: \
            return H_icWin32InternalWndFunc(hWnd, Msg, wParam, lParam, DataPtr); \
        } else { \
            if (Msg == WM_NCCREATE) { \
                DataPtr = (IC_WIN32_WND*)(((CREATESTRUCT_xt*)lParam)->lpCreateParams); \
                ic_assert(DataPtr != NULL,       "DataPtr不能是NULL。"); \
                ic_assert(DataPtr->hWnd == NULL, "发送WM_NCCREATE前，window_handle必须先销毁。"); \
                DataPtr->hWnd = hWnd; \
                SetWindowLongPtr_xf(hWnd, GWLP_USERDATA, (LONG_PTR)DataPtr); \
                goto SysPos; \
            } \
            return DefWindowProc_xf(hWnd, Msg, wParam, lParam); /* 有一个消息会在DataPtr被设置之前发出。 */ \
        }

    ic_win32_dcl LRESULT CALLBACK icWin32WndFuncA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) ic_noexc {
        icWin32WndFunc_m(GetWindowLongPtrA, CREATESTRUCTA, SetWindowLongPtrA, DefWindowProcA);
    }

    ic_win32_dcl LRESULT CALLBACK icWin32WndFuncW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) ic_noexc {
        icWin32WndFunc_m(GetWindowLongPtrW, CREATESTRUCTW, SetWindowLongPtrW, DefWindowProcW);
    }
#endif