
// TestDialogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "TestDialog.h"
#include "TestDialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestDialogDlg 대화 상자



CTestDialogDlg::CTestDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTDIALOG_DIALOG, pParent)
	, m_sName(_T("목원이"))
	, m_nPostalCode(35349)
	, m_sAddress(_T("대전시 서구 도안북로 88"))
	, m_bVip(FALSE)
	, m_nGender(0)
	, m_sEnergy(_T("I"))
	, m_sSense(_T("N"))
	, m_sThink(_T("F"))
	, m_sLife(_T("P"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sName);
	DDX_Control(pDX, IDC_LIST1, m_lbData);
	DDX_Text(pDX, IDC_EDIT2, m_nPostalCode);
	DDX_Text(pDX, IDC_EDIT3, m_sAddress);
	DDX_Check(pDX, IDC_CHECK1, m_bVip);
	DDX_Radio(pDX, IDC_RADIO1, m_nGender);
	DDX_CBString(pDX, IDC_COMBO1, m_sEnergy);
	DDX_CBString(pDX, IDC_COMBO2, m_sSense);
	DDX_CBString(pDX, IDC_COMBO4, m_sLife);
	DDX_CBString(pDX, IDC_COMBO3, m_sThink);
	DDX_Control(pDX, IDC_STATIC1, m_stBirthDate);
	DDX_Control(pDX, IDC_MONTHCALENDAR1, m_ctMonthCal);
}

BEGIN_MESSAGE_MAP(CTestDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTestDialogDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTestDialogDlg 메시지 처리기

BOOL CTestDialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTestDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTestDialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTestDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestDialogDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // 현재 입력한 정보를 저장(TRUE: 저장할까요?의 답을 TRUE로 설정)
	// 컨트롤이 제공하는 다양한 변수와 함수를 알려면 Microsoft Learn(번역도 제공)
	// ListBox의 모든 내용 지우기
	m_lbData.ResetContent();
	// 현재까지 입력된 정보를 ListBox에 더하기
	m_lbData.AddString(_T("이름 = ") + m_sName); // 유니코드(Unicode)와 ASCII 코드를 구별해야 함; _T(""): 문자열을 유니코드로 변경하는 매크로, T의 의미는 text
	// 우편 번호(숫자) -> 문자열로 변경
	CString str; str.Format(_T("%d"), m_nPostalCode);
	m_lbData.AddString(_T("주소 = (") + str + _T(") ") + m_sAddress);
	// Check Box 확인
	if (m_bVip) str = _T("중요 인물");
	else str = _T("보통 사람");
	m_lbData.AddString(_T("인물 등급 = ") + str);
	// Radio Button 확인
	switch (m_nGender)
	{
	case 0: str = "남성"; break;
	case 1: str = "여성"; break;
	default: str = "모름";
	}
	m_lbData.AddString(_T("성별 = ") + str);
	// Combo Box의 MBTI 확인
	m_lbData.AddString(_T("MBTI = ") + m_sEnergy + m_sSense + m_sThink + m_sLife);

	// 생년월일 얻기
	CTime date;
	m_ctMonthCal.GetCurSel(date); // get current selection: 현재 선택 날짜 얻기
}
