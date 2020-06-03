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

	m_sprite = new CSprite(L"./Images/rocket.png", m_Gfx);
	m_PlayerPos = { (float)(m_dScnX / 2),(float)(m_dScnY / 2) };
	m_rot = 0.0f;
	m_PlayerScale = { 1.0f,1.0f };
	return 0;
}

INT CGame::Render()
{
	m_Gfx->BeginDraw();
	m_Gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	D2D1_POINT_2F center;
	center.x = m_PlayerPos.x + (m_sprite->GetSize().width / 2);
	center.y = m_PlayerPos.y + (m_sprite->GetSize().height / 2);
	m_sprite->Draw(m_PlayerPos, &center, D2D1::Point2F(m_PlayerScale.x, m_PlayerScale.y), m_rot);

	m_Gfx->EndDraw();
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
	POINT MousePos = Input->GetMousePos();

	float rotdegree = atan2f(m_PlayerPos.y - MousePos.y, m_PlayerPos.x - MousePos.x);
	
	m_rot = (rotdegree * (180 / PI)) - 90;
	//printf("%f\n", m_rot);

	if (Input->KeyPress(VK_LEFT) && m_PlayerPos.x > 0)
		m_PlayerPos.x -= 10;
	if (Input->KeyPress(VK_RIGHT) && m_PlayerPos.x< (m_dScnX - m_sprite->GetSize().width))
		m_PlayerPos.x += 10;
	if (Input->KeyPress(VK_UP) && m_PlayerPos.y > 0)
		m_PlayerPos.y -= 10;
	if (Input->KeyPress(VK_DOWN) && m_PlayerPos.y< (m_dScnY - m_sprite->GetSize().height))
		m_PlayerPos.y += 10;


	if (Input->BtnDown(0) || Input->BtnPress(0))
	{
		m_PlayerScale.x += 0.1f;
		m_PlayerScale.y += 0.1f;
	}
	if (Input->BtnDown(1) || Input->BtnPress(1))
	{
		m_PlayerScale.x -= 0.1f;
		m_PlayerScale.y -= 0.1f;
	}
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
