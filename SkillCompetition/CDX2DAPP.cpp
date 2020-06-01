#include "framework.h"

CDX2DAPP* g_pDX2DApp;


CDX2DAPP::CDX2DAPP()
{
	g_pDX2DApp = this;

	m_sCls = L"기능 경기대회 준비 프로젝트";


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

	return 0;
}

INT CDX2DAPP::Run()
{
	return 0;
}

void CDX2DAPP::CleanUp()
{
}

INT CDX2DAPP::RenderLoop()
{
	return 0;
}

INT CDX2DAPP::Init()
{
	return 0;
}

INT CDX2DAPP::Render()
{
	return 0;
}

INT CDX2DAPP::FrameMove(DWORD elpased)
{
	return 0;
}

LRESULT CDX2DAPP::MsgProc(HWND, UINT, WPARAM, LPARAM)
{
	return LRESULT();
}

LRESULT __stdcall CDX2DAPP::WndProc(HWND, UINT, WPARAM, LPARAM)
{
	return LRESULT();
}
