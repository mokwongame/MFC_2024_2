#pragma once
#include <afxwin.h>
#include "Wall.h"
#include "Snake.h"
#include "Fruit.h"

class MyScreen :
	public CStatic
{
public:
	MyScreen(void)
	{}
	~MyScreen()
	{}

	int getScore(void) const
	{
		return m_nScore;
	}

	void setSnakeDir(SnakeDir nDir)
	{
		m_snake.setDir(nDir);
	}

	void incScore(void)
	{
		m_nScore++;
	}

	void drawScore(CDC* pDC);
	void drawGameOver(CDC* pDC);

	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

protected:
	int m_nBkWid = 1000;
	int m_nBkHt = 370;
	int m_nScore = 0;
	Wall m_wall;
	Snake m_snake;
	Fruit m_fruit;
	bool m_bGameOver = false;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

