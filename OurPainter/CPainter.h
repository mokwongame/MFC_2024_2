#pragma once

#include <afxwin.h>

// 클래스 마법사 호출: Ctrl+Shift+X; 프로젝트 > 클래스 마법사
class CPainter :
	public CStatic
{
public:

protected:
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

