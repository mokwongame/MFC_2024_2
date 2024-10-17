#pragma once

#include <afxwin.h>

#define MAX_RECT_WID	(300)
#define MAX_RECT_HT		(250)
#define FLOW_RECT_STEP	(1)

class CPainter :
	public CStatic
{
public:
	CPainter(void); // 생성자(constructor)

	// public 멤버
	int getRectX0(void) const { return m_nRectX0; }
	int getRectY0(void) const { return m_nRectY0; }
	int getRectStep(void) const { return m_nRectStep; }
	int getRectWid(void) const { return m_nRectWid; }
	int getRectHt(void) const { return m_nRectHt; }
	COLORREF getBackCol(void) const { return m_backCol; }
	void setRectBallStep(int nStep) { m_nRectStep = m_nBallStep = nStep; }
	void setRectWid(int nWid)
	{
		m_nRectWid = nWid;
		Invalidate(TRUE);
	}
	void setRectHt(int nHt)
	{
		m_nRectHt = nHt;
		Invalidate(TRUE);
	}
	void setBackCol(COLORREF nCol)
	{
		m_backCol = nCol;
		Invalidate(TRUE);
	}

	void moveRectUp(void);
	void moveRectDown(void);
	void moveRectLeft(void);
	void moveRectRight(void);

	void flowRectRight(void);

	void moveBallUp(void);
	void moveBallDown(void);
	void moveBallLeft(void);
	void moveBallRight(void);

protected:
	// protected 멤버
	int m_nRectX0; // 사각형의 시작 X 좌표
	int m_nRectY0; // 사각형의 시작 Y 좌표
	int m_nRectWid;	// 사각형의 길이(width)
	int m_nRectHt;	// 사각형의 높이(height)
	int m_nRectStep;	// 사각형 이동의 스텝(step)
	int m_nBallX0;	// 공의 시작 X 좌표
	int m_nBallY0;	// 공의 시작 Y 좌표
	int m_nBallStep;	// 공 이동의 스텝
	COLORREF m_rectCol;	// 사각형의 색깔
	COLORREF m_rectLineCol;	// 사각형 외곽선의 색깔

	COLORREF m_backCol;	// 배경색

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

