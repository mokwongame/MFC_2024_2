#pragma once
class Car
{
public:
	Car(void);
	~Car()
	{}

	void draw(CDC* pDC);

protected:
	CPoint m_pt;	// 자동차의 중심점
	int m_nWid;
	int m_nHt;

	int m_nId;
};

