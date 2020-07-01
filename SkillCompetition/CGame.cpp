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
	m_hourTheta = 0.0f;
	m_clockCenterPoint= { (float)(m_dScnX / 2),(float)(m_dScnY / 2) };
	m_clockEndPoint = { 0,0 };

	m_hour = { 0,0 };
	m_minuate = { 0,0 };
	m_second = { 0,0 };


	GetLocalTime(&st);
	printf("%d %d %d ", st.wHour, st.wMinute, st.wSecond);


	/*m_hourTheta = 270;
	m_minuateTheta = 270;
	m_secondTheta = 270;*/

	m_hourTheta = st.wHour * 30.0f - 90.0f;
	m_minuateTheta = st.wMinute * 6.0f - 90.0f;
	m_secondTheta = st.wSecond * 6.0f -  90.0f;


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
	m_Gfx->ClearScreen(0.0f, 0.0f, 0.0f);
	
	m_clock->Render();


	//m_Gfx->DrawCircle((float)(m_dScnX / 2), (float)(m_dScnY / 2), 100.0f, 1.0f, 1.0f, 1.0f, 1.0f);

	//m_sprite->Draw(m_PlayerPos, &m_playerCenter, D2D1::Point2F(m_PlayerScale.x, m_PlayerScale.y), m_rot);
	//m_Gfx->DrawTextOut(L"20106 ������", D2D1::Point2F(m_PlayerPos.x - 50, m_PlayerPos.y - 30));

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

	
	m_Gfx->DrawCircle(m_clockCenterPoint.x, m_clockCenterPoint.y, 300.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	float radian = PI / 180.0f;

	m_hour.x = cosf(m_hourTheta * radian) * 100;
	m_hour.y = sinf(m_hourTheta * radian) * 100;

	m_minuate.x = cosf(m_minuateTheta * radian) * 200;
	m_minuate.y = sinf(m_minuateTheta * radian) * 200;

	m_second.y = sinf(m_secondTheta * radian) * 250;
	m_second.x = cosf(m_secondTheta * radian) * 250;

	m_Gfx->DrawLine(m_clockCenterPoint.x, m_clockCenterPoint.y
		, m_clockCenterPoint.x + m_hour.x, m_clockCenterPoint.y + m_hour.y
		, 5, 1.0f, 1.0, 1.0f, 1.0f);

	m_Gfx->DrawLine(m_clockCenterPoint.x, m_clockCenterPoint.y
		, m_clockCenterPoint.x + m_minuate.x, m_clockCenterPoint.y + m_minuate.y
		, 5, 1.0f, 1.0, 1.0f, 1.0f);

	m_Gfx->DrawLine(m_clockCenterPoint.x, m_clockCenterPoint.y
		, m_clockCenterPoint.x + m_second.x, m_clockCenterPoint.y + m_second.y
		, 5, 1.0f, 1.0, 1.0f, 1.0f);


	for (int i = 0; i < 60; i++)
	{
		float y = sinf((i * 6) * radian) * 280;
		float x = cosf((i * 6) * radian) * 280;
		m_Gfx->DrawPoint(m_clockCenterPoint.x + x, m_clockCenterPoint.y + y, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	

	//m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());

	//

	//m_sprite->Draw(m_PlayerPos, &m_playerCenter, D2D1::Point2F(m_PlayerScale.x, m_PlayerScale.y), m_rot);
	//m_Gfx->DrawTextOut(L"20106 ������", D2D1::Point2F(m_PlayerPos.x - 50, m_PlayerPos.y - 30));

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
	//m_Gfx->DrawTextOut(L"�̵�: ����Ű\n ȸ��: ���콺 ����\n Ȯ��/���: ���콺 ��/�� Ŭ��", D2D1::Point2F());

	m_Gfx->EndDraw();
	return 0;
}
int Second = 1;
int Hour = 0;
INT CGame::FrameMove(DWORD elpased)
{
	CDX2DAPP::FrameMove(elpased);

	m_clock->Update();

	static DWORD OldTimer = timeGetTime();
	DWORD timer = timeGetTime();
	float MaxHour = 12.0f;
	float MaxMinuate = 60.0f;
	float MaxSecond =  60.0f;
	if (timer - OldTimer  >= 1000)
	{
		//printf("%d %d\n", timer, OldTimer);
		if (m_secondTheta + 6.0f < 360.0f) {
			m_secondTheta += 6.0f;
			Second++;
		}
		else m_secondTheta = 0.0f;


		if (m_secondTheta == 270.0f)
		{
			m_minuateTheta += 6.0f;

			if (m_minuateTheta + 6.0f == 360.0f) {
				m_minuateTheta = 0.0f;
			}

			if (m_minuateTheta == 270.0f)
			{
				m_hourTheta += 30.0f;
				++Hour;
				printf("%d %f\n", Hour, m_hourTheta);
				if (m_hourTheta == 360.0f) {
					m_hourTheta = 0.0f;
				}

			}
		}

		
		OldTimer = timer;
	}

	
	

	//if (m_hourTheta <= 360.0f)
	//	m_hourTheta += 1.0f;
	//else m_hourTheta = 0.0f;

	//if (m_minuateTheta <= 360.0f)
	//	m_minuateTheta += 1.0f;
	//else m_minuateTheta = 0.0f;


	


	/*
	m_playerCenter.x = m_PlayerPos.x + (m_sprite->GetSize().width / 2);
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
	*/
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
