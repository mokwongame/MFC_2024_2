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


BOOL GameScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//return CStatic::OnEraseBkgnd(pDC);
	return FALSE;
}


void GameScreen::OnPaint()
{
	CPaintDC viewDc(this); // device context for painting
	MemoryDC dc(&viewDc);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	m_road.drawBack(&dc);
	m_road.drawAllLines(&dc);

	m_car.draw(&dc);
	m_enemy.draw(&dc);
}


GameScreen::GameScreen(void)
{
	randseed();

	m_car.setBitmap(IDB_CAR, 90, 180);
	m_car.setStep(10);

	m_enemy.setBitmap(IDB_TRUCK, 80, 158);
	m_enemy.setStep(1);
}

CPoint GameScreen::getRandPt(void) const
{
	CRect rect = m_road.getRect();
	CPoint pt;
	pt.x = randrange(rect.left + m_enemy.getWid() / 2, rect.right - m_enemy.getWid() / 2);
	pt.y = rect.top + m_enemy.getHt() / 2;
	return pt;
}

BOOL GameScreen::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	BOOL bResult = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);

	CRect rtClient;
	GetClientRect(rtClient); // GameScreen 좌표계의 원점을 기준으로 계산한 rtClient
	m_road.setRect(rtClient);

	CPoint ptCar;
	ptCar.x = rtClient.CenterPoint().x;
	ptCar.y = rtClient.bottom - m_car.getHt() / 2 - 3;
	m_car.setPt(ptCar);

	m_enemy.setPt(getRandPt());
	return bResult;
}


void GameScreen::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == TIMER_SCREEN)
	{
		m_road.moveDown();
		Invalidate(TRUE);
	}

	CStatic::OnTimer(nIDEvent);
}
