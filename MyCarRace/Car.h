#pragma once

class Car
{
public:
	Car(void)
	{
		m_nStep = 1;
		m_bEnable = true;
	}
	~Car()
	{
	}

	// getter
	int getWid(void) const
	{
		return m_nWid;
	}
	int getHt(void) const
	{
		return m_nHt;
	}
	int getStep(void) const
	{
		return m_nStep;
	}
	bool getEnable(void) const
	{
		return m_bEnable;
	}

	// setter
	void setBitmap(int nId, int nWid, int nHt)
	{
		m_nId = nId;
		m_nWid = nWid;
		m_nHt = nHt;
	}
	void setPt(const CPoint& pt) // ¡ﬂΩ…¡°
	{
		m_pt = pt;
	}
	void setStep(int nStep)
	{
		m_nStep = nStep;
	}
	void setEnable(bool bEnable)
	{
		m_bEnable = bEnable;
	}

	void draw(CDC* pDC);

	void move(int dx, int dy)
	{
		m_pt += CPoint(dx, dy);
	}
	void moveLeft(void)
	{
		move(-m_nStep, 0);
	}
	void moveRight(void)
	{
		move(m_nStep, 0);
	}
	void moveDown(void)
	{
		move(0, m_nStep);
	}

	int top(void) const
	{
		return m_pt.y - m_nHt / 2;
	}
	void incStep(void)
	{
		m_nStep++;
	}
	void decStep(void)
	{
		m_nStep--;
		if (m_nStep <= 0) m_nStep = 1;
	}

	CRect makeRect(void) const;

protected:
	CPoint m_pt;
	int m_nWid;
	int m_nHt;
	int m_nStep;

	int m_nId;
	bool m_bEnable;
};

