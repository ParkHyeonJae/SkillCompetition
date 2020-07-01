#pragma once
class CGameManager
{
	static CGraphics* m_gfx;
	static CSpriteManager* m_SpriteManager;
	static CGameObjectManager* m_GameObjectManager;
	static CInput* m_Input;
public:
	CGameManager();
	~CGameManager();

	static void Init(CInput* Input, CGraphics* gfx, CGameObjectManager* GOMg, CSpriteManager* SprMg); //  , CSceneObject* Scene);
	//static void Init(CInput* Input, CGraphics* gfx, CSpriteManager* SprMg, CSceneObject* Scene);

	static CGraphics* GetGfx() { return m_gfx; }
	//static CSceneObject* GetCurrentScene() { return m_CurrentScene; }
	static CGameObjectManager* GetGameObjectManager() {
		return m_GameObjectManager;
	}
	static CSpriteManager* GetSpriteManager() { return m_SpriteManager; }
};

