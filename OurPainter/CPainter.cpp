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
	Invalidate(TRUE); // 무효화하다
}

void CPainter::moveRectUp(void)
{
	m_nRectY0 -= m_nRectStep;
	Invalidate(TRUE); // 무효화하다
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

void CPainter::OnPaint() // WM_PAINT 메시지가 발생할 때 처리하는 함수
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	// 사각형 그리기
	CBrush brush;
	brush.CreateSolidBrush(m_nRectCol);
	CBrush* pOldBrush = dc.SelectObject(&brush);
	CPen pen;
	pen.CreatePen(PS_SOLID, 3, m_nRectLineCol);
	CPen* pOldPen = dc.SelectObject(&pen);
	dc.Rectangle(m_nRectX0, m_nRectY0, m_nRectX0 + m_nRectWidth, m_nRectY0 + m_nRectHeight); // 사각형 그리기
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);

	// 비트맵 그리기
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_SPACE);
	CDC memDc; // 메모리에 먼저 그리는 걸 도와주는 DC
	memDc.CreateCompatibleDC(&dc);
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	// bit blt: bit block transfer - 비트 블록(bit block)를 통쳐로 화면으로 전송(transfer)
	// SRCCOPY: 비트맵으로 덮어쓰기
	dc.BitBlt(m_nBitX0, m_nBitY0, 150, 150, &memDc, 0, 0, SRCCOPY);
	memDc.SelectObject(pOldBitmap);
}


BOOL CPainter::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CBrush brush;
	//brush.CreateSolidBrush(RGB(255, 255, 255));  // 흰색: RGB(255, 255, 255)
	brush.CreateSolidBrush(m_nBackCol);
	//CBrush* pOldBrush = pDC->SelectObject(&brush); // & 의미: brush의 포인터(주소)
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect, &brush);
	//pDC->SelectObject(pOldBrush); // brush를 원상 복구

	return CStatic::OnEraseBkgnd(pDC);
}
