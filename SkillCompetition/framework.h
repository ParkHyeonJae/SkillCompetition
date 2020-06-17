// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#define PI 3.141592654

// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <atlstr.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <mmsystem.h>
#include <math.h>

#include <vector>
#include <map>

#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "windowscodecs.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "winmm.lib")

#include "Utility.h"
#include "CGraphics.h"
#include "CSprite.h"
#include "CInput.h"
#include "SkillCompetition.h"
#include "CSpriteManager.h"
#include "IGameObject.h"
#include "GameObject.h"
#include "CGameObjectManager.h"
#include "CGameManager.h"
#include "CDX2DAPP.h"
#include "CGame.h"

//
//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
//#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
//#endif