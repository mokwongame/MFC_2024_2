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
	pDC->BitBlt(pt.x, pt.y, m_nWid, m_nHt, &memDc, 0, 0, SRCAND);
	memDc.SelectObject(pOldBitmap);
}

void Snake::move(void)
{
	switch (m_nDir)
	{
	case SnakeDir::LEFT:
		m_pt.x -= m_nStep;
		break;
	case SnakeDir::RIGHT:
		m_pt.x += m_nStep;
		break;
	case SnakeDir::UP:
		m_pt.y -= m_nStep;
		break;
	case SnakeDir::DOWN:
		m_pt.y += m_nStep;
		break;
	}
	m_rect = makeRect();
}
