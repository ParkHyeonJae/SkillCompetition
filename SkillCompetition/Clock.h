#pragma once
class Clock
{
private:
	SYSTEMTIME st;
	D2D1_POINT_2F m_circleCenter;


	D2D1_POINT_2F m_hourPoint;
	D2D1_POINT_2F m_minuatePoint;
	D2D1_POINT_2F m_secondPoint;

	CSprite* m_clockspirte;

	float m_secondTheta;
	float m_minuateTheta;
	float m_hourTheta;

	float radian;

	CGraphics* m_Gfx;
	DWORD m_dScnX;
	DWORD m_dScnY;
public:
	Clock(CGraphics * m_Gfx, DWORD m_dScnX, DWORD m_dScnY);
	~Clock();

	INT Init();
	INT Update();
	INT Render();

};

