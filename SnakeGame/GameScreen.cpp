#include "pch.h"
#include "GameScreen.h"
#include "resource.h"

BEGIN_MESSAGE_MAP(GameScreen, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()


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

	return CStatic::OnEraseBkgnd(pDC);
}


void GameScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
}
