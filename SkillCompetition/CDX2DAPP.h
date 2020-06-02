#pragma once
class CDX2DAPP
{
protected:
	LPCWSTR m_sCls;
	HINSTANCE m_hInst;
	HWND m_hWnd;
	DWORD m_dWinStyle;
	DWORD m_dScnX;
	DWORD m_dScnY;
	BOOL m_bShowCursor;

	RECT m_rcWin;

	DWORD m_fps;

protected:
	CGraphics* m_Gfx;
public:
	CDX2DAPP();
	virtual ~CDX2DAPP();

	INT Create(HINSTANCE hInst);
	INT Run();
	void CleanUp();

	INT RenderLoop();

	virtual INT Init();
	virtual INT Render();
	virtual INT FrameMove(DWORD elpased);
	
	virtual INT Control();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	static LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
	
};

