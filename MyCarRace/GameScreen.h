#pragma once

#include <afxwin.h>
#include "Road.h"
#include "Car.h"

#define TIMER_SCREEN	(1)

class GameScreen :
	public CStatic
{
public:
	GameScreen(void);
	~GameScreen()
	{
	}

	int getFps(void) const
	{
		return m_fps;
	}

	void moveCarLeft(void)
	{
		m_car.moveLeft();
	}
	void moveCarRight(void)
	{
		m_car.moveRight();
	}

	CPoint makeRandPt(void) const;

	void incStep(void)
	{
		m_road.incStep();
		m_enemy.incStep();
	}
	void decStep(void)
	{
		m_road.decStep();
		m_enemy.decStep();
	}

	void drawScore(CDC* pDC);

protected:
	// 프로퍼티: 멤버 변수
	Road m_road;
	Car m_car;
	Car m_enemy;
	int m_fps; // frames per second
	bool m_bGameOver;
	int m_nScore;

public:
	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

