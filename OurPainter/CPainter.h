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
	int getRectWid(void) const { return m_nRectWidth; }
	COLORREF getBackCol(void) const { return m_nBackCol; }

	void setRectStep(int nStep) { m_nRectStep = nStep; }
	void setRectWid(int nWid)
	{
		m_nRectWidth = nWid;
		Invalidate(TRUE);
	}
	void setBackCol(COLORREF col) { m_nBackCol = col; }

	void moveRectDown(void);
	void moveRectUp(void);

protected:
	int m_nRectX0; // 사각형의 x좌표
	int m_nRectY0; // 사각형의 y좌표
	int m_nRectWidth; // 사각형의 너비
	int m_nRectHeight;	// 사각형의 높이
	int m_nRectStep;	// 사각형 이동의 스텝
	COLORREF m_nBackCol;	// 배경색의 저장 공간: color reference(RGB); RGB 매크로를 써서 R, G, B를 각각 8비트(0~255)씩 입력
	COLORREF m_nRectCol;	// 사각형의 색깔
	COLORREF m_nRectLineCol;	// 사각형 윤곽선의 색깔

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

