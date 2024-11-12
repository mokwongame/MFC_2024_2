#pragma once
#include <afxwin.h>

class GameScreen :
	public CStatic
{
public:
	GameScreen(void) // 持失切
	{}
	~GameScreen() // 社瑚切
	{}

protected:
	int m_nBkWid = 1000;
	int m_nBkHt = 370;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
};

