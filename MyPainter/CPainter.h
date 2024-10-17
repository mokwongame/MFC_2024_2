#pragma once

#include <afxwin.h>

#define MAX_RECT_WID	(300)
#define MAX_RECT_HT		(250)
#define FLOW_RECT_STEP	(1)

class CPainter :
	public CStatic
{
public:
	CPainter(void); // ������(constructor)

	// public ���
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
	// protected ���
	int m_nRectX0; // �簢���� ���� X ��ǥ
	int m_nRectY0; // �簢���� ���� Y ��ǥ
	int m_nRectWid;	// �簢���� ����(width)
	int m_nRectHt;	// �簢���� ����(height)
	int m_nRectStep;	// �簢�� �̵��� ����(step)
	int m_nBallX0;	// ���� ���� X ��ǥ
	int m_nBallY0;	// ���� ���� Y ��ǥ
	int m_nBallStep;	// �� �̵��� ����
	COLORREF m_rectCol;	// �簢���� ����
	COLORREF m_rectLineCol;	// �簢�� �ܰ����� ����

	COLORREF m_backCol;	// ����

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

