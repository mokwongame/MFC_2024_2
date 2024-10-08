﻿
// TestDialogDlg.h: 헤더 파일
//

#pragma once


// CTestDialogDlg 대화 상자
class CTestDialogDlg : public CDialogEx
{
	// 생성입니다.
public:
	CTestDialogDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTDIALOG_DIALOG };
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
public:
	CString m_sName; // member of string named as m_sName
	afx_msg void OnBnClickedButton1();
	CListBox m_lbData;
	int m_nPostalCode;
	CString m_sAddress;
	BOOL m_bVip;
	int m_nGender;
	CString m_sEnergy;
	CString m_sSense;
	CString m_sLife;
	CString m_sThink;
	CStatic m_stBirthDate;
	CMonthCalCtrl m_ctMonthCal;
	int m_nPet;
	CStatic m_pcPet;
};
