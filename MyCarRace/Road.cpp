#include "pch.h"
#include "Road.h"

Road::Road(void)
{
	m_rect = CRect(CPoint(0, 0), CPoint(0, 0));
	m_nLineWid = 15;
	m_nLineHt = 70;
	m_nLaneSize = 100;
	m_nCurbSize = 20;
	m_nLineOffset = 0;
	m_nLineStep = 1;

	m_nRoadCol = RGB(0, 0, 0);
	m_nLineCol = RGB(255, 255, 255);
	m_nCurbCol = RGB(255, 0, 0);
}

void Road::drawBack(CDC* pDC)
{
	CBrush brush;
	brush.CreateSolidBrush(m_nRoadCol);
	pDC->FillRect(m_rect, &brush);

	CBrush brushCurb;
	brushCurb.CreateHatchBrush(HS_VERTICAL, m_nCurbCol);
	CBrush* pOldBrush = pDC->SelectObject(&brushCurb);
	CPen penCurb;
	penCurb.CreatePen(PS_NULL, 0, RGB(0, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&penCurb);
	pDC->Rectangle(CRect(m_rect.TopLeft(), CPoint(m_rect.left + m_nCurbSize, m_rect.bottom + 1)));
	pDC->Rectangle(CRect(CPoint(m_rect.right - m_nCurbSize, m_rect.top), CPoint(m_rect.right + 1, m_rect.bottom + 1)));
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

void Road::drawAllLines(CDC* pDC)
{
	int nLineCount = (m_rect.Width() - 2 * m_nCurbSize) / m_nLaneSize;
	for (int i = 1; i <= nLineCount; i++)
	{
		int x = i * m_nLaneSize + m_nCurbSize;
		drawLine(pDC, x);
	}
}

void Road::moveDown(void)
{
	m_nLineOffset += m_nLineStep;
	if (m_nLineOffset >= m_rect.Height()) m_nLineOffset = 0;
}

void Road::drawLine(CDC* pDC, int x)
{
	CBrush brush;
	brush.CreateSolidBrush(m_nLineCol);
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	CRect rect;
	int y = m_nLineOffset;
	while (1)
	{
		if (y > m_rect.bottom) break;
		rect = CRect(x - m_nLineWid / 2, y, x + m_nLineWid / 2, y + m_nLineHt);
		pDC->Rectangle(rect);
		y += 2 * m_nLineHt;
	}
	y = m_nLineOffset - 1 - m_nLineHt;
	while (1)
	{
		if (y < 0) break;
		rect = CRect(x - m_nLineWid / 2, y - m_nLineHt, x + m_nLineWid / 2, y);
		pDC->Rectangle(rect);
		y -= 2 * m_nLineHt;
	}
	pDC->SelectObject(pOldBrush);
}
