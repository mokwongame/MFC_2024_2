#pragma once
class Road
{
public:
	Road(void);
	~Road()
	{}

	// setter
	void setRect(const CRect& rect)
	{
		m_rect = rect;
	}

	void drawBack(CDC* pDC);

protected:
	CRect m_rect;
	COLORREF m_nRoadCol;
	COLORREF m_nCurbCol;
	int m_nCurbSize;
};

