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
	// SRCAND: 배경과 현재 비트맵을 AND로 연산
	pDC->BitBlt(pt.x, pt.y, m_nWid, m_nHt, &memDc, 0, 0, SRCAND);
	memDc.SelectObject(pOldBitmap);
}

void Snake::move(void)
{
	switch (m_nDir)
	{
	case SnakeDir::LEFT:
		m_pt.x -= m_step;
		break;
	case SnakeDir::RIGHT:
		m_pt.x += m_step;
		break;
	case SnakeDir::UP:
		m_pt.y -= m_step;
		break;
	case SnakeDir::DOWN:
		m_pt.y += m_step;
		break;
	}
	if (m_nDir != SnakeDir::NULL_DEF) m_rect = makeRect();
}

CRect Snake::makeRect(void) const
{
	return CRect(m_pt.x - m_nWid / 2, m_pt.y - m_nHt / 2, m_pt.x + m_nWid / 2, m_pt.y + m_nHt / 2); // (l, t), (r, b) 순서로 입력
}
