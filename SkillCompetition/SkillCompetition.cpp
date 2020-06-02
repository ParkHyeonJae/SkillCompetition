﻿// SkillCompetition.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"

extern CDX2DAPP* g_pDX2DApp;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    

    CGame GameApp;

    g_pDX2DApp = &GameApp;

    HRESULT hr = GameApp.Create(hInstance);
    if (hr != S_OK)
        return -1;
    return GameApp.Run();
    
}