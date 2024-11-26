#include "pch.h"
#include "GameScreen.h"
#include "resource.h"

BEGIN_MESSAGE_MAP(GameScreen, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


void GameScreen::drawScore(CDC* pDC)
{
	CString str;
	str.Format(_T("score = %d"), m_nScore);
	CFont font;
	font.CreatePointFont(200, _T("맑은 고딕"));
	CFont* pOldFont;
	COLORREF oldTextCol = pDC->GetTextColor();
	COLORREF oldBkCol = pDC->GetBkColor();
	pDC->SetTextColor(RGB(255, 0, 0));
	pDC->SetBkColor(RGB(0, 255, 255));
	pOldFont = pDC->SelectObject(&font);
	pDC->TextOut(100, 100, str);
	pDC->SetTextColor(oldTextCol);
	pDC->SetBkColor(oldBkCol);
	pDC->SelectObject(pOldFont);
}

void GameScreen::drawGameOver(CDC* pDC)
{
	CFont font;
	font.CreatePointFont(200, _T("맑은 고딕"));
	CFont* pOldFont;
	COLORREF oldTextCol = pDC->GetTextColor();
	COLORREF oldBkCol = pDC->GetBkColor();
	pDC->SetTextColor(RGB(0, 0, 255));
	pDC->SetBkColor(RGB(255, 255, 0));
	pOldFont = pDC->SelectObject(&font);
	pDC->TextOut(500, 100, _T("Game Over~~"));
	pDC->SetTextColor(oldTextCol);
	pDC->SetBkColor(oldBkCol);
	pDC->SelectObject(pOldFont);
}

BOOL GameScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_JUNGLE);
	CDC memDc;
	memDc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	pDC->BitBlt(0, 0, m_nBkWid, m_nBkHt, &memDc, 0, 0, SRCCOPY);
	memDc.SelectObject(pOldBitmap);

	m_wall.draw(pDC);

	return CStatic::OnEraseBkgnd(pDC);
}


void GameScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	if (m_bGameOver)
	{
		drawGameOver(&dc);
		return;
	}
	if (!m_fruit.getEnable()) // Snake이 Fruit을 먹으면
	{
		m_fruit.setRandPt();
		m_fruit.setEnable(true);
	}
	m_fruit.draw(&dc);
	m_snake.draw(&dc);
	drawScore(&dc);
}


BOOL GameScreen::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	BOOL bResult = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
	CRect rtClient;
	GetClientRect(rtClient);
	m_wall.setRect(rtClient);
	m_snake.setPt(rtClient.CenterPoint());
	m_fruit.setClientRect(rtClient);
	m_fruit.setRandPt();
	return bResult;
}


void GameScreen::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == SCREEN_TIMER)
	{
		m_snake.move();
		if (m_fruit.isHit(m_snake.getRect()))
		{
			m_fruit.setEnable(false); // Snake이 Fruit을 먹음
			m_nScore++;
		}
		else if (m_wall.isHit(m_snake.getRect()))
		{
			m_bGameOver = true;
		}
		Invalidate(TRUE);
	}

	CStatic::OnTimer(nIDEvent);
}
