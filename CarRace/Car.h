#pragma once
class Car
{
public:
	Car(void);
	~Car()
	{}

	void draw(CDC* pDC);

protected:
	CPoint m_pt;	// �ڵ����� �߽���
	int m_nWid;
	int m_nHt;

	int m_nId;
};

