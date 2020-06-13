#include "framework.h"

BOOL IsPointInRect(const RECT rt, const POINT pt)
{
	if ((rt.left <= pt.x && rt.right >= pt.x) &&
		(rt.top <= pt.y && rt.bottom >= pt.y))
	{
		return TRUE;
	}
	return FALSE;
}

BOOL IsPointInCircle(const POINT ptCircle, const int cr, const POINT pt)
{
	float dx = ptCircle.x - pt.x;
	float dy = ptCircle.y - pt.y;
	float l = sqrt(dx * dx + dy * dy);

	if (l <= cr) return TRUE;
	
	return FALSE;
}

RECT* rtIntersectRect(const RECT rt1, const RECT rt2)
{
	RECT* pIntersect = new RECT();
	*pIntersect = RECT{ 0,0,0,0 };

	if (rt1.left < rt2.right && rt1.right > rt2.left)
	{
		pIntersect->left = max(rt1.left, rt2.left);
		pIntersect->right = min(rt1.right, rt2.right);
	}
	if (rt1.top < rt2.bottom && rt1.bottom > rt2.top)
	{
		pIntersect->top = max(rt1.top, rt2.top);
		pIntersect->bottom = min(rt1.bottom, rt2.bottom);
	}

	return pIntersect;
}

BOOL IsRectInRect(const RECT rt1, const RECT rt2)
{
	if (rt1.right >= rt2.left && rt1.bottom >= rt2.top
		&& rt1.left <= rt2.right && rt1.top <= rt2.bottom) {
		
		return TRUE;

	}
	return FALSE;
}
BOOL IsRectInCircle(POINT ptCircle, int radius, const RECT rt)
{
	RECT newRt = { rt.left - radius, rt.top - radius, rt.right + radius ,rt.bottom + radius };

	if ((newRt.left < ptCircle.x && newRt.right > ptCircle.x) &&
		(newRt.top < ptCircle.y && newRt.bottom > ptCircle.y))
	{
		return TRUE;
	}

	return FALSE;
}
BOOL CircleCrashCheck(POINT ptCircle1, int r1, POINT ptCircle2, int r2)
{
	float dx = ptCircle1.x - ptCircle2.x;
	float dy = ptCircle1.y - ptCircle2.y;
	float l = sqrt(dx * dx + dy * dy);

	if (l <= (r1 + r2)) return TRUE;
	return FALSE;
}
