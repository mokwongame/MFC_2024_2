#pragma once

#include <afxwin.h>

// Ŭ���� ������ ȣ��: Ctrl+Shift+X; ������Ʈ > Ŭ���� ������
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
	int m_nRectX0; // �簢���� x��ǥ
	int m_nRectY0; // �簢���� y��ǥ
	int m_nRectWidth; // �簢���� �ʺ�
	int m_nRectHeight;	// �簢���� ����
	int m_nRectStep;	// �簢�� �̵��� ����
	COLORREF m_nBackCol;	// ������ ���� ����: color reference(RGB); RGB ��ũ�θ� �Ἥ R, G, B�� ���� 8��Ʈ(0~255)�� �Է�
	COLORREF m_nRectCol;	// �簢���� ����
	COLORREF m_nRectLineCol;	// �簢�� �������� ����

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

