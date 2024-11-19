#pragma once
#include <afxwin.h>
#include "Wall.h"
#include "Snake.h"

class GameScreen :
	public CStatic
{
public:
	GameScreen(void) // 持失切
	{}
	~GameScreen() // 社瑚切
	{}

	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

protected:
	int m_nBkWid = 1000;
	int m_nBkHt = 370;
	Wall m_wall;
	Snake m_snake;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
};

