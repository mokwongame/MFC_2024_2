#pragma once

#include <afxwin.h>
#include "Road.h"

class GameScreen :
	public CStatic
{
public:
	GameScreen(void)
	{}
	~GameScreen()
	{}

protected:
	Road m_road;

public:
	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
};

