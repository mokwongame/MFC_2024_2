#include "pch.h"
#include "CPainter.h"

BEGIN_MESSAGE_MAP(CPainter, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CPainter::OnPaint() // WM_PAINT �޽����� �߻��� �� ó���ϴ� �Լ�
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
	dc.Rectangle(0, 0, 100, 200); // �簢�� �׸���
}
