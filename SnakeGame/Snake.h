#pragma once

enum class SnakeDir
{
	NULL_DEF = 0, LEFT, RIGHT, UP, DOWN
};

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
	void setDir(SnakeDir nDir)
	{
		m_nDir = nDir;
	}

	void draw(CDC* pDC);
	void move(void);

protected:
	int m_nWid = 100;
	int m_nHt = 89;
	int m_step = 5;	// snake이 움직일 간격
	CPoint m_pt;	// 비트맵의 중심 좌표
	CRect m_rect;	// 충돌 테스트용
	SnakeDir m_nDir = SnakeDir::NULL_DEF;

	CRect makeRect(void) const;
};

