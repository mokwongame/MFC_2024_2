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
	Invalidate(TRUE); // 현재 window 담당 영역을 무효화; 무효라서 WM_PAINT 메시지가 발생
}

void CPainter::moveRectDown(void)
{
	m_nRectY0 += m_nRectStep;
	Invalidate(TRUE); // 현재 window 담당 영역을 무효화; 무효라서 WM_PAINT 메시지가 발생
}

void CPainter::moveRectLeft(void)
{
	m_nRectX0 -= m_nRectStep;
	Invalidate(TRUE); // 현재 window 담당 영역을 무효화; 무효라서 WM_PAINT 메시지가 발생
}

void CPainter::moveRectRight(void)
{
	m_nRectX0 += m_nRectStep;
	Invalidate(TRUE); // 현재 window 담당 영역을 무효화; 무효라서 WM_PAINT 메시지가 발생
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

// CDialog 경우는 WM_PAINT
// CView 경우는 WM_DRAW
void CPainter::OnPaint() // 페인트(paint)를 할 때(on)
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	CBrush brush;
	brush.CreateSolidBrush(m_rectCol);
	CBrush* pOldBrush;
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, m_rectLineCol);
	CPen* pOldPen;

	// 사각형 그리기
	pOldBrush = dc.SelectObject(&brush);
	pOldPen = dc.SelectObject(&pen);
	dc.Rectangle(m_nRectX0, m_nRectY0, m_nRectX0 + m_nRectWid, m_nRectY0 + m_nRectHt);
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);

	// 비트맵 그리기(마스크 그리기)
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BALL_MASK);
	CBitmap* pOldBitmap;
	CDC memDc; // memory DC
	memDc.CreateCompatibleDC(&dc);
	pOldBitmap = memDc.SelectObject(&bitmap);
	// SRCCOPY: source copy; 배경과 별다른 연산없이 비트맵을 그대로 화면 그림
	// AND 연산: SRCAND; 0(검정색) & b = 0; 1(흰색) & b = b
	// OR 연산: SRCPAINT; 0(검정색) | b = b; 1(흰색) | b = 1
	dc.BitBlt(m_nBallX0, m_nBallY0, 150, 150, &memDc, 0, 0, SRCAND); // 비트(bit)를 블록(block) 단위로 이송(transfer)
	// 비트맵 그리기(물체 그리기)
	bitmap.DeleteObject();
	// 비트맵 그리기(마스크 그리기)
	bitmap.LoadBitmap(IDB_BALL_OBJ);
	memDc.SelectObject(&bitmap);
	dc.BitBlt(m_nBallX0, m_nBallY0, 150, 150, &memDc, 0, 0, SRCPAINT);
	memDc.SelectObject(pOldBitmap);
}


BOOL CPainter::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 색깔을 도형에 채울 때는 CBrush
	CBrush brush;
	brush.CreateSolidBrush(m_backCol); // brush를 단일색으로 생성; 입력은 color reference(RGB를 표현하는 정수: 8비트*3 = 24비트 = 2^24)
	CBrush* pOldBrush = pDC->SelectObject(&brush); // &의미: 포인터(주소)를 생성
	CRect rect;
	GetClientRect(rect); // 클라이언트(client)의 사각형(rect) 영역 얻기(get)
	pDC->FillRect(rect, &brush);
	pDC->SelectObject(pOldBrush); // 원래 brush를 다시 선택
	return CStatic::OnEraseBkgnd(pDC);
}
