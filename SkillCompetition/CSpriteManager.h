#pragma once
class CSpriteManager
{
private:
	std::map<CStringW, CSprite*> m_SpriteMap;
public:
	CSpriteManager();
	~CSpriteManager();

	CSprite* GetSprite(LPCWSTR sFile);
	CSprite* LoadData(LPCWSTR sFile);

	void Init();
	void Destroy();
};

