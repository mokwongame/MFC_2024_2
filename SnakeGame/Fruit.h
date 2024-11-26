#pragma once

class Fruit
{
public:
	Fruit(void)
	{}
	~Fruit()
	{}

	bool getEnable(void) const
	{
		return m_bEnable;
	}

	void setEnable(bool bEnable)
	{
		m_bEnable = bEnable;
	}

	void setClientRect(const CRect& rt)
	{
		m_rtClient = rt;
	}
	void setRandPt(void);
	void draw(CDC* pDC);
	bool isHit(const CRect& rect) const;

protected:
	int m_nWid = 95;
	int m_nHt = 82;
	CPoint m_pt;	// ��Ʈ���� �߽� ��ǥ
	CRect m_rect;	// �浹 �׽�Ʈ��
	CRect m_rtClient;	// ���� �߻���
	bool m_bEnable = true;	// Fruit�� ���� �� �ִ°�
	CRect makeRect(void) const;
};

