#include "pch.h"
#include "CPainter.h"

BEGIN_MESSAGE_MAP(CPainter, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CPainter::OnPaint() // WM_PAINT 메시지가 발생할 때 처리하는 함수
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	dc.Rectangle(0, 0, 100, 200); // 사각형 그리기
}
