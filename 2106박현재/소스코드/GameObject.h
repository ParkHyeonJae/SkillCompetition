#pragma once
class CGameObject : public IGameObject
{
protected:
	D2D1_POINT_2F			m_Pos;
	CSprite* m_Sprite;

public:
	D2D1_POINT_2F			m_Scale;
	D2D1_RECT_F				m_rTiled;
	INT						m_tag;
	CStringW				m_Name;
	BOOL					m_isLive;

	CGameObject(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int tag);
	virtual ~CGameObject(void);

	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;		//07

	D2D1_POINT_2F GetPos() { return m_Pos; }
};

