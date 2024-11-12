#pragma once
class Wall
{
public:
	Wall(void)
	{}
	~Wall()
	{}

	void setRect(const CRect& rect)
	{
		m_rect = rect;
	}

	void draw(CDC* pDC);

protected:
	CRect m_rect;
	int m_nThick = 10;
};

