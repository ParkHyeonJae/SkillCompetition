#include "framework.h"

Clock::Clock(CGraphics* m_Gfx, DWORD m_dScnX, DWORD m_dScnY)
{
	this->m_Gfx = m_Gfx;
	this->m_dScnX = m_dScnX;
	this->m_dScnY = m_dScnY;

	
}

Clock::~Clock()
{
}

INT Clock::Init()
{
	m_circleCenter = { (float)(m_dScnX / 2),(float)(m_dScnY / 2) };

	m_secondPoint = { 0,0 };
	m_minuatePoint = { 0,0 };
	m_hourPoint = { 0,0 };

	radian = PI / 180.0f;

	m_clockspirte = new CSprite(L"./Images/clock_background.png", m_Gfx, 583, 830);

	m_clockSecondHand = new CSprite(L"./Images/SecondHand.png", m_Gfx);
	m_clockMinuateHand = new CSprite(L"./Images/Minuate.png", m_Gfx);
	m_clockHourHand = new CSprite(L"./Images/Hour.png", m_Gfx);


	m_clockMode = PICTURE;

	return 0;
}



INT Clock::Render()
{
	m_clockspirte->Draw(D2D1::Point2F(87.5f, -50));

	m_Gfx->DrawCircle(m_circleCenter.x, m_circleCenter.y, 255, 1.0f, 1.0f, 1.0f, 1.0f);

	D2D1_POINT_2F center;
	switch (m_clockMode)
	{
	case _CLOCKMODE::GEOMETRY:// 지오메트리 모드
		// 초침
		m_secondPoint.x = cosf(m_secondTheta * radian) * 150.0f;
		m_secondPoint.y = sinf(m_secondTheta * radian) * 150.0f;
		// 분침
		m_minuatePoint.x = cosf(m_minuateTheta * radian) * 100.0f;
		m_minuatePoint.y = sinf(m_minuateTheta * radian) * 100.0f;
		//시침
		m_hourPoint.x = cosf(m_hourTheta * radian) * 70.0f;
		m_hourPoint.y = sinf(m_hourTheta * radian) * 70.0f;

		// 초침 그리기
		m_Gfx->DrawLine(m_circleCenter.x, m_circleCenter.y,
			m_circleCenter.x + m_secondPoint.x, m_circleCenter.y + m_secondPoint.y, 3, 1.0f, 0.0f, 0.0f, 1.0f);

		// 분침 그리기
		m_Gfx->DrawLine(m_circleCenter.x, m_circleCenter.y,
			m_circleCenter.x + m_minuatePoint.x, m_circleCenter.y + m_minuatePoint.y, 4, 0.0f, 1.0f, 0.0f, 1.0f);

		//시침 그리기
		m_Gfx->DrawLine(m_circleCenter.x, m_circleCenter.y,
			m_circleCenter.x + m_hourPoint.x, m_circleCenter.y + m_hourPoint.y, 6, 0.0f, 0.0f, 0.0f, 1.0f);

		m_Gfx->DrawPoint(m_circleCenter.x, m_circleCenter.y, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		break;
	case _CLOCKMODE::PICTURE:
		
		center = { m_circleCenter.x - 100.0f + (m_clockSecondHand->GetSize().width / 2)
			,m_circleCenter.y - 100.0f + (m_clockSecondHand->GetSize().height / 2) };				//초침

		m_clockSecondHand->Draw(D2D1::Point2F(m_circleCenter.x - 100.0f, m_circleCenter.y - 100.0f),
			&center, D2D1::Point2F(1.5f, 1.5f), m_secondTheta);

		
		center = { m_circleCenter.x - 100.0f + (m_clockMinuateHand->GetSize().width / 2)
			,m_circleCenter.y - 100.0f + (m_clockMinuateHand->GetSize().height / 2) };			//분침

		m_clockMinuateHand->Draw(D2D1::Point2F(m_circleCenter.x - 100.0f, m_circleCenter.y - 100.0f),
			&center, D2D1::Point2F(1.5f, 1.5f), m_minuateTheta);

		
		center = { m_circleCenter.x - 100.0f + (m_clockHourHand->GetSize().width / 2)
			,m_circleCenter.y - 100.0f + (m_clockHourHand->GetSize().height / 2) };

		m_clockHourHand->Draw(D2D1::Point2F(m_circleCenter.x - 100.0f, m_circleCenter.y - 100.0f),
			&center, D2D1::Point2F(1.5f, 1.5f), m_hourTheta);								//시침

		break;
	default:
		break;
	}
	
	return 0;
}

INT Clock::Update()
{
	GetLocalTime(&st);

	switch (m_clockMode)
	{
	case _CLOCKMODE::GEOMETRY:
		//지오메트리 모드
		m_secondTheta = static_cast<FLOAT>((st.wSecond * 6) - 90);
		m_minuateTheta = static_cast<FLOAT>((st.wMinute * 6) - 90);
		m_hourTheta = static_cast<FLOAT>((st.wHour * 30) - 90);
		break;
	case _CLOCKMODE::PICTURE:
		//그림 모드
		m_secondTheta = static_cast<FLOAT>(st.wSecond * 6);
		m_minuateTheta = static_cast<FLOAT>(st.wMinute * 6);
		m_hourTheta = static_cast<FLOAT>(st.wHour * 30);
		break;
	default:
		break;
	}
	



	return 0;
}

INT Clock::Control(CInput* m_Input)
{
	if (m_Input->KeyDown(VK_SPACE))
	{
		m_clockMode = !m_clockMode;
	}
	return 0;
}
