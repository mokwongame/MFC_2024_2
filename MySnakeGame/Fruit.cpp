#include "pch.h"
#include "Fruit.h"
#include "resource.h"

bool Fruit::isHit(const CRect& rect)
{
	if (m_rect.PtInRect(rect.TopLeft()) || m_rect.PtInRect(rect.BottomRight()) || m_rect.PtInRect(CPoint(rect.left, rect.bottom)) || m_rect.PtInRect(CPoint(rect.right, rect.top))) return true;
	else if (rect.PtInRect(m_rect.TopLeft()) || rect.PtInRect(m_rect.BottomRight()) || rect.PtInRect(CPoint(m_rect.left, m_rect.bottom)) || rect.PtInRect(CPoint(m_rect.right, m_rect.top))) return true;
	else return false;
}

void Fruit::draw(CDC* pDC)
{
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_FRUIT);
	CDC memDc;
	memDc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	CPoint pt = m_rect.TopLeft();
	pDC->BitBlt(pt.x, pt.y, m_nWid, m_nHt, &memDc, 0, 0, SRCAND);
	memDc.SelectObject(pOldBitmap);
}
