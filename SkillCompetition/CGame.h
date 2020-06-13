#pragma once
class CGame : public CDX2DAPP
{
	D2D1_POINT_2F m_clockCenterPoint;
	D2D1_POINT_2F m_clockEndPoint;
	float m_theta;



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

