#include "pch.h"
#include "Wall.h"

void Wall::draw(CDC* pDC)
{
	CBrush brush;
	brush.CreateHatchBrush(HS_DIAGCROSS, RGB(255, 0, 0));
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	CPen pen;
	pen.CreatePen(PS_NULL, 0, RGB(0, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);

	pDC->Rectangle(m_rect.left, m_rect.top, m_rect.right, m_rect.top + m_nThick);
	pDC->Rectangle(m_rect.left, m_rect.bottom - m_nThick, m_rect.right, m_rect.bottom);
	pDC->Rectangle(m_rect.left, m_rect.top, m_rect.left + m_nThick, m_rect.bottom);
	pDC->Rectangle(m_rect.right - m_nThick, m_rect.top, m_rect.right, m_rect.bottom);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

bool Wall::isHit(const CRect& rect) const
{
	if (rect.left <= m_rect.left + m_nThick || rect.right >= m_rect.right - m_nThick || rect.top <= m_rect.top + m_nThick || rect.bottom >= m_rect.bottom - m_nThick) return true;
	else return false;
}
