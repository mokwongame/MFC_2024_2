#include "pch.h"
#include "GameScreen.h"
#include "MemoryDC.h"
#include "resource.h"
#include "CarRaceFun.h"

BEGIN_MESSAGE_MAP(GameScreen, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()

GameScreen::GameScreen(void)
{
	randseed();

	m_fps = 100;

	m_car.setBitmap(IDB_CAR, 100, 209);
	m_car.setStep(10);

	m_enemy.setBitmap(IDB_ENEMY, 90, 190);
	m_enemy.setStep(1);

	m_bGameOver = false;

	m_nScore = 0;
}

BOOL GameScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return FALSE;
	//return CStatic::OnEraseBkgnd(pDC);
}


void GameScreen::OnPaint()
{
	CPaintDC viewDc(this); // device context for painting
	MemoryDC dc(&viewDc);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	m_road.drawBack(&dc);
	m_road.drawAllLines(&dc);

	if (m_bGameOver)
	{
		return;
	}

	m_car.draw(&dc);

	if (!m_enemy.getEnable())
	{
		m_enemy.setPt(makeRandPt());
		m_enemy.setEnable(true);
	}
	m_enemy.draw(&dc);

	drawScore(&dc);
}

CPoint GameScreen::makeRandPt(void) const
{
	CRect rect = m_road.getRect();
	int x = randrange(rect.left + m_road.getCurbSize() + m_enemy.getWid() / 2, rect.right - m_road.getCurbSize() - m_enemy.getWid() / 2);
	return CPoint(x, m_enemy.getHt() / 2);
}

void GameScreen::drawScore(CDC* pDC)
{
	CFont font;
	font.CreatePointFont(300, _T("맑은 고딕"));
	CFont* pOldFont = pDC->SelectObject(&font);
	COLORREF nOldText = pDC->SetTextColor(RGB(255, 255, 0));
	COLORREF nOldBack = pDC->SetBkColor(RGB(127, 127, 127));
	CString str;
	str.Format(_T("score = %d"), m_nScore);
	pDC->TextOut(100, 100, str);
	pDC->SetTextColor(nOldText);
	pDC->SetBkColor(nOldBack);
	pDC->SelectObject(pOldFont);
}

BOOL GameScreen::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	BOOL bResult = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
	CRect rtClient;
	GetClientRect(rtClient);
	m_road.setRect(rtClient);
	m_car.setPt(CPoint(rtClient.CenterPoint().x, rtClient.bottom - m_car.getHt() / 2));
	m_enemy.setPt(makeRandPt());
	return bResult;
}


void GameScreen::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == TIMER_SCREEN)
	{
		m_nScore++;
		m_road.moveDown();
		m_enemy.moveDown();
		if (m_enemy.top() >= m_road.bottom())
		{
			m_enemy.setEnable(false);
		}
		if (rectInRectAny(m_enemy.makeRect(), m_car.makeRect()))
		{
			m_bGameOver = true;
		}
		Invalidate(TRUE);
	}

	CStatic::OnTimer(nIDEvent);
}
