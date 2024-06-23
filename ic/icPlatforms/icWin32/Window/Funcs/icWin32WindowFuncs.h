
#pragma once

#include"../../Common/icWin32Common.h"
#include"../Structs/icWin32WindowStructs.h"
#include"../../../../../ic/ic/Memory/Funcs/icMemoryFuncs.h"

ic_info("declarations")
    ic_win32_dcl BOOL   ic_call icWin32GetClientSize(SIZE* pSz, HWND hWnd) ic_noexc;
    ic_win32_dcl WPARAM ic_call icWin32ShowRunWndW(HWND hWnd, int nCmdShow, UINT wMsgFilterMin ic_dfv(0), UINT wMsgFilterMax ic_dfv(0), HWND hWndMsgFrom ic_dfv(NULL)) ic_noexc;
    ic_win32_dcl WPARAM ic_call icWin32ShowRunWndA(HWND hWnd, int nCmdShow, UINT wMsgFilterMin ic_dfv(0), UINT wMsgFilterMax ic_dfv(0), HWND hWndMsgFrom ic_dfv(NULL)) ic_noexc;
    ic_win32_dcl BOOL   ic_call icWin32GetMinAndMaxMsg(
        uint16_p                         pMinVal,
        uint16_p                         pMaxVal,
        const IC_WIN32_WND_MSG_MAP_INFO* pMsgMapInfo,
        const uint32_t                   uCount
    ) ic_noexc;
    ic_win32_dcl BOOL ic_call icWin32CreateWndMsgMap(
        IC_WIN32_WND_MSG_MAP*            pMsgMap,
        const IC_WIN32_WND_MSG_MAP_INFO* pMsgMapInfo,
        uint32_t                         msgMapInfoCount,
        ic_alloc_f                       allocate ic_dfv(icAlloc)
    ) ic_noexc;
    ic_win32_dcl void ic_call icWin32DestroyWndMsgMap(IC_WIN32_WND_MSG_MAP* pMsgMap, ic_dealloc_f dealloc ic_dfv(icDealloc)) ic_noexc;
    ic_win32_dcl void ic_call icWin32Gen_WNDCLASSEXW(
        WNDCLASSEXW* pWNDCLASS,
        WNDPROC      lpfnWndProc,
        const WCHAR* lpszClassName,
        HINSTANCE    hInstance    ic_dfv(NULL),
        UINT         ClassStyle   ic_dfv(IC_WIN32_CS_DEFAULT),
        HICON        hIcon        ic_dfv(NULL),
        HICON        hIconSm      ic_dfv(NULL),
        HCURSOR      hCursor      ic_dfv(NULL),
        const WCHAR* lpszMenuName ic_dfv(NULL),
        int          cbClsExtra   ic_dfv(0), 
        int          cbWndExtra   ic_dfv(0),
        HBRUSH       hbrBackgroun ic_dfv(NULL)
    ) ic_noexc;

    ic_win32_dcl void ic_call icWin32Gen_WNDCLASSEXA(
        WNDCLASSEXA* pWNDCLASS,
        WNDPROC      lpfnWndProc,
        const CHAR*  lpszClassName,
        HINSTANCE    hInstance    ic_dfv(NULL),
        UINT         ClassStyle   ic_dfv(IC_WIN32_CS_DEFAULT),
        HICON        hIcon        ic_dfv(NULL),
        HICON        hIconSm      ic_dfv(NULL),
        HCURSOR      hCursor      ic_dfv(NULL),
        const CHAR*  lpszMenuName ic_dfv(NULL),
        int          cbClsExtra   ic_dfv(0), 
        int          cbWndExtra   ic_dfv(0),
        HBRUSH       hbrBackgroun ic_dfv(NULL)
    ) ic_noexc;
    ic_win32_dcl ATOM ic_call icWin32RegWndA(
        IC_WIN32_WND_REGISTER_A* lpWndRegister,
        WNDPROC                  lpfnWndProc,
        const CHAR*              lpszClassName,
        HINSTANCE                hInstance     ic_dfv(NULL),
        UINT                     ClassStyle    ic_dfv(IC_WIN32_CS_DEFAULT),
        HICON                    hIcon         ic_dfv(NULL),
        HICON                    hIconSm       ic_dfv(NULL),
        HCURSOR                  hCursor       ic_dfv(NULL),
        const CHAR*              lpszMenuName  ic_dfv(NULL),
        int                      cbClsExtra    ic_dfv(0),
        int                      cbWndExtra    ic_dfv(0),
        HBRUSH                   hbrBackground ic_dfv(NULL)
    ) ic_noexc;
    ic_win32_dcl ATOM ic_call icWin32RegWndW(
        IC_WIN32_WND_REGISTER_W* lpWndRegister,
        WNDPROC                  lpfnWndProc,
        const WCHAR*             lpszClassName,
        HINSTANCE                hInstance     ic_dfv(NULL),
        UINT                     ClassStyle    ic_dfv(IC_WIN32_CS_DEFAULT),
        HICON                    hIcon         ic_dfv(NULL),
        HICON                    hIconSm       ic_dfv(NULL),
        HCURSOR                  hCursor       ic_dfv(NULL),
        const WCHAR*             lpszMenuName  ic_dfv(NULL),
        int                      cbClsExtra    ic_dfv(0),
        int                      cbWndExtra    ic_dfv(0),
        HBRUSH                   hbrBackground ic_dfv(NULL)
    ) ic_noexc;
    ic_win32_dcl BOOL ic_call icWin32UnregWndA(IC_WIN32_WND_REGISTER_A* lpWndRegister) ic_noexc;
    ic_win32_dcl BOOL ic_call icWin32UnregWndW(IC_WIN32_WND_REGISTER_W* lpWndRegister) ic_noexc;
    ic_inl void icWin32InitWnd(IC_WIN32_WND* pWnd,
		const IC_WIN32_WND_MSG_MAP* pSysMsgMap ic_dfv(NULL), 
		const IC_WIN32_WND_MSG_MAP* pUsrMsgMap ic_dfv(NULL), 
		const IC_WIN32_WND_MSG_MAP* pAppMsgMap ic_dfv(NULL), 
		const IC_WIN32_WND_MSG_MAP* pStrMsgMap ic_dfv(NULL)
	) ic_noexc;
    ic_win32_dcl BOOL ic_call icWin32CreateWndA(
        IC_WIN32_WND* pWnd,
        const CHAR*   lpClassName,
        const CHAR*   lpWindowTitle ic_dfv(NULL),
        HINSTANCE     hInstance     ic_dfv(NULL),
        DWORD         dwStyle       ic_dfv(IC_WIN32_WS_DEFAULT),
        DWORD         dwExStyle     ic_dfv(0),
        POINT         ptPos         ic_dfv(POINT { CW_USEDEFAULT, CW_USEDEFAULT }),
        SIZE          WindowSize    ic_dfv(SIZE  { CW_USEDEFAULT, CW_USEDEFAULT }),
        HWND          hWndParent    ic_dfv(NULL),
        HMENU         hMenu         ic_dfv(NULL),
        WNDPROC       defProc       ic_dfv(DefWindowProcA)
    ) ic_noexc;
    ic_win32_dcl BOOL ic_call icWin32CreateWndW(
        IC_WIN32_WND* pWnd,
        const WCHAR*  lpClassName,
        const WCHAR*  lpWindowTitle ic_dfv(NULL),
        HINSTANCE     hInstance     ic_dfv(NULL),
        DWORD         dwStyle       ic_dfv(IC_WIN32_WS_DEFAULT),
        DWORD         dwExStyle     ic_dfv(0),
        POINT         ptPos         ic_dfv(POINT { CW_USEDEFAULT, CW_USEDEFAULT }),
        SIZE          WindowSize    ic_dfv(SIZE  { CW_USEDEFAULT, CW_USEDEFAULT }),
        HWND          hWndParent    ic_dfv(NULL),
        HMENU         hMenu         ic_dfv(NULL),
        WNDPROC       defProc       ic_dfv(DefWindowProcW)
    ) ic_noexc;
    ic_inl HWND ic_call icWin32CreateHWNDA(
        const CHAR* lpClassName,
        const CHAR* lpWindowTitle  ic_dfv(NULL),
        HINSTANCE   hInstance      ic_dfv(NULL),
        DWORD       dwStyle        ic_dfv(IC_WIN32_WS_DEFAULT),
        DWORD       dwExStyle      ic_dfv(0),
        POINT       ptPos          ic_dfv(POINT { CW_USEDEFAULT, CW_USEDEFAULT }),
        SIZE        WindowSize     ic_dfv(SIZE  { CW_USEDEFAULT, CW_USEDEFAULT }),
        HWND        hWndParent     ic_dfv(NULL),
        HMENU       hMenu          ic_dfv(NULL),
        LPVOID      lpParam        ic_dfv(NULL)
    ) ic_noexc;
    ic_inl HWND ic_call icWin32CreateHWNDW(
        const WCHAR* lpClassName,
        const WCHAR* lpWindowTitle ic_dfv(NULL),
        HINSTANCE    hInstance     ic_dfv(NULL),
        DWORD        dwStyle       ic_dfv(IC_WIN32_WS_DEFAULT),
        DWORD        dwExStyle     ic_dfv(0),
        POINT        ptPos         ic_dfv(POINT { CW_USEDEFAULT, CW_USEDEFAULT }),
        SIZE         WindowSize    ic_dfv(SIZE  { CW_USEDEFAULT, CW_USEDEFAULT }),
        HWND         hWndParent    ic_dfv(NULL),
        HMENU        hMenu         ic_dfv(NULL),
        LPVOID       lpParam       ic_dfv(NULL)
    ) ic_noexc;
    ic_win32_dcl LRESULT CALLBACK icWin32WndFuncA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) ic_noexc;
    ic_win32_dcl LRESULT CALLBACK icWin32WndFuncW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) ic_noexc;

ic_info("inl")
    ic_inl void icWin32InitWnd(IC_WIN32_WND* pWnd, 
		const IC_WIN32_WND_MSG_MAP* pSysMsgMap, 
		const IC_WIN32_WND_MSG_MAP* pUsrMsgMap, 
		const IC_WIN32_WND_MSG_MAP* pAppMsgMap, 
		const IC_WIN32_WND_MSG_MAP* pStrMsgMap) ic_noexc {
		pWnd->hWnd       = NULL;
		pWnd->fDefProc   = NULL;
        pWnd->pSysMsgMap = pSysMsgMap;
        pWnd->pUsrMsgMap = pUsrMsgMap;
        pWnd->pAppMsgMap = pAppMsgMap;
        pWnd->pStrMsgMap = pStrMsgMap;
	};
    #define icWin32CreateHWND_m(CreateWindowEx_xf)\
        return CreateWindowEx_xf( \
            dwExStyle, lpClassName, lpWindowTitle, dwStyle, \
            ptPos.x, ptPos.y, WindowSize.cx, WindowSize.cy, hWndParent, hMenu, \
            hInstance, lpParam)
    ic_inl HWND ic_call icWin32CreateHWNDA(
        const CHAR* lpClassName,
        const CHAR* lpWindowTitle,
        HINSTANCE   hInstance,
        DWORD       dwStyle,
        DWORD       dwExStyle,
        POINT       ptPos,
        SIZE        WindowSize,
        HWND        hWndParent,
        HMENU       hMenu,
        LPVOID      lpParam
    ) ic_noexc {
        icWin32CreateHWND_m(CreateWindowExA);
    }

    ic_inl HWND ic_call icWin32CreateHWNDW(
        const WCHAR* lpClassName,
        const WCHAR* lpWindowTitle,
        HINSTANCE    hInstance,
        DWORD        dwStyle,
        DWORD        dwExStyle,
        POINT        ptPos,
        SIZE         WindowSize,
        HWND         hWndParent,
        HMENU        hMenu,
        LPVOID       lpParam
    ) ic_noexc {
        icWin32CreateHWND_m(CreateWindowExW);
    }
    #undef icWin32CreateHWND_m
