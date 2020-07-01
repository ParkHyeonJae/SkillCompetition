#pragma once

BOOL IsPointInRect(const RECT rt, const POINT pt);		//점과 사각형 충돌

BOOL IsPointInCircle(const POINT ptCircle, const int cr, const POINT pt);		//원과 점 출동

RECT* rtIntersectRect(const RECT rt1, const RECT rt2);		//사각형 충돌 여백
BOOL IsRectInRect(const RECT rt1, const RECT rt2);
BOOL CircleCrashCheck(POINT ptCircle1, int r1, POINT ptCircle2, int r2);		//원과 원 충돌 체크
BOOL IsRectInCircle(POINT ptCircle, int radius, const RECT rt);