#include "pch.h"
#include "Car.h"

Car::Car(void)
{
	m_nWid = 0;
	m_nHt = 0;

	m_nId = NULL;
}

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
