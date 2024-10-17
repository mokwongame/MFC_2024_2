
// MyPainterDlg.h: 헤더 파일
//

#pragma once

#include "CPainter.h" // 내가 만든 painter 클래스

// CMyPainterDlg 대화 상자
class CMyPainterDlg : public CDialogEx
{
	// 생성입니다.
public:
	CMyPainterDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYPAINTER_DIALOG };
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
	CPainter m_painter;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	int m_nRectX0;
	int m_nRectY0;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_nRectStep;
	afx_msg void OnBnClickedButton5();
	CSliderCtrl m_sliderWid;
	CSliderCtrl m_sliderHt;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSpinButtonCtrl m_spinStep;
	afx_msg void OnBnClickedMfccolorbutton1();
	CMFCColorButton m_colBack;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CProgressCtrl m_prog;
};
