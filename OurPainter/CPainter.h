#pragma once

#include <afxwin.h>

// Ŭ���� ������ ȣ��: Ctrl+Shift+X; ������Ʈ > Ŭ���� ������
class CPainter :
	public CStatic
{
public:
	CPainter(void);

protected:
	int m_nRectX0; // �簢���� x��ǥ
	int m_nRectY0; // �簢���� y��ǥ
	int m_nRectWidth; // �簢���� �ʺ�
	int m_nRectHeight;	// �簢���� ����

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

