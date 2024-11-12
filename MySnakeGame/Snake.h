#pragma once

enum class SnakeDir
{
	DEF_NULL, LEFT, RIGHT, UP, DOWN
};

class Snake
{
public:
	Snake(void)
	{}
	~Snake()
	{}

	CRect getRect(void) const
	{
		return m_rect;
	}

	void setPt(const CPoint& pt)
	{
		m_pt = pt;
		m_rect = makeRect();
	}

	void setDir(SnakeDir nDir)
	{
		m_nDir = nDir;
	}

	void draw(CDC* pDC);
	void move(void);

protected:
	int m_nWid = 100;
	int m_nHt = 89;
	int m_nStep = 3;
	CPoint m_pt;	// Snake의 중심점
	CRect m_rect;	// 비트맵의 위치
	SnakeDir m_nDir = SnakeDir::DEF_NULL;

	CRect makeRect(void) const
	{
		return CRect(m_pt.x - m_nWid / 2, m_pt.y - m_nHt / 2, m_pt.x + m_nWid / 2, m_pt.y + m_nHt / 2); // (l, t), (r, b)의 좌표를 설정
	}
};

