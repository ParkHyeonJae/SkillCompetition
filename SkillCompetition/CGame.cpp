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

	m_theta = 0.0f;
	m_clockCenterPoint= { (float)(m_dScnX / 2),(float)(m_dScnY / 2) };
	m_clockEndPoint = { 0,0 };



	//m_sprite = new CSprite(L"../Images/rocket.png", m_Gfx);

	/*m_PlayerPos = { (float)(m_dScnX / 2),(float)(m_dScnY / 2) };
	m_rot = 0.0f;
	m_PlayerScale = { 1.0f,1.0f };
	m_playerCenter.x = m_PlayerPos.x + (m_sprite->GetSize().width / 2);
	m_playerCenter.y = m_PlayerPos.y + (m_sprite->GetSize().height / 2);
	m_rtPlayerBox = { (LONG)m_playerCenter.x - 120, (LONG)m_playerCenter.y - 120, (LONG)m_playerCenter.x + 120, (LONG)m_playerCenter.y + 120 };
	m_bIsCrash = FALSE;
	m_bIsCircleCrash = FALSE;

	LONG RandX = (LONG)(rand() % m_dScnX + 1);
	LONG RandY = (LONG)(rand() % m_dScnY + 1);
	m_rtTargetBox = { RandX, RandY, RandX + (LONG)(rand() % (m_dScnX - RandX) + 1), RandY + (LONG)(rand() % (m_dScnY - RandY) + 1)};

	LONG RandX1 = (LONG)(rand() % m_dScnX + 1);
	LONG RandY1 = (LONG)(rand() % m_dScnY + 1);
	m_rtTargetBox2 = { RandX1, RandY1, RandX1 + (LONG)(rand() % (m_dScnX - RandX1) + 1), RandY1 + (LONG)(rand() % (m_dScnY - RandY1) + 1) };


	m_TargetCircle = { (LONG)(rand() % m_dScnX + 1) , (LONG)(rand() % m_dScnY + 1) };
	radius = rand() % (m_dScnX - m_dScnY);


	m_TargetCircle2 = { (LONG)(rand() % m_dScnX + 1) , (LONG)(rand() % m_dScnY + 1) };
	radius2 = rand() % (m_dScnX - m_dScnY);

	m_bOnceGeometry[0] = TRUE;
	m_bOnceGeometry[1] = TRUE;*/
	
	return 0;
}

INT CGame::Render()
{
	m_Gfx->BeginDraw();
	m_Gfx->ClearScreen(0.0f, 0.0f, 0.5f);

	m_Gfx->DrawCircle(m_clockCenterPoint.x, m_clockCenterPoint.y, 300.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	float xPos = cosf(m_theta) * 300;
	float yPos = sinf(m_theta) * 300;
	m_Gfx->DrawLine(m_clockCenterPoint.x, m_clockCenterPoint.y, m_clockCenterPoint.x + xPos, m_clockCenterPoint.y + yPos, 5, 1.0f, 1.0, 1.0f, 1.0f);


	//m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());

	//

	//m_sprite->Draw(m_PlayerPos, &m_playerCenter, D2D1::Point2F(m_PlayerScale.x, m_PlayerScale.y), m_rot);
	//m_Gfx->DrawTextOut(L"20106 박현재", D2D1::Point2F(m_PlayerPos.x - 50, m_PlayerPos.y - 30));

	//m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	////m_Gfx->DrawRectangle((float)m_rtPlayerBox.left, (float)m_rtPlayerBox.top, (float)m_rtPlayerBox.right, (float)m_rtPlayerBox.bottom, 1.0f, 1.0f, 1.0f, 1.0f);
	//m_Gfx->DrawRectangle((float)m_rtTargetBox.left, (float)m_rtTargetBox.top, (float)m_rtTargetBox.right, (float)m_rtTargetBox.bottom, 1.0f, 1.0f, 1.0f, 1.0f);
	//m_Gfx->DrawCircle((float)m_TargetCircle.x, (float)m_TargetCircle.y, radius, 1.0f, 1.0f, 1.0f, 1.0f);

	//if (m_bOnceGeometry[0])
	//{
	//	m_Gfx->DrawRectangle((float)m_rtTargetBox2.left, (float)m_rtTargetBox2.top, (float)m_rtTargetBox2.right, (float)m_rtTargetBox2.bottom, 1.0f, 1.0f, 1.0f, 1.0f);
	//	
	//}
	//if (m_bOnceGeometry[1])
	//{
	//	m_Gfx->DrawCircle((float)m_TargetCircle2.x, (float)m_TargetCircle2.y, radius2, 1.0f, 1.0f, 1.0f, 1.0f);

	//}
	//
	//m_Gfx->DrawTextOut(L"이동: 방향키\n 회전: 마우스 방향\n 확대/축소: 마우스 좌/우 클릭", D2D1::Point2F());


	m_Gfx->EndDraw();
	return 0;
}

INT CGame::FrameMove(DWORD elpased)
{
	CDX2DAPP::FrameMove(elpased);

	if (m_theta <= 360.0f)
		m_theta += 0.1f;
	else m_theta = 0.0f;


	/*m_playerCenter.x = m_PlayerPos.x + (m_sprite->GetSize().width / 2);
	m_playerCenter.y = m_PlayerPos.y + (m_sprite->GetSize().height / 2);
	m_rtPlayerBox = { (LONG)m_playerCenter.x - 120,
		(LONG)m_playerCenter.y - 120,
		(LONG)m_playerCenter.x + 120,
		(LONG)m_playerCenter.y + 120 };
	if (IsRectInRect(m_rtTargetBox, m_rtPlayerBox)) {
		m_bIsCrash = TRUE;
	}
	
	if (m_bIsCrash) {
		LONG RandX = (LONG)(rand() % m_dScnX);
		LONG RandY = (LONG)(rand() % m_dScnY);
		m_rtTargetBox = { RandX, RandY, RandX + (LONG)(rand() % (m_dScnX - RandX) + 1), RandY + (LONG)(rand() % (m_dScnY - RandY) + 1) };
		m_bIsCrash = FALSE;
	}

	if (IsRectInCircle(m_TargetCircle, radius, m_rtPlayerBox)){
		m_bIsCircleCrash = TRUE;
	}
	if (m_bIsCircleCrash)
	{
		m_TargetCircle = { (LONG)(rand() % m_dScnX + 1) , (LONG)(rand() % m_dScnY + 1) };
		radius = rand() % (m_dScnX - m_dScnY) + 1;
		m_bIsCircleCrash = FALSE;
	}

	if (IsRectInRect(m_rtTargetBox2, m_rtPlayerBox)) {
		m_bOnceGeometry[0] = FALSE;
	}
	if (IsRectInCircle(m_TargetCircle2, radius2, m_rtPlayerBox)) {
		m_bOnceGeometry[1] = FALSE;
	}*/
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
