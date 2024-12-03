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
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
};

