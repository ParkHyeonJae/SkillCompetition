#pragma once
class CGame : public CDX2DAPP
{
	SYSTEMTIME st;
	D2D1_POINT_2F m_circleCenter;


	D2D1_POINT_2F m_hourPoint;
	D2D1_POINT_2F m_minuatePoint;
	D2D1_POINT_2F m_secondPoint;

	CSprite * m_clockspirte;
	CSprite* m_clockHour;
	CSprite* m_clockMinuate;

	float m_secondTheta;
	float m_minuateTheta;
	float m_hourTheta;

	float radian;

	Clock* m_clock;

	
	INT m_clockMode;
	//CSprite* m_sprite;
	//D2D1_POINT_2F m_playerCenter;
	//D2D1_POINT_2F m_PlayerPos;
	//D2D1_POINT_2F m_PlayerScale;
	//RECT m_rtPlayerBox;

	//RECT m_rtTargetBox;
	//RECT m_rtTargetBox2;
	//

	//POINT m_TargetCircle;
	//int radius;

	//POINT m_TargetCircle2;
	//int radius2;

	//float m_rot;
	//BOOL m_bIsCrash;
	//BOOL m_bIsCircleCrash;
	//BOOL m_bOnceGeometry[2];
public:
	CGame();
	~CGame();

	virtual INT Init();
	virtual INT Render();
	virtual INT FrameMove(DWORD elpased);
	virtual void Destroy();

	virtual INT Control(CInput * Input);

	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

