
// OurPainterDlg.h: 헤더 파일
//

#pragma once

#include "CPainter.h"

// COurPainterDlg 대화 상자
class COurPainterDlg : public CDialogEx
{
	// 생성입니다.
public:
	COurPainterDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OURPAINTER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CPainter m_paint; // 우리가 그림을 그릴 컨트롤 선언
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	int m_nRectX0;
	int m_nRectY0;
	int m_nRectStep;
	afx_msg void OnBnClickedButton5();
	CSpinButtonCtrl m_spinRectStep;
	CSliderCtrl m_slidRectWid;
	CSliderCtrl m_slidRectHt;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
