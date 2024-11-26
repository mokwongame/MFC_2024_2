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
		m_rect.right++;
		m_rect.bottom++;
	}

	void draw(CDC* pDC);
	bool isHit(const CRect& rect) const;

protected:
	CRect m_rect;
	int m_nThick = 10;
};

