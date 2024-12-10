#include "pch.h"
#include "GameScreen.h"
#include "MemoryDC.h"

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
}


BOOL GameScreen::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	BOOL bResult = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);

	CRect rtClient;
	GetClientRect(rtClient); // GameScreen ��ǥ���� ������ �������� ����� rtClient
	m_road.setRect(rtClient);

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
