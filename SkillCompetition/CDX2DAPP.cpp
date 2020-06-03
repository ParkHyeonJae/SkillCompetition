#include "framework.h"

CDX2DAPP* g_pDX2DApp;


CDX2DAPP::CDX2DAPP()
{
	g_pDX2DApp = this;

	m_sCls = L"Direct 2D Project";

	m_hInst = NULL;
	m_hWnd = NULL;
	m_dWinStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE;
	m_dScnX = 768;
	m_dScnY = 600;

	m_bShowCursor = TRUE;

	m_fps = 0;


}

CDX2DAPP::~CDX2DAPP()
{
}

INT CDX2DAPP::Create(HINSTANCE hInst)
{
	m_hInst = hInst;

	WNDCLASS wc = {
		CS_CLASSDC
		, WndProc
		, 0
		, 0
		, m_hInst
		, NULL
		, LoadCursor(NULL, IDC_ARROW)
		, (HBRUSH)GetStockObject(LTGRAY_BRUSH)
		, NULL
		, m_sCls
	};
	
	RegisterClass(&wc);

	RECT rc;

	SetRect(&rc, 0, 0, m_dScnX, m_dScnY);
	AdjustWindowRect(&rc, m_dWinStyle, FALSE);

	int iScnSysW = ::GetSystemMetrics(SM_CXSCREEN);
	int iScnSysH = ::GetSystemMetrics(SM_CYSCREEN);

	m_hWnd = CreateWindow(m_sCls
		, m_sCls
		, m_dWinStyle
		, (iScnSysW - (rc.right - rc.left)) / 2
		, (iScnSysH - (rc.bottom - rc.top)) / 2
		, m_dScnX
		, m_dScnY
		, NULL
		, NULL
		, m_hInst
		, NULL);
	GetWindowRect(m_hWnd, &m_rcWin);

	m_Gfx = new CGraphics();
	m_Gfx->Init(m_hWnd, m_rcWin);

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	Init();

	return 0;
}

INT CDX2DAPP::Run()
{
	MSG msg;
	memset(&msg, 0, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			RenderLoop();
		}

	}

	UnregisterClass(m_sCls, m_hInst);
	return 0;
}

void CDX2DAPP::CleanUp()
{
	delete m_Input;
	delete m_Gfx;
}

INT CDX2DAPP::RenderLoop()
{
	static DWORD dlastTime = timeGetTime();
	static DWORD framecount = 0;
	static DWORD TotElapsed = 0;

	DWORD dCurTime = timeGetTime();
	DWORD elapsed = dCurTime - dlastTime;
	TotElapsed += elapsed;
	framecount++;
	if (TotElapsed >= 1000)
	{
		m_fps = framecount;
		framecount = 0;
		TotElapsed -= 1000;
	}
	dlastTime = dCurTime;

	HRESULT res = FrameMove(elapsed);

	if (res != S_OK)
		return -1;
	res = Render();
	if (res != S_OK)
		return -1;

	return 0;
}

INT CDX2DAPP::Init()
{
	m_Input = new CInput();
	m_Input->Create(m_hWnd);
	return 0;
}

INT CDX2DAPP::Render()
{
	return 0;
}

INT CDX2DAPP::FrameMove(DWORD elpased)
{
	if (m_Input) m_Input->FrameMove();
	Control(m_Input);
	return 0;
}

INT CDX2DAPP::Control(CInput* Input)
{

	return 0;
}

LRESULT CDX2DAPP::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT:
	{
		break;
	}
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
		{
			SendMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		}
		return 0;
	}
	case WM_DESTROY:
	{
		CleanUp();
		PostQuitMessage(0);
		return 0;
	}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CDX2DAPP::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return g_pDX2DApp->MsgProc(hWnd, msg, wParam, lParam);
	
}
