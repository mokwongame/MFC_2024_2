#include "pch.h"
#include "Snake.h"
#include "resource.h"

void Snake::draw(CDC* pDC)
{
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_SNAKE);
	CDC memDc;
	memDc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	CPoint pt = m_rect.TopLeft();
	// SRCAND: ���� ���� ��Ʈ���� AND�� ����
	pDC->BitBlt(pt.x, pt.y, m_nWid, m_nHt, &memDc, 0, 0, SRCAND);
	memDc.SelectObject(pOldBitmap);
}

CRect Snake::makeRect(void) const
{
	return CRect(m_pt.x - m_nWid / 2, m_pt.y - m_nHt / 2, m_pt.x + m_nWid / 2, m_pt.y + m_nHt / 2); // (l, t), (r, b) ������ �Է�
}