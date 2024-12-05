#pragma once

class Road
{
public:
	Road(void);
	~Road()
	{
	}

	// getter
	CRect getRect(void) const
	{
		return m_rect;
	}
	int getCurbSize(void) const
	{
		return m_nCurbSize;
	}

	// setter
	void setRect(const CRect& rect)
	{
		m_rect = rect;
	}

	void drawBack(CDC* pDC);
	void drawAllLines(CDC* pDC);

	void moveDown(void);

	int top(void) const
	{
		return m_rect.top;
	}
	int bottom(void) const
	{
		return m_rect.bottom;
	}
	void incStep(void)
	{
		m_nLineStep++;
	}
	void decStep(void)
	{
		m_nLineStep--;
		if (m_nLineStep <= 0) m_nLineStep = 1;
	}

protected:
	CRect m_rect;
	int m_nLineWid;
	int m_nLineHt;
	int m_nLaneSize;
	int m_nCurbSize;
	int m_nLineOffset;
	int m_nLineStep;

	COLORREF m_nRoadCol;
	COLORREF m_nLineCol;
	COLORREF m_nCurbCol;

	void drawLine(CDC* pDC, int x);
};

