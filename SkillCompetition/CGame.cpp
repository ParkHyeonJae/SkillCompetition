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

	m_circleCenter = { (float)(m_dScnX / 2),(float)(m_dScnY / 2) };

	m_secondPoint = { 0,0 };
	m_minuatePoint = { 0,0 };
	m_hourPoint = { 0,0 };

	radian = PI / 180.0f;

	m_clockspirte = new CSprite(L"../Images/clock_background.png", m_Gfx, 583, 830);

	return 0;
}

INT CGame::Render()
{
	m_Gfx->BeginDraw();
	m_Gfx->ClearScreen(0.0f, 0.0f, 0.0f);

	m_clockspirte->Draw(D2D1::Point2F(87.5f,-50));

	m_Gfx->DrawCircle(m_circleCenter.x, m_circleCenter.y, 255, 1.0f, 1.0f, 1.0f, 1.0f);

	m_secondPoint.x = cosf(m_secondTheta * radian)  * 150.0f;
	m_secondPoint.y = sinf(m_secondTheta * radian)  * 150.0f;

	m_minuatePoint.x = cosf(m_minuateTheta * radian) * 100.0f;
	m_minuatePoint.y = sinf(m_minuateTheta * radian) * 100.0f;

	m_hourPoint.x = cosf(m_hourTheta * radian) * 50.0f;
	m_hourPoint.y = sinf(m_hourTheta * radian) * 50.0f;

	m_Gfx->DrawLine(m_circleCenter.x, m_circleCenter.y,
		m_circleCenter.x + m_secondPoint.x, m_circleCenter.y + m_secondPoint.y, 3, 1.0f, 0.0f, 0.0f, 1.0f);

	m_Gfx->DrawLine(m_circleCenter.x, m_circleCenter.y,
		m_circleCenter.x + m_minuatePoint.x, m_circleCenter.y + m_minuatePoint.y, 4, 0.0f, 1.0f,0.0f, 1.0f);

	m_Gfx->DrawLine(m_circleCenter.x, m_circleCenter.y,
		m_circleCenter.x + m_hourPoint.x, m_circleCenter.y + m_hourPoint.y, 6, 0.0f, 0.0f, 0.0f, 1.0f);

	m_Gfx->DrawPoint(m_circleCenter.x, m_circleCenter.y,5.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	m_Gfx->EndDraw();
	return 0;
}

INT CGame::FrameMove(DWORD elpased)
{
	CDX2DAPP::FrameMove(elpased);

	GetLocalTime(&st);


	m_secondTheta = ((st.wSecond * 6) - 90);
	m_minuateTheta = ((st.wMinute * 6) - 90);
	m_hourTheta = ((st.wHour * 30) - 90);

	return 0;
}

void CGame::Destroy()
{
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
