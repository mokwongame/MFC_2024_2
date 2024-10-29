
// OurPainterDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "OurPainter.h"
#include "OurPainterDlg.h"
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
public:
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


// COurPainterDlg 대화 상자



COurPainterDlg::COurPainterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OURPAINTER_DIALOG, pParent)
	, m_nRectX0(0)
	, m_nRectY0(0)
	, m_nRectStep(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COurPainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nRectX0);
	DDX_Text(pDX, IDC_EDIT2, m_nRectY0);
	DDX_Text(pDX, IDC_EDIT3, m_nRectStep);
	DDX_Control(pDX, IDC_SPIN1, m_spinRectStep);
	DDX_Control(pDX, IDC_SLIDER_WID, m_slidRectWid);
	DDX_Control(pDX, IDC_SLIDER_HT, m_slidRectHt);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_btBackCol);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctProg);
}

BEGIN_MESSAGE_MAP(COurPainterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &COurPainterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &COurPainterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &COurPainterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &COurPainterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &COurPainterDlg::OnBnClickedButton5)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &COurPainterDlg::OnBnClickedMfccolorbutton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// COurPainterDlg 메시지 처리기

BOOL COurPainterDlg::OnInitDialog()
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
	CWnd* pWnd = GetDlgItem(IDC_PAINT); // IDC_PAINT 번호를 가진  dialog item을 얻기(get); pWnd는 CWnd(window class)의 포인터
	// -> 의미: 클래스 포인터의 멤버 접근 연산자
	pWnd->ShowWindow(SW_HIDE); // 현재 static text 숨기기
	CRect rect;
	pWnd->GetWindowRect(rect); // window의 사각형(rectangle) 크기 얻기; 사각형 크기는 rect에 담김; 이때 좌표계는 화면(screen) 좌표계를 사용
	ScreenToClient(rect); // 화면 좌표계를 클라이언트(client) 좌표계로 변경; 화면 상 위치가 아니고 앱 기준 위치로 변경

	m_paint.Create(NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, rect, this);

	m_nRectStep = m_paint.getRectStep();
	UpdateData(FALSE);
	m_spinRectStep.SetRange(0, 100); // ScrollBar의 방향을 수학 Y축과 같게 설정

	m_slidRectWid.SetRange(0, 300);
	m_slidRectWid.SetPos(m_paint.getRectWid());

	// 색깔 설정
	m_btBackCol.SetColor(m_paint.getBackCol());

	// Progress control 설정: 예시로 timer로 조절
	m_ctProg.SetRange(0, 3000);
	m_ctProg.SetPos(0);

	// timer 시작
	SetTimer(1, 100, NULL); // 1: 타이머 ID; 100: 호출 주기(msec); NULL: 콜백 함수가 없음

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void COurPainterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COurPainterDlg::OnPaint()
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
HCURSOR COurPainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 사각형을 위로 이동
void COurPainterDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_paint.moveRectUp();
	//Invalidate(TRUE);
	m_nRectY0 = m_paint.getRectY0();
	UpdateData(FALSE);
}

// 사각형을 아래로 이동
void COurPainterDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_paint.moveRectDown();
	//Invalidate(TRUE);
	m_nRectY0 = m_paint.getRectY0();
	UpdateData(FALSE);
}

// 사각형을 왼쪽으로 이동
void COurPainterDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

// 사각형을 오른쪽으로 이동
void COurPainterDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

// 속성 설정
void COurPainterDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_paint.setRectStep(m_nRectStep);
	m_paint.setRectWid(m_slidRectWid.GetPos());
}

void COurPainterDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_WID)
	{
		CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
		int nWid = pSlider->GetPos();
		m_paint.setRectWid(nWid);
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

// 배경색 변경
void COurPainterDlg::OnBnClickedMfccolorbutton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 색깔 가져오기 -> m_paint에 설정
	m_paint.setBackCol(m_btBackCol.GetColor());
	m_paint.Invalidate(TRUE);
}

// 메시지(message) 번역(translate) 전(pre)에 호출되는 가상 함수
BOOL COurPainterDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_UP || pMsg->wParam == 'W') // VK: virtual key, 가상키
		{
			m_paint.moveBitUp();
			return TRUE;
		}
		else if (pMsg->wParam == VK_DOWN || pMsg->wParam == 'S')
		{
			m_paint.moveBitDown();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void COurPainterDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 1)
	{
		// progress control의 위치를 1만큼 증가
		m_ctProg.SetPos(m_ctProg.GetPos() + 1);
	}

	CDialogEx::OnTimer(nIDEvent);
}
