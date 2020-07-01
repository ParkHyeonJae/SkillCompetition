#pragma once
class CGameObjectManager
{
protected:
	std::map<CStringW, CGameObject*> m_gameObjectMap;
public:
	CGameObjectManager();
	~CGameObjectManager();

	void AddObject(CGameObject* p_pObject);
	void RemoveObject(CGameObject* p_pOjbect);
	CGameObject* FindObject(LPCWSTR sFile);

	void RemoveAllObject();

};

