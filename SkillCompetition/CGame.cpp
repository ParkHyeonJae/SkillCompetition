#include "framework.h"

CGame::CGame()
{
}

CGame::~CGame()
{
	Destroy();
}

INT CGame::Init()
{
	CDX2DAPP::Init();


	return 0;
}

INT CGame::Render()
{
	
	return 0;
}

INT CGame::FrameMove(DWORD elpased)
{

	CDX2DAPP::FrameMove(elpased);
	return 0;
}

void CGame::Destroy()
{
}

INT CGame::Control(CInput* Input)
{


	return 0;
}

LRESULT CGame::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT:
	{
		break;
	}
	}

	return CDX2DAPP::MsgProc(hWnd, msg, wParam, lParam);
}
