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

bool Fruit::isHit(const CRect& rect) const
{
	if (m_rect.PtInRect(rect.TopLeft()) || m_rect.PtInRect(rect.BottomRight()) || m_rect.PtInRect(CPoint(rect.left, rect.bottom)) || m_rect.PtInRect(CPoint(rect.right, rect.top))) return true;
	else if (rect.PtInRect(m_rect.TopLeft()) || rect.PtInRect(m_rect.BottomRight()) || rect.PtInRect(CPoint(m_rect.left, m_rect.bottom)) || rect.PtInRect(CPoint(m_rect.right, m_rect.top))) return true;
	else return false;
}

CRect Fruit::makeRect(void) const
{
	return CRect(m_pt.x - m_nWid / 2, m_pt.y - m_nHt / 2, m_pt.x + m_nWid / 2, m_pt.y + m_nHt / 2); // (l, t), (r, b) 순서로 입력
}
