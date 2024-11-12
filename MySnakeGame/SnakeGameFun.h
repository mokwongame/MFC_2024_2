#pragma once

#include <stdlib.h>
#include <time.h>

#define DU2SU	(1000./1750.) // ���̾�α� ���� / ȭ�� ����
#define FPS		(60)	// frame per second
#define TIMER_SCREEN	(1)

// ���� �߻��� �ʱ�ȭ
inline void randseed()
{
	time_t nTime = time(NULL);
	srand((unsigned int)llabs(nTime * nTime));
}

// rmin, rmin+1, ..., rmax-1 ������ ���� ���
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