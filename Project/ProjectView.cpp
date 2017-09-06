
// ProjectView.cpp : CProjectView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Project.h"
#endif

#include "ProjectDoc.h"
#include "ProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <cstdlib> // 헤더파일 선언
#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int s=1; // 출력 시그널
int l=0; // 로그 시그널

void CProjectView::Data() // init함수를 호출할 함수
{
	CProjectDoc * pDoc = GetDocument();
	srand(time(0)); // 랜덤함수 호출
	int i=0; // 랜덤 값을 받을 변수

	while(1)
	{
		i=rand()%16+1; // 랜덤 값 받음
		if(pDoc->Board->Init(i)==0) // init함수 호출
			break; // 0이면 탈출
		else 
			continue; // 아니면 재진행
	}
}

void CProjectView::Data(CDC *pDC) // 보드를 그려줄 함수
{
	CProjectDoc * pDoc = GetDocument();
	int num=0; // 블록의 숫자를 저장
	int cenx=0; // x값의 센터
	int ceny=0; // y값의 센터
	COLORREF c; // 색을 받을 변수

	for(int i=0; i<4; i++) // 보드를 그릴 반복문
	{
		for(int j=0; j<4; j++)
		{
			num = pDoc->Board->Print(i, j); // 블록 숫자 저장
			c=Color(num); // 숫자에 따른 색
			CBrush brush(c); // brush에 색 입력
			if(s==1) // 색을 출력할 경우
				pDC->SelectObject(&brush); // 색 출력
			pDC->Rectangle(100+64*j, 100+64*i, 100+64*(j+1), 100+64*(i+1)); // 블록 출력
			cenx = (100+64*j+100+64*(j+1))/2-4; // 블록의 센터 값 계산
			ceny = (100+64*i+100+64*(i+1))/2-8; // 계산

			if(num!=0) // 블록의 값이 0이 아닌 경우
			{
				if(s==1) // 색 출력
				{
					pDC->SetBkColor(c); // 배경색도 출력
					std::stringstream st; 
					st << num; // 숫자 입력
					pDC->TextOutA(cenx, ceny, CString(st.str().c_str())); // 숫자 출력
				}
				else
				{
					std::stringstream st; // 숫자 입력
					st << num; // 숫자 입력
					pDC->TextOutA(cenx, ceny, CString(st.str().c_str())); // 숫자 출력
				}
			}
		}
	}
}

COLORREF CProjectView::Color(int num) // 색을 리턴하는 함수
{
	// 각 경우 별로 색을 리턴 
	if(num==2) 
		return RGB(255, 255, 0);
	else if(num==4)
		return RGB(255, 127, 0);
	else if(num==8)
		return RGB(0, 255, 0);
	else if(num==16)
		return RGB(0, 0, 255);
	else if(num==32)
		return RGB(166, 166, 166);
	else if(num==64)
		return RGB(255, 0, 255);
	else if(num==128)
		return RGB(0, 255, 255);
	else if(num==256)
		return RGB(128, 0, 128);
	else if(num==512)
		return RGB(112, 48, 160);
	else if(num==1024)
		return RGB(207, 110, 54);
	else if(num==2048)
		return RGB(255, 0, 0);
	else if(num==0)
		return RGB(255, 255, 255);
}
// CProjectView

IMPLEMENT_DYNCREATE(CProjectView, CView)

BEGIN_MESSAGE_MAP(CProjectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CProjectView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32784, &CProjectView::On32784)
	ON_COMMAND(ID_32785, &CProjectView::On32785)
	ON_COMMAND(ID_32786, &CProjectView::On32786)
	ON_COMMAND(ID_32787, &CProjectView::On32787)
	ON_UPDATE_COMMAND_UI(ID_32784, &CProjectView::OnUpdate32784)
	ON_UPDATE_COMMAND_UI(ID_32785, &CProjectView::OnUpdate32785)
	ON_UPDATE_COMMAND_UI(ID_32786, &CProjectView::OnUpdate32786)
	ON_UPDATE_COMMAND_UI(ID_32787, &CProjectView::OnUpdate32787)
END_MESSAGE_MAP()

// CProjectView 생성/소멸

CProjectView::CProjectView()
{
	count=1;
	// TODO: 여기에 생성 코드를 추가합니다.
}

CProjectView::~CProjectView()
{
}

BOOL CProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CProjectView 그리기

void CProjectView::OnDraw(CDC* pDC) // 보드를 그려줄 함수
{
	CProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;

	Data(GetDC()); // Data 함수 호출
}
// CProjectView 인쇄

void CProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CProjectView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) // 키보드 입력 함수
{
	string log;
	CProjectDoc* pDoc = GetDocument();
	
	switch (nChar) {
	case VK_UP:
		pDoc->Board->U(); // 상단 입력
		log = "Key_Up";
		break;
	case VK_DOWN:
		pDoc->Board->D(); // 하단 입력
		log = "Key_Down";
		break;
	case VK_RIGHT:
		pDoc->Board->R(); // 우측 입력
		log = "Key_Right";
		break;
	case VK_LEFT:
		pDoc->Board->L(); // 좌측 입력
		log = "Key_Left";
		break;
	}

	if(pDoc->Board->Win()==1) // 승리조건인 경우
		AfxMessageBox(_T("You Win!")); // 메시지 출력
	else if(pDoc->Board->Win()==2) // 패배조건인 경우
		AfxMessageBox(_T("You Lose!")); // 메시지 출력
	else
	{
		Data(); 
		Data(GetDC());
		if(l==1) // 로그 파일 출력인 경우
		{
			int num=0;
			ofstream fout;
			if(count==1) // 첫 번째 출력이면 파일 만든다
				fout.open("log.txt");
			else // 아니면
				fout.open("log.txt", ios::app); // 이어서 출력
			if(fout.fail())
				return;
			fout<<count<<"."<<log<<endl; // 로그 출력
			count++; // 카운트 증가
			fout<<"[result]"<<endl; // 문자열 출력
			for(int i=0; i<4; i++) // 보드의 값들 로그에 출력
			{
				for(int j=0; j<4; j++)
				{
					num=pDoc->Board->Print(i, j); // 출력
					if(num!=0)
						fout<<setw(0)<<num<<" ";
					else
						fout<<setw(0)<<" "<<" ";
				}
				fout<<endl;
			}
			fout<<endl<<endl;
			fout.close();	// 파일 닫음
		}
		Invalidate(true);
		CView::OnKeyDown(nChar, nRepCnt, nFlags);
	}
}

void CProjectView::OnLButtonDown(UINT nFlags, CPoint point) // 마우스 동작
{ 
	Sp = point; // 시작점
	SetCapture(); 
	Drag = true; // 드래그 1
	RedrawWindow(); 
	CView::OnLButtonDown(nFlags, point);
}

void CProjectView::OnLButtonUp(UINT nFlags, CPoint point) // 마우스 동작
{
	CProjectDoc* pDoc = GetDocument();
	Ep = point; // 끝점
	Drag = false; // 드래그 0
	string log;

	if(Ep.x>Sp.x) // 우측 회전인 경우
	{
		pDoc->Board->CRotate(); // 우측 회전
		log = "Mouse_Left_to_Right";
	}
	else if(Ep.x<Sp.x) // 좌측 회전인 경우
	{
		pDoc->Board->IRotate(); // 좌측 회전
		log = "Mouse_Right_to_Left";
	}

	if(l==1) // 로그 파일을 출력하는 경우
	{
		int num=0;
		ofstream fout;
		if(count==1) // 카운트가 1인 경우
			fout.open("log.txt"); // 로그 파일 생성
		else // 그렇지 않다면
			fout.open("log.txt", ios::app); // 로그에 이어서 출력
		if(fout.fail())
			return;
		fout<<count<<"."<<log<<endl; // 로그 출력
		count++; // 카운트 1 증가
		fout<<"[result]"<<endl;
		for(int i=0; i<4; i++) // 보드를 로그에 출력하기 위한 반복문
		{
			for(int j=0; j<4; j++)
			{
				num=pDoc->Board->Print(i, j); // 출력
				if(num!=0)
					fout<<setw(0)<<num;
				else
					fout<<setw(0)<<" ";
			}
			fout<<endl;
		}
		fout<<endl<<endl;
		fout.close(); // 파일 닫음	
	}
	RedrawWindow();
    ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void CProjectView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CProjectView::OnContextMenu(CWnd* pWnd, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CProjectView 진단

#ifdef _DEBUG
void CProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectDoc* CProjectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectDoc)));
	return (CProjectDoc*)m_pDocument;
}
#endif //_DEBUG

void CProjectView::On32784() // 출력 메뉴
{
	s=0; // 시그널 0으로
	Data(GetDC());
}

void CProjectView::On32785() // 출력 메뉴
{
	s=1; // 시그널 1로
	Data(GetDC());
}

void CProjectView::On32786() // 로그 메뉴
{
	l=0; // 시그널 0으로
}

void CProjectView::On32787() // 로그 메뉴
{
	l=1; // 시그널 1로
}

void CProjectView::OnUpdate32784(CCmdUI *pCmdUI)// 출력 메뉴
{
	pCmdUI->SetCheck(s==0); // 체크
}

void CProjectView::OnUpdate32785(CCmdUI *pCmdUI)// 출력 메뉴
{
	pCmdUI->SetCheck(s==1); // 체크
}

void CProjectView::OnUpdate32786(CCmdUI *pCmdUI)// 로그 메뉴
{
	pCmdUI->SetCheck(l==0); // 체크
}

void CProjectView::OnUpdate32787(CCmdUI *pCmdUI)// 로그 메뉴
{
	pCmdUI->SetCheck(l==1); // 체크
}
