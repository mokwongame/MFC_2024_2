#pragma once

class Snake
{
public:
	Snake(void)
	{}
	~Snake()
	{}

	void setPt(const CPoint& pt)
	{
		m_pt = pt;
		m_rect = makeRect();
	}

	void draw(CDC* pDC);

protected:
	int m_nWid = 100;
	int m_nHt = 89;
	CPoint m_pt;	// 비트맵의 중심 좌표
	CRect m_rect;	// 충돌 테스트용

	CRect makeRect(void) const;
};

