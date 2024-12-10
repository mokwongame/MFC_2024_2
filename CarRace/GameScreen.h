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
	{}

	// getter
	int getFps(void) const
	{
		return m_fps;
	}

	CPoint getRandPt(void) const;

	void moveCarLeft(void)
	{
		m_car.moveLeft();
	}

	void moveCarRight(void)
	{
		m_car.moveRight();
	}

protected:
	Road m_road;
	Car m_car;
	Car m_enemy;
	int m_fps = 80; // frame per second

public:
	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

