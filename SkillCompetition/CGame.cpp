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

	srand((unsigned int)time(0));

	m_clock = new Clock(m_Gfx, m_dScnX, m_dScnY);

	m_clock->Init();
	return 0;
}

INT CGame::Render()
{
	m_Gfx->BeginDraw();
	m_Gfx->ClearScreen(0.0f, 0.0f, 0.0f);
	
	m_clock->Render();

	m_Gfx->EndDraw();
	return 0;
}

INT CGame::FrameMove(DWORD elpased)
{
	CDX2DAPP::FrameMove(elpased);

	m_clock->Update();

	return 0;
}

void CGame::Destroy()
{
	if (m_clock != NULL)
		delete m_clock;
}

INT CGame::Control(CInput* Input)
{
	POINT MousePos = Input->GetMousePos();

	//float rotdegree = atan2f(m_PlayerPos.y - MousePos.y, m_PlayerPos.x - MousePos.x);
	//
	//m_rot = (rotdegree * (180 / PI)) - 90;

	//
	////printf("%f\n", m_rot);

	//if (Input->KeyPress(VK_LEFT))
	//	m_PlayerPos.x -= 10;
	//if (Input->KeyPress(VK_RIGHT))
	//	m_PlayerPos.x += 10;
	//if (Input->KeyPress(VK_UP))
	//	m_PlayerPos.y -= 10;
	//if (Input->KeyPress(VK_DOWN))
	//	m_PlayerPos.y += 10;


	//if (Input->BtnDown(0) || Input->BtnPress(0))
	//{
	//	m_PlayerScale.x += 0.1f;
	//	m_PlayerScale.y += 0.1f;
	//}
	//if (Input->BtnDown(1) || Input->BtnPress(1))
	//{
	//	m_PlayerScale.x -= 0.1f;
	//	m_PlayerScale.y -= 0.1f;
	//}



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
