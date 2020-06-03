#pragma once
class CGame : public CDX2DAPP
{
	CSprite* m_sprite;
	D2D1_POINT_2F m_PlayerPos;
	D2D1_POINT_2F m_PlayerScale;
	float m_rot;
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

