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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//return CStatic::OnEraseBkgnd(pDC);
	return FALSE;
}


void GameScreen::OnPaint()
{
	CPaintDC viewDc(this); // device context for painting
	MemoryDC dc(&viewDc);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	BOOL bResult = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);

	CRect rtClient;
	GetClientRect(rtClient); // GameScreen ��ǥ���� ������ �������� ����� rtClient
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == TIMER_SCREEN)
	{
		m_road.moveDown();
		Invalidate(TRUE);
	}

	CStatic::OnTimer(nIDEvent);
}
