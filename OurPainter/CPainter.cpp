#include "pch.h"
#include "CPainter.h"
#include "Resource.h"

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
	m_nRectCol = RGB(255, 0, 0);
	m_nRectLineCol = RGB(0, 0, 255);

	m_nBitX0 = 20;
	m_nBitY0 = 30;
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

void CPainter::moveBitDown(void)
{
	m_nBitY0 += m_nRectStep;
	Invalidate(TRUE);
}

void CPainter::moveBitUp(void)
{
	m_nBitY0 -= m_nRectStep;
	Invalidate(TRUE);
}

void CPainter::OnPaint() // WM_PAINT �޽����� �߻��� �� ó���ϴ� �Լ�
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
	// �簢�� �׸���
	CBrush brush;
	brush.CreateSolidBrush(m_nRectCol);
	CBrush* pOldBrush = dc.SelectObject(&brush);
	CPen pen;
	pen.CreatePen(PS_SOLID, 3, m_nRectLineCol);
	CPen* pOldPen = dc.SelectObject(&pen);
	dc.Rectangle(m_nRectX0, m_nRectY0, m_nRectX0 + m_nRectWidth, m_nRectY0 + m_nRectHeight); // �簢�� �׸���
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);

	// ��Ʈ�� �׸���
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_SPACE);
	CDC memDc; // �޸𸮿� ���� �׸��� �� �����ִ� DC
	memDc.CreateCompatibleDC(&dc);
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	// bit blt: bit block transfer - ��Ʈ ���(bit block)�� ���ķ� ȭ������ ����(transfer)
	// SRCCOPY: ��Ʈ������ �����
	dc.BitBlt(m_nBitX0, m_nBitY0, 150, 150, &memDc, 0, 0, SRCCOPY);
	memDc.SelectObject(pOldBitmap);
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
