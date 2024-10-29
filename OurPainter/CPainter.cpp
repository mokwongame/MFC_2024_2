#include "pch.h"
#include "CPainter.h"

BEGIN_MESSAGE_MAP(CPainter, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


CPainter::CPainter(void)
{
	m_nRectX0 = 10;
	m_nRectY0 = 20;
	m_nRectWidth = 150;
	m_nRectHeight = 100;
	m_nRectStep = 5;
	m_nBackCol = RGB(0, 255, 0); // green color
}

void CPainter::moveRectDown(void)
{
	m_nRectY0 += m_nRectStep;
	Invalidate(TRUE); // ��ȿȭ�ϴ�
}

void CPainter::moveRectUp(void)
{
	m_nRectY0 -= m_nRectStep;
	Invalidate(TRUE); // ��ȿȭ�ϴ�
}

void CPainter::OnPaint() // WM_PAINT �޽����� �߻��� �� ó���ϴ� �Լ�
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
	dc.Rectangle(m_nRectX0, m_nRectY0, m_nRectX0 + m_nRectWidth, m_nRectY0 + m_nRectHeight); // �簢�� �׸���
}


BOOL CPainter::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CBrush brush;
	//brush.CreateSolidBrush(RGB(255, 255, 255));  // ���: RGB(255, 255, 255)
	brush.CreateSolidBrush(m_nBackCol);
	//CBrush* pOldBrush = pDC->SelectObject(&brush); // & �ǹ�: brush�� ������(�ּ�)
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect, &brush);
	//pDC->SelectObject(pOldBrush); // brush�� ���� ����

	return CStatic::OnEraseBkgnd(pDC);
}
