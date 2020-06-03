#include "framework.h"


CSpriteManager::CSpriteManager()
{
}


CSpriteManager::~CSpriteManager()
{
	Destroy();
}

CSprite* CSpriteManager::GetSprite(LPCWSTR sFile) {
	CSprite* _Spr = m_SpriteMap[sFile];
	if (_Spr == NULL) {
		return LoadData(sFile);
	}
	else {
		return _Spr;
	}
}

CSprite* CSpriteManager::LoadData(LPCWSTR sFile) {
	CSprite* Spr = new CSprite(sFile, CGameManager::GetGfx());

	//	if (Spr == NULL)
	//		MessageBox(g_pApp->m_hWnd, L"Texture Loading Failed", L"Error", MB_OK);

	m_SpriteMap[sFile] = Spr;

	//m_TextureMap.insert(std::map<std::string, CTexture*>::value_type(sFile, pTexture));//FileName, pTexture);
	return Spr;
}

void CSpriteManager::Init() {

}
void CSpriteManager::Destroy() {
	std::map<CStringW, CSprite*>::iterator iter = m_SpriteMap.begin();

	while (iter != m_SpriteMap.end()) {
		delete iter->second;
		m_SpriteMap.erase(iter++);
	}
	if (m_SpriteMap.empty() != false) {
		m_SpriteMap.clear();
	}
}