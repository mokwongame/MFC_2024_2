
// MyPainterDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MyPainter.h"
#include "MyPainterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TIMER_PROG	(1)
#define TIMER_PROG_PERIOD	(100)

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


// CMyPainterDlg 대화 상자



CMyPainterDlg::CMyPainterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYPAINTER_DIALOG, pParent)
	, m_nRectX0(0)
	, m_nRectY0(0)
	, m_nRectStep(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nRectX0 = m_painter.getRectX0();
	m_nRectY0 = m_painter.getRectY0();
}

void CMyPainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nRectX0);
	DDX_Text(pDX, IDC_EDIT2, m_nRectY0);
	DDX_Text(pDX, IDC_EDIT3, m_nRectStep);
	DDX_Control(pDX, IDC_SLIDER_WID, m_sliderWid);
	DDX_Control(pDX, IDC_SLIDER_HT, m_sliderHt);
	DDX_Control(pDX, IDC_SPIN1, m_spinStep);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_colBack);
	DDX_Control(pDX, IDC_PROGRESS1, m_prog);
}

BEGIN_MESSAGE_MAP(CMyPainterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyPainterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyPainterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyPainterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyPainterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyPainterDlg::OnBnClickedButton5)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CMyPainterDlg::OnBnClickedMfccolorbutton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMyPainterDlg 메시지 처리기

BOOL CMyPainterDlg::OnInitDialog()
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
	CWnd* pWnd = GetDlgItem(IDC_PAINTER); // dialog iterm을 얻기(get): static text에 접근 가능(포인터: *, ->)
	pWnd->ShowWindow(SW_HIDE);
	CRect rect; // 사각형(rectangle) 위치를 저장하는 클래스
	pWnd->GetWindowRect(rect); // 현재 pWnd가 차지한 사각형 정보를 rect에 얻기; 좌표계: 화면의 전역 좌표계
	ScreenToClient(rect);

	m_painter.Create(NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, rect, this);

	m_nRectStep = m_painter.getRectStep();
	m_spinStep.SetRange(0, 100);

	m_sliderWid.SetRange(0, MAX_RECT_WID);
	m_sliderWid.SetPos(m_painter.getRectWid());
	m_sliderHt.SetRange(0, MAX_RECT_HT);
	m_sliderHt.SetPos(m_painter.getRectHt());

	m_colBack.SetColor(m_painter.getBackCol());

	UpdateData(FALSE);

	// 타이머 설정
	m_prog.SetRange(0, 1000);
	m_prog.SetPos(0);
	SetTimer(TIMER_PROG, TIMER_PROG_PERIOD, NULL); // 타이머 주기는 msec 단위
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMyPainterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyPainterDlg::OnPaint()
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
HCURSOR CMyPainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 사각형 위 이동
void CMyPainterDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_painter.moveRectUp();
	//Invalidate(TRUE);
	m_nRectY0 = m_painter.getRectY0();
	UpdateData(FALSE);
}

// 사각형 아래 이동
void CMyPainterDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_painter.moveRectDown();
	m_nRectY0 = m_painter.getRectY0();
	UpdateData(FALSE);
}

// 사각형 왼쪽 이동
void CMyPainterDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_painter.moveRectLeft();
	m_nRectX0 = m_painter.getRectX0();
	UpdateData(FALSE);
}

// 사각형 오른쪽 이동
void CMyPainterDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_painter.moveRectRight();
	m_nRectX0 = m_painter.getRectX0();
	UpdateData(FALSE);
}


BOOL CMyPainterDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	// Dialog로 메시지가 전달되기 전에 가로채는 함수
	if (pMsg->message == WM_KEYDOWN)
	{
		// 넘어온 키값을 확인: wParam(word parameter)
		if (pMsg->wParam == VK_UP || pMsg->wParam == 'W')
		{
			m_painter.moveBallUp();
			return TRUE; // Dialog의 WM_KEYDOWN을 처리하는 함수를 없앰
		}
		else if (pMsg->wParam == VK_DOWN || pMsg->wParam == 'S')
		{
			m_painter.moveBallDown();
			return TRUE; // Dialog의 WM_KEYDOWN을 처리하는 함수를 없앰
		}
		else if (pMsg->wParam == VK_LEFT || pMsg->wParam == 'A')
		{
			m_painter.moveBallLeft();
			return TRUE;
		}
		else if (pMsg->wParam == VK_RIGHT || pMsg->wParam == 'D')
		{
			m_painter.moveBallRight();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

// 컨트롤 설정
void CMyPainterDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_painter.setRectBallStep(m_nRectStep);
	m_painter.setRectWid(m_sliderWid.GetPos());
	m_painter.setRectHt(m_sliderHt.GetPos());
	//m_painter.Invalidate(TRUE);
}


void CMyPainterDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_WID)
	{
		CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
		m_painter.setRectWid(pSlider->GetPos());
	}
	else if (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_HT)
	{
		CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
		m_painter.setRectHt(pSlider->GetPos());
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

// 배경색 설정
void CMyPainterDlg::OnBnClickedMfccolorbutton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_painter.setBackCol(m_colBack.GetColor());
}

// WM_TIMER 메시지를 처리하는 핸들러(처리기)
void CMyPainterDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == TIMER_PROG)
	{
		m_prog.SetPos(m_prog.GetPos() + 1);
		m_painter.flowRectRight();
	}
	CDialogEx::OnTimer(nIDEvent);
}
