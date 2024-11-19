#include "pch.h"
#include "Fruit.h"
#include "resource.h"
#include "SnakeGameFun.h"

void Fruit::setRandPt(void)
{
	m_pt.x = randrange(m_rtClient.left + m_nWid, m_rtClient.right - m_nWid);
	m_pt.y = randrange(m_rtClient.top + m_nHt, m_rtClient.bottom - m_nHt);
	m_rect = makeRect();
}

void Fruit::draw(CDC* pDC)
{
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_FRUIT);
	CDC memDc;
	memDc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	CPoint pt = m_rect.TopLeft();
	// SRCAND: 배경과 현재 비트맵을 AND로 연산
	pDC->BitBlt(pt.x, pt.y, m_nWid, m_nHt, &memDc, 0, 0, SRCAND);
	memDc.SelectObject(pOldBitmap);
}

CRect Fruit::makeRect(void) const
{
	return CRect(m_pt.x - m_nWid / 2, m_pt.y - m_nHt / 2, m_pt.x + m_nWid / 2, m_pt.y + m_nHt / 2); // (l, t), (r, b) 순서로 입력
}
