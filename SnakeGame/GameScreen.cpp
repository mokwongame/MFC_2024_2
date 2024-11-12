#include "pch.h"
#include "GameScreen.h"
#include "resource.h"

BEGIN_MESSAGE_MAP(GameScreen, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()


BOOL GameScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
}


BOOL GameScreen::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	BOOL bResult = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
	CRect rtClient;
	GetClientRect(rtClient);
	m_wall.setRect(rtClient);
	return bResult;
}
