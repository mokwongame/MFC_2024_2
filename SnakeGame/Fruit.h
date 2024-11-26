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
	CPoint m_pt;	// 비트맵의 중심 좌표
	CRect m_rect;	// 충돌 테스트용
	CRect m_rtClient;	// 난수 발생용
	bool m_bEnable = true;	// Fruit을 먹을 수 있는가
	CRect makeRect(void) const;
};

