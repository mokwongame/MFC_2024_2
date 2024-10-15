#include "pch.h"
#include "CPainter.h"

BEGIN_MESSAGE_MAP(CPainter, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()


CPainter::CPainter(void)
{
	m_nRectX0 = 10;
	m_nRectY0 = 20;
	m_nRectWidth = 150;
	m_nRectHeight = 100;
}

void CPainter::OnPaint() // WM_PAINT �޽����� �߻��� �� ó���ϴ� �Լ�
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
	dc.Rectangle(m_nRectX0, m_nRectY0, m_nRectX0 + m_nRectWidth, m_nRectY0 + m_nRectHeight); // �簢�� �׸���
}
