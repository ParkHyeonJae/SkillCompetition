#pragma once

BOOL IsPointInRect(const RECT rt, const POINT pt);		//���� �簢�� �浹

BOOL IsPointInCircle(const POINT ptCircle, const int cr, const POINT pt);		//���� �� �⵿

RECT* rtIntersectRect(const RECT rt1, const RECT rt2);		//�簢�� �浹 ����
BOOL IsRectInRect(const RECT rt1, const RECT rt2);
BOOL CircleCrashCheck(POINT ptCircle1, int r1, POINT ptCircle2, int r2);		//���� �� �浹 üũ
BOOL IsRectInCircle(POINT ptCircle, int radius, const RECT rt);