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

	m_clockspirte = new CSprite(L"../Images/clock_background.png", m_Gfx, 583, 830);
	return 0;
}



INT Clock::Render()
{
	m_clockspirte->Draw(D2D1::Point2F(87.5f, -50));

	m_Gfx->DrawCircle(m_circleCenter.x, m_circleCenter.y, 255, 1.0f, 1.0f, 1.0f, 1.0f);

	m_secondPoint.x = cosf(m_secondTheta * radian) * 150.0f;
	m_secondPoint.y = sinf(m_secondTheta * radian) * 150.0f;

	m_minuatePoint.x = cosf(m_minuateTheta * radian) * 100.0f;
	m_minuatePoint.y = sinf(m_minuateTheta * radian) * 100.0f;

	m_hourPoint.x = cosf(m_hourTheta * radian) * 50.0f;
	m_hourPoint.y = sinf(m_hourTheta * radian) * 50.0f;

	m_Gfx->DrawLine(m_circleCenter.x, m_circleCenter.y,
		m_circleCenter.x + m_secondPoint.x, m_circleCenter.y + m_secondPoint.y, 3, 1.0f, 0.0f, 0.0f, 1.0f);

	m_Gfx->DrawLine(m_circleCenter.x, m_circleCenter.y,
		m_circleCenter.x + m_minuatePoint.x, m_circleCenter.y + m_minuatePoint.y, 4, 0.0f, 1.0f, 0.0f, 1.0f);

	m_Gfx->DrawLine(m_circleCenter.x, m_circleCenter.y,
		m_circleCenter.x + m_hourPoint.x, m_circleCenter.y + m_hourPoint.y, 6, 0.0f, 0.0f, 0.0f, 1.0f);

	m_Gfx->DrawPoint(m_circleCenter.x, m_circleCenter.y, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	return 0;
}

INT Clock::Update()
{
	GetLocalTime(&st);


	m_secondTheta = ((st.wSecond * 6) - 90);
	m_minuateTheta = ((st.wMinute * 6) - 90);
	m_hourTheta = ((st.wHour * 30) - 90);
	return 0;
}