#pragma once
class CGame : public CDX2DAPP
{
	Clock* m_clock;
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

