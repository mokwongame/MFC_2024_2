#include "pch.h"
#include "Car.h"

void Car::draw(CDC* pDC)
{
	CBitmap bitmap;
	bitmap.LoadBitmap(m_nId);
	CDC memDc;
	memDc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	pDC->BitBlt(m_pt.x - m_nWid / 2, m_pt.y - m_nHt / 2, m_nWid, m_nHt, &memDc, 0, 0, SRCCOPY);
	memDc.SelectObject(pOldBitmap);
}

CRect Car::makeRect(void) const
{
	return CRect(m_pt.x - m_nWid / 2, m_pt.y - m_nHt / 2, m_pt.x + m_nWid / 2, m_pt.y + m_nHt / 2);
}
