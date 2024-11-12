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
	CPoint m_pt;	// Snake�� �߽���
	CRect m_rect;	// ��Ʈ���� ��ġ
	SnakeDir m_nDir = SnakeDir::DEF_NULL;

	CRect makeRect(void) const
	{
		return CRect(m_pt.x - m_nWid / 2, m_pt.y - m_nHt / 2, m_pt.x + m_nWid / 2, m_pt.y + m_nHt / 2); // (l, t), (r, b)�� ��ǥ�� ����
	}
};

