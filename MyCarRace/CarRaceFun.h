#pragma once

#include <stdlib.h>
#include <time.h>

// 난수 발생을 초기화
inline void randseed()
{
	time_t nTime = time(NULL);
	srand((unsigned int)llabs(nTime * nTime));
}

// rmin, rmin+1, ..., rmax-1 사이의 정수 출력
inline int randrange(int rmin, int rmax)
{
	if (rmin < rmax)
	{
		int nRand = rand() % (rmax - rmin);
		return nRand + rmin;
	}
	else if (rmin == rmax) return rmin;
	else return 0;
}

inline bool rectInRect(const CRect& rect1, const CRect& rect2)
{
	if (rect1.PtInRect(rect2.TopLeft()) || rect1.PtInRect(rect2.BottomRight()) || rect1.PtInRect(CPoint(rect2.left, rect2.bottom)) || rect1.PtInRect(CPoint(rect2.right, rect2.top))) return true;
	else return false;
}

inline bool rectInRectAny(const CRect& rect1, const CRect& rect2)
{
	return rectInRect(rect1, rect2) || rectInRect(rect2, rect1);
}