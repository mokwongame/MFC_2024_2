#pragma once

#include <afxwin.h>

// 클래스 마법사 호출: Ctrl+Shift+X; 프로젝트 > 클래스 마법사
class CPainter :
	public CStatic
{
public:
	CPainter(void);

	int getRectX0(void) const { return m_nRectX0; }
	int getRectY0(void) const { return m_nRectY0; }
	int getRectStep(void) const { return m_nRectStep; }

	void setRectStep(int nStep) { m_nRectStep = nStep; }

	void moveRectDown(void);
	void moveRectUp(void);

protected:
	int m_nRectX0; // 사각형의 x좌표
	int m_nRectY0; // 사각형의 y좌표
	int m_nRectWidth; // 사각형의 너비
	int m_nRectHeight;	// 사각형의 높이
	int m_nRectStep;	// 사각형 이동의 스텝

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

