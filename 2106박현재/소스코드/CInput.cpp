#include "framework.h"

CInput::CInput(void)
{
	m_hWnd = NULL;

	memset(m_KeyOld, 0, sizeof(m_KeyOld));
	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));
	
	memset(m_BtnCur, 0, sizeof(m_BtnCur));
	memset(m_BtnOld, 0, sizeof(m_BtnOld));
	memset(m_BtnMap, 0, sizeof(m_BtnMap));

	m_vcCur = { 0,0 };
	m_vcOld = { 0,0 };
	m_vcEps = { 0,0 };

	m_dTimeDC = 0;
	memset(m_dBtnBgn, 0, sizeof(m_dBtnBgn));
	memset(m_dBtnCnt, 0, sizeof(m_dBtnCnt));



	SetKeyboardState(m_KeyCur);
}

CInput::~CInput(void)
{
}

INT CInput::Create(HWND hWnd)
{
	m_hWnd = hWnd;

	memset(m_KeyOld, 0, sizeof(m_KeyOld));
	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	memset(m_BtnCur, 0, sizeof(m_BtnCur));
	memset(m_BtnOld, 0, sizeof(m_BtnOld));
	memset(m_BtnMap, 0, sizeof(m_BtnMap));


	m_vcCur = { 0,0 };
	m_vcOld = { 0,0 };
	m_vcEps = { 0,0 };

	m_dTimeDC = GetDoubleClickTime();

	memset(m_dBtnBgn, 0, sizeof(m_dBtnBgn));
	memset(m_dBtnCnt, 0, sizeof(m_dBtnCnt));

	m_dBtnBgn[0] = GetTickCount();

	for (int i = 1; i < MAX_INPUT_BTN; ++i)
	{
		m_dBtnBgn[i] = m_dBtnBgn[0];
	}

	memset(m_dBtnCnt, 0, sizeof(m_dBtnCnt));

	UINT ucNumLines = 0;
	SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &ucNumLines, 0);


	return 0;
}

INT CInput::FrameMove()
{
	INT i = 0;

	memcpy(m_KeyOld, m_KeyCur, sizeof(m_KeyOld));
	memcpy(m_BtnOld, m_BtnCur, sizeof(m_BtnOld));

	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	memset(m_BtnCur, 0, sizeof(m_BtnCur));
	memset(m_BtnMap, 0, sizeof(m_BtnMap));

	GetKeyboardState(m_KeyCur);

	//Keyboard
	for (i = 0; i < MAX_INPUT_KEY; ++i)
	{
		BYTE vKey = m_KeyCur[i] & 0x80;
		m_KeyCur[i] = (vKey) ? 1 : 0;

		INT nOld = m_KeyOld[i];
		INT nCur = m_KeyCur[i];

		if (0 == nOld && 1 == nCur) m_KeyMap[i] = EINPUT_DOWN;
		else if (1 == nOld && 0 == nCur) m_KeyMap[i] = EINPUT_UP;
		else if (1 == nOld && 1 == nCur) m_KeyMap[i] = EINPUT_PRESS;
		else							 m_KeyMap[i] = EINPUT_NONE;

	}

	//Mouse Btn
	m_BtnCur[0] = m_KeyCur[VK_LBUTTON];
	m_BtnCur[1] = m_KeyCur[VK_RBUTTON];
	m_BtnCur[2] = m_KeyCur[VK_MBUTTON];

	for (i = 0; i < MAX_INPUT_BTN; i++)
	{
		INT nOld = m_BtnOld[i];
		INT nCur = m_BtnCur[i];

		if (0 == nOld && 1 == nCur) m_BtnMap[i] = EINPUT_DOWN;
		else if (1 == nOld && 0 == nCur) m_BtnMap[i] = EINPUT_UP;
		else if (1 == nOld && 1 == nCur) m_BtnMap[i] = EINPUT_PRESS;
		else							 m_BtnMap[i] = EINPUT_NONE;
	}

	//Update Mouse Position

	::GetCursorPos(&m_vcCur);
	::ScreenToClient(m_hWnd, &m_vcCur);

	m_vcEps.x = m_vcCur.x - m_vcOld.x;
	m_vcEps.y = m_vcCur.y - m_vcOld.y;

	m_vcOld = m_vcCur;

	//Double Click
	DWORD dBtnCur = GetTickCount();

	for (i = 0; i < MAX_INPUT_BTN; i++)
	{
		if (EINPUT_DOWN == m_BtnMap[i])
		{
			if (1 == m_dBtnCnt[i])
			{
				if ((dBtnCur - m_dBtnBgn[i]) >= m_dTimeDC)
				{
					m_dBtnCnt[i] = 0;
				}
			}
			++m_dBtnCnt[i];
			if (1 == m_dBtnCnt[i])
			{
				m_dBtnBgn[i] = dBtnCur;
			}
		}
		if (EINPUT_UP == m_BtnMap[i])
		{
			if (1 == m_dBtnCnt[i])
			{
				if ((dBtnCur - m_dBtnBgn[i]) >= m_dTimeDC)
				{
					m_dBtnCnt[i] = 0;
				}
			}
			else if (2 == m_dBtnCnt[i])
			{
				if ((dBtnCur - m_dBtnBgn[i]) <= m_dTimeDC)
				{
					m_BtnMap[i] = EINPUT_DBCLK;
				}
				m_dBtnCnt[i] = 0;
			}
		}
	}

	return 0;
}

LRESULT CInput::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{

	}
	return 0;
}

BOOL CInput::KeyDown(INT nKey)
{
	return m_KeyMap[nKey] == EINPUT_DOWN;
}

BOOL CInput::KeyUp(INT nKey)
{
	return m_KeyMap[nKey] == EINPUT_UP;
}

BOOL CInput::KeyPress(INT nKey)
{
	return m_KeyMap[nKey] == EINPUT_PRESS;
}

INT CInput::KeyState(INT nKey)
{
	return m_KeyMap[nKey];
}	


BOOL CInput::BtnDown(INT nBtn)
{
	return m_BtnMap[nBtn] == EINPUT_DOWN;
}

BOOL CInput::BtnUp(INT nBtn)
{
	return m_BtnMap[nBtn] == EINPUT_UP;
}

BOOL CInput::BtnPress(INT nBtn)
{
	return m_BtnMap[nBtn] == EINPUT_PRESS;
}

INT CInput::BtnState(INT nBtn)
{
	return m_BtnMap[nBtn];
}

POINT CInput::GetMousePos()
{
	return m_vcCur;
}

POINT CInput::GetMouseEps()
{
	return m_vcEps;
}
