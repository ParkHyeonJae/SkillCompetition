#include "framework.h"


CGameObject::CGameObject(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int tag)
{
	m_tag = tag;

	m_Pos = Pos;

	m_Sprite = CGameManager::GetSpriteManager()->GetSprite(sFileName);

	m_rTiled = D2D1::RectF(0, 0, (float)sprWidth, (float)sprHeight);

	m_Scale = { 1, 1 };

	m_Name = sFileName;

	m_isLive = true;
}

CGameObject::~CGameObject(void)
{
}

void CGameObject::Render()
{
	m_Sprite->Draw(m_Pos);
}

void CGameObject::FrameMove(DWORD elapsed)
{
}

void CGameObject::Control(CInput* Input)
{
}
