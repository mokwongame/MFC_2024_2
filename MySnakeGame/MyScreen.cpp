#include "pch.h"
#include "MyScreen.h"
#include "resource.h"
#include "SnakeGameFun.h"

BEGIN_MESSAGE_MAP(MyScreen, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


BOOL MyScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ��� �߰�: �ȼ� (1000*370)�� ���̾�α׿��� (571*211)�� �ٲ�
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_JUNGLE);
	CDC memDc;
	memDc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	pDC->BitBlt(0, 0, m_nBkWid, m_nBkHt, &memDc, 0, 0, SRCCOPY);
	memDc.SelectObject(pOldBitmap);

	// �� �׸���
	m_wall.draw(pDC);

	return CStatic::OnEraseBkgnd(pDC);
}


void MyScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
	if (m_bGameOver)
	{
		drawGameOver(&dc);
		return;
	}

	if (!m_fruit.getEnable()) // ���� ������ ���� ����
	{
		m_fruit.setRandPt();
		m_fruit.setEnable(true);
	}
	m_fruit.draw(&dc);
	m_snake.draw(&dc);
	drawScore(&dc);
}


void MyScreen::drawScore(CDC* pDC)
{
	CString str;
	str.Format(_T("���� = %d"), getScore());
	COLORREF oldTextCol = pDC->SetTextColor(RGB(0, 0, 255));
	COLORREF oldBkCol = pDC->SetBkColor(RGB(0, 255, 0));
	pDC->TextOut(100, 100, str);
	pDC->SetTextColor(oldTextCol);
	pDC->SetBkColor(oldBkCol);
}

void MyScreen::drawGameOver(CDC* pDC)
{
	COLORREF oldTextCol = pDC->SetTextColor(RGB(0, 0, 255));
	COLORREF oldBkCol = pDC->SetBkColor(RGB(0, 255, 0));
	pDC->TextOut(500, 150, _T("Game Over!"));
	pDC->SetTextColor(oldTextCol);
	pDC->SetBkColor(oldBkCol);
}

BOOL MyScreen::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	BOOL bResult = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
	CRect rtClient;
	GetClientRect(rtClient);
	m_wall.setRect(rtClient);
	m_snake.setPt(rtClient.CenterPoint());
	m_fruit.setClientRect(rtClient);
	m_fruit.setRandPt();
	m_fruit.setEnable(true);
	return bResult;
}


void MyScreen::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == TIMER_SCREEN)
	{
		m_snake.move();
		if (m_fruit.isHit(m_snake.getRect())) // ������ �Ծ ����
		{
			incScore();
			m_fruit.setEnable(false);
		}
		else if (m_wall.isHit(m_snake.getRect()))
		{
			m_bGameOver = true;
		}
		Invalidate(TRUE);
	}

	CStatic::OnTimer(nIDEvent);
}
