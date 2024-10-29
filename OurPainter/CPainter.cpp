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
	Invalidate(TRUE); // 무효화하다
}

void CPainter::moveRectUp(void)
{
	m_nRectY0 -= m_nRectStep;
	Invalidate(TRUE); // 무효화하다
}

void CPainter::OnPaint() // WM_PAINT 메시지가 발생할 때 처리하는 함수
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	dc.Rectangle(m_nRectX0, m_nRectY0, m_nRectX0 + m_nRectWidth, m_nRectY0 + m_nRectHeight); // 사각형 그리기
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
