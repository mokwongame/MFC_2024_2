#pragma once

class Fruit
{
public:
	Fruit(void)
	{}
	~Fruit()
	{}

	void setClientRect(const CRect& rt)
	{
		m_rtClient = rt;
	}
	void setRandPt(void);
	void draw(CDC* pDC);

protected:
	int m_nWid = 95;
	int m_nHt = 82;
	CPoint m_pt;	// ��Ʈ���� �߽� ��ǥ
	CRect m_rect;	// �浹 �׽�Ʈ��
	CRect m_rtClient;	// ���� �߻���

	CRect makeRect(void) const;
};

