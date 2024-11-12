#pragma once
#include <afxwin.h>
#include "Wall.h"

class GameScreen :
	public CStatic
{
public:
	GameScreen(void) // ������
	{}
	~GameScreen() // �Ҹ���
	{}

	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

protected:
	int m_nBkWid = 1000;
	int m_nBkHt = 370;
	Wall m_wall;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
};

