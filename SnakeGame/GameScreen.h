#pragma once
#include <afxwin.h>
#include "Wall.h"
#include "Snake.h"
#include "Fruit.h"

#define SCREEN_TIMER	(1)
#define FPS		(60)	// frame per second

class GameScreen :
	public CStatic
{
public:
	GameScreen(void) // 持失切
	{}
	~GameScreen() // 社瑚切
	{}

	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

	void setSnakeDir(SnakeDir nDir)
	{
		m_snake.setDir(nDir);
	}

protected:
	int m_nBkWid = 1000;
	int m_nBkHt = 370;
	Wall m_wall;
	Snake m_snake;
	Fruit m_fruit;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

