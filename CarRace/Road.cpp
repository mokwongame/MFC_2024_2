#include "pch.h"
#include "Road.h"

Road::Road(void)
{
	m_nRoadCol = RGB(0, 0, 0);
	m_nCurbCol = RGB(255, 0, 0);
	m_nLineCol = RGB(255, 255, 0);

	m_nCurbSize = 20;
	m_nLineWid = 10;
	m_nLineHt = 60;
	m_nLaneSize = 100;
	m_nLineOffset = 0;
	m_nMoveStep = 5;
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

void Road::drawAllLines(CDC* pDC)
{
	int nLineCount = (m_rect.Width() - m_nCurbSize * 2) / m_nLaneSize;
	for (int i = 1; i <= nLineCount; i++)
	{
		int x = m_nCurbSize + i * m_nLaneSize;
		drawLine(pDC, x);
	}
}

void Road::moveDown(void)
{
	m_nLineOffset += m_nMoveStep;
	if (m_nLineOffset >= m_rect.Height())
		m_nLineOffset = 0;
}

void Road::drawLine(CDC* pDC, int x)
{
	CBrush brush;
	brush.CreateSolidBrush(m_nLineCol);
	CPen pen;
	pen.CreatePen(PS_NULL, 0, RGB(0, 0, 0));
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	CPen* pOldPen = pDC->SelectObject(&pen);

	CRect rect;
	// bottom lines
	int y = m_nLineOffset;
	while (1)
	{
		if (y >= m_rect.bottom) break;
		rect = CRect(x - m_nLineWid / 2, y, x + m_nLineWid / 2, y + m_nLineHt);
		pDC->Rectangle(rect);
		y += m_nLineHt * 2;
	}
	// top lines
	y = m_nLineOffset - m_nLineHt;
	while (1)
	{
		if (y <= 0) break;
		rect = CRect(x - m_nLineWid / 2, y - m_nLineHt, x + m_nLineWid / 2, y);
		pDC->Rectangle(rect);
		y -= m_nLineHt * 2;
	}

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}
