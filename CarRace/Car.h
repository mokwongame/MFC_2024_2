#pragma once
class Car
{
public:
	Car(void);
	~Car()
	{}

	void draw(CDC* pDC);

	// getter
	int getWid(void) const
	{
		return m_nWid;
	}

	bool getEnable(void) const
	{
		return m_bEnable;
	}

	int getHt(void) const
	{
		return m_nHt;
	}

	// setter
	void setBitmap(int nId, int nWid, int nHt)
	{
		m_nId = nId;
		m_nWid = nWid;
		m_nHt = nHt;
	}

	void setPt(const CPoint& pt)
	{
		m_pt = pt;
	}

	void setStep(int step)
	{
		m_step = step;
	}

	void setEnable(bool bEnable)
	{
		m_bEnable = bEnable;
	}

	void move(int dx, int dy)
	{
		m_pt += CPoint(dx, dy);
	}

	void moveLeft(void)
	{
		move(-m_step, 0);
	}

	void moveRight(void)
	{
		move(m_step, 0);
	}

	void moveDown(void)
	{
		move(0, m_step);
	}

	int top(void) const
	{
		return m_pt.y - m_nHt / 2;
	}

protected:
	CPoint m_pt;	// 자동차의 중심점
	int m_nWid;
	int m_nHt;
	int m_step;

	int m_nId;
	bool m_bEnable;
};

