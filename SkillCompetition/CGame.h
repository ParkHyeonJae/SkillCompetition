#pragma once
class CGame : public CDX2DAPP
{

public:
	CGame();
	~CGame();

	virtual INT Init();
	virtual INT Render();
	virtual INT FrameMove(DWORD elpased);

	virtual INT Control();

};

