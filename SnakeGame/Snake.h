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
	CPoint m_pt;	// ��Ʈ���� �߽� ��ǥ
	CRect m_rect;	// �浹 �׽�Ʈ��

	CRect makeRect(void) const;
};

