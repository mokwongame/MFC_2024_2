#pragma once

#include <afxwin.h>

// 클래스 마법사 호출: Ctrl+Shift+X; 프로젝트 > 클래스 마법사
class CPainter :
	public CStatic
{
public:
	CPainter(void);

protected:
	int m_nRectX0; // 사각형의 x좌표
	int m_nRectY0; // 사각형의 y좌표
	int m_nRectWidth; // 사각형의 너비
	int m_nRectHeight;	// 사각형의 높이

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

