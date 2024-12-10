#pragma once
class Road
{
public:
	Road(void);
	~Road()
	{}

	// getter
	CRect getRect(void) const
	{
		return m_rect;
	}

	// setter
	void setRect(const CRect& rect)
	{
		m_rect = rect;
	}

	void drawBack(CDC* pDC);
	void drawAllLines(CDC* pDC);

	void moveDown(void);

	int bottom(void) const
	{
		return m_rect.bottom;
	}

protected:
	CRect m_rect;
	COLORREF m_nRoadCol;
	COLORREF m_nCurbCol;
	COLORREF m_nLineCol;
	int m_nCurbSize;
	int m_nLineWid;
	int m_nLineHt;
	int m_nLaneSize;
	int m_nLineOffset;
	int m_nMoveStep;

	void drawLine(CDC* pDC, int x);
};

