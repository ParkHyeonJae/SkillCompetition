#pragma once
class CGame : public CDX2DAPP
{

public:
	CGame();
	~CGame();

	virtual INT Init();
	virtual INT Render();
	virtual INT FrameMove(DWORD elpased);
	virtual void Destroy();

	virtual INT Control();

	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

