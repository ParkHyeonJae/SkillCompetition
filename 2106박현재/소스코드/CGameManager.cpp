#include "framework.h"

CInput* CGameManager::m_Input = NULL;
CGraphics* CGameManager::m_gfx = NULL;
CSpriteManager* CGameManager::m_SpriteManager = NULL;
CGameObjectManager* CGameManager::m_GameObjectManager = NULL;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init(CInput* Input, CGraphics* gfx, CGameObjectManager* GOMg, CSpriteManager* SprMg) // , CSceneObject* Scene)
{
	m_Input = Input;
	m_gfx = gfx;
	m_GameObjectManager = GOMg;
	m_SpriteManager = SprMg;

	//Loading = true;
	//m_CurrentScene = Scene;
	//m_CurrentScene->Init();
	//Loading = false;
}