#include "framework.h"

CGameObjectManager::CGameObjectManager()
{
}


CGameObjectManager::~CGameObjectManager()
{
	RemoveAllObject();
}

void CGameObjectManager::AddObject(CGameObject* pObject)
{
	m_gameObjectMap[pObject->m_Name] = pObject;
}

void CGameObjectManager::RemoveObject(CGameObject* p_pOjbect)
{

}

CGameObject* CGameObjectManager::FindObject(LPCWSTR sFile)
{
	CGameObject* gameObject = m_gameObjectMap[sFile];
	if (gameObject == NULL) {
		MessageBox(NULL, L"Texture Loading Failed", L"Error", MB_OK);
		return NULL;
	}
	else {
		return gameObject;
	}
}

void CGameObjectManager::RemoveAllObject()
{
	std::map<CStringW, CGameObject*>::iterator iter = m_gameObjectMap.begin();

	while (iter != m_gameObjectMap.end()) {
		delete iter->second;
		m_gameObjectMap.erase(iter++);
	}

	if (m_gameObjectMap.empty() != false) {
		m_gameObjectMap.clear();
	}
}