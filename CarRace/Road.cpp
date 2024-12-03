#include "pch.h"
#include "Road.h"

Road::Road(void)
{
	m_nRoadCol = RGB(0, 0, 0);
	m_nCurbCol = RGB(255, 0, 0);

	m_nCurbSize = 20;
}

void Road::drawBack(CDC* pDC)
{
	// road
	CBrush brush;
	brush.CreateSolidBrush(m_nRoadCol);
	pDC->FillRect(m_rect, &brush);

	// curb
	CBrush brushCurb;
	brushCurb.CreateHatchBrush(HS_VERTICAL, m_nCurbCol);
	CRect rect1(m_rect.TopLeft(), CPoint(m_rect.left + m_nCurbSize, m_rect.bottom));
	pDC->FillRect(rect1, &brushCurb);
	CRect rect2(CPoint(m_rect.right - m_nCurbSize, m_rect.top), m_rect.BottomRight());
	pDC->FillRect(rect2, &brushCurb);
}
