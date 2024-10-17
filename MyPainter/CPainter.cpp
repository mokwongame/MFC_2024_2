#include "pch.h"
#include "CPainter.h"
#include "resource.h"

BEGIN_MESSAGE_MAP(CPainter, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

CPainter::CPainter(void)
{
	m_nRectX0 = 50;
	m_nRectY0 = 100;
	m_nRectWid = 200;
	m_nRectHt = 100;
	m_nRectStep = 10;
	m_rectCol = RGB(255, 0, 0);
	m_rectLineCol = RGB(0, 0, 255);

	m_nBallX0 = 0;
	m_nBallY0 = 0;
	m_nBallStep = m_nRectStep;

	m_backCol = RGB(255, 255, 255);
}

void CPainter::moveRectUp(void)
{
	m_nRectY0 -= m_nRectStep;
	Invalidate(TRUE); // ���� window ��� ������ ��ȿȭ; ��ȿ�� WM_PAINT �޽����� �߻�
}

void CPainter::moveRectDown(void)
{
	m_nRectY0 += m_nRectStep;
	Invalidate(TRUE); // ���� window ��� ������ ��ȿȭ; ��ȿ�� WM_PAINT �޽����� �߻�
}

void CPainter::moveRectLeft(void)
{
	m_nRectX0 -= m_nRectStep;
	Invalidate(TRUE); // ���� window ��� ������ ��ȿȭ; ��ȿ�� WM_PAINT �޽����� �߻�
}

void CPainter::moveRectRight(void)
{
	m_nRectX0 += m_nRectStep;
	Invalidate(TRUE); // ���� window ��� ������ ��ȿȭ; ��ȿ�� WM_PAINT �޽����� �߻�
}

void CPainter::flowRectRight(void)
{
	m_nRectX0 += FLOW_RECT_STEP;
	Invalidate(TRUE);
}

void CPainter::moveBallUp(void)
{
	m_nBallY0 -= m_nBallStep;
	Invalidate(TRUE);
}

void CPainter::moveBallDown(void)
{
	m_nBallY0 += m_nBallStep;
	Invalidate(TRUE);
}

void CPainter::moveBallLeft(void)
{
	m_nBallX0 -= m_nBallStep;
	Invalidate(TRUE);
}

void CPainter::moveBallRight(void)
{
	m_nBallX0 += m_nBallStep;
	Invalidate(TRUE);
}

// CDialog ���� WM_PAINT
// CView ���� WM_DRAW
void CPainter::OnPaint() // ����Ʈ(paint)�� �� ��(on)
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
	CBrush brush;
	brush.CreateSolidBrush(m_rectCol);
	CBrush* pOldBrush;
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, m_rectLineCol);
	CPen* pOldPen;

	// �簢�� �׸���
	pOldBrush = dc.SelectObject(&brush);
	pOldPen = dc.SelectObject(&pen);
	dc.Rectangle(m_nRectX0, m_nRectY0, m_nRectX0 + m_nRectWid, m_nRectY0 + m_nRectHt);
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);

	// ��Ʈ�� �׸���(����ũ �׸���)
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BALL_MASK);
	CBitmap* pOldBitmap;
	CDC memDc; // memory DC
	memDc.CreateCompatibleDC(&dc);
	pOldBitmap = memDc.SelectObject(&bitmap);
	// SRCCOPY: source copy; ���� ���ٸ� ������� ��Ʈ���� �״�� ȭ�� �׸�
	// AND ����: SRCAND; 0(������) & b = 0; 1(���) & b = b
	// OR ����: SRCPAINT; 0(������) | b = b; 1(���) | b = 1
	dc.BitBlt(m_nBallX0, m_nBallY0, 150, 150, &memDc, 0, 0, SRCAND); // ��Ʈ(bit)�� ���(block) ������ �̼�(transfer)
	// ��Ʈ�� �׸���(��ü �׸���)
	bitmap.DeleteObject();
	// ��Ʈ�� �׸���(����ũ �׸���)
	bitmap.LoadBitmap(IDB_BALL_OBJ);
	memDc.SelectObject(&bitmap);
	dc.BitBlt(m_nBallX0, m_nBallY0, 150, 150, &memDc, 0, 0, SRCPAINT);
	memDc.SelectObject(pOldBitmap);
}


BOOL CPainter::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ������ ������ ä�� ���� CBrush
	CBrush brush;
	brush.CreateSolidBrush(m_backCol); // brush�� ���ϻ����� ����; �Է��� color reference(RGB�� ǥ���ϴ� ����: 8��Ʈ*3 = 24��Ʈ = 2^24)
	CBrush* pOldBrush = pDC->SelectObject(&brush); // &�ǹ�: ������(�ּ�)�� ����
	CRect rect;
	GetClientRect(rect); // Ŭ���̾�Ʈ(client)�� �簢��(rect) ���� ���(get)
	pDC->FillRect(rect, &brush);
	pDC->SelectObject(pOldBrush); // ���� brush�� �ٽ� ����
	return CStatic::OnEraseBkgnd(pDC);
}
