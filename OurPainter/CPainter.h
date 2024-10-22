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

	void setRectStep(int nStep) { m_nRectStep = nStep; }

	void moveRectDown(void);
	void moveRectUp(void);

protected:
	int m_nRectX0; // �簢���� x��ǥ
	int m_nRectY0; // �簢���� y��ǥ
	int m_nRectWidth; // �簢���� �ʺ�
	int m_nRectHeight;	// �簢���� ����
	int m_nRectStep;	// �簢�� �̵��� ����

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

