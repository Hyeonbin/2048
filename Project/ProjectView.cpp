
// ProjectView.cpp : CProjectView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Project.h"
#endif

#include "ProjectDoc.h"
#include "ProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <cstdlib> // ������� ����
#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int s=1; // ��� �ñ׳�
int l=0; // �α� �ñ׳�

void CProjectView::Data() // init�Լ��� ȣ���� �Լ�
{
	CProjectDoc * pDoc = GetDocument();
	srand(time(0)); // �����Լ� ȣ��
	int i=0; // ���� ���� ���� ����

	while(1)
	{
		i=rand()%16+1; // ���� �� ����
		if(pDoc->Board->Init(i)==0) // init�Լ� ȣ��
			break; // 0�̸� Ż��
		else 
			continue; // �ƴϸ� ������
	}
}

void CProjectView::Data(CDC *pDC) // ���带 �׷��� �Լ�
{
	CProjectDoc * pDoc = GetDocument();
	int num=0; // ����� ���ڸ� ����
	int cenx=0; // x���� ����
	int ceny=0; // y���� ����
	COLORREF c; // ���� ���� ����

	for(int i=0; i<4; i++) // ���带 �׸� �ݺ���
	{
		for(int j=0; j<4; j++)
		{
			num = pDoc->Board->Print(i, j); // ��� ���� ����
			c=Color(num); // ���ڿ� ���� ��
			CBrush brush(c); // brush�� �� �Է�
			if(s==1) // ���� ����� ���
				pDC->SelectObject(&brush); // �� ���
			pDC->Rectangle(100+64*j, 100+64*i, 100+64*(j+1), 100+64*(i+1)); // ��� ���
			cenx = (100+64*j+100+64*(j+1))/2-4; // ����� ���� �� ���
			ceny = (100+64*i+100+64*(i+1))/2-8; // ���

			if(num!=0) // ����� ���� 0�� �ƴ� ���
			{
				if(s==1) // �� ���
				{
					pDC->SetBkColor(c); // ������ ���
					std::stringstream st; 
					st << num; // ���� �Է�
					pDC->TextOutA(cenx, ceny, CString(st.str().c_str())); // ���� ���
				}
				else
				{
					std::stringstream st; // ���� �Է�
					st << num; // ���� �Է�
					pDC->TextOutA(cenx, ceny, CString(st.str().c_str())); // ���� ���
				}
			}
		}
	}
}

COLORREF CProjectView::Color(int num) // ���� �����ϴ� �Լ�
{
	// �� ��� ���� ���� ���� 
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
	// ǥ�� �μ� ����Դϴ�.
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

// CProjectView ����/�Ҹ�

CProjectView::CProjectView()
{
	count=1;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
}

CProjectView::~CProjectView()
{
}

BOOL CProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CProjectView �׸���

void CProjectView::OnDraw(CDC* pDC) // ���带 �׷��� �Լ�
{
	CProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;

	Data(GetDC()); // Data �Լ� ȣ��
}
// CProjectView �μ�

void CProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CProjectView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) // Ű���� �Է� �Լ�
{
	string log;
	CProjectDoc* pDoc = GetDocument();
	
	switch (nChar) {
	case VK_UP:
		pDoc->Board->U(); // ��� �Է�
		log = "Key_Up";
		break;
	case VK_DOWN:
		pDoc->Board->D(); // �ϴ� �Է�
		log = "Key_Down";
		break;
	case VK_RIGHT:
		pDoc->Board->R(); // ���� �Է�
		log = "Key_Right";
		break;
	case VK_LEFT:
		pDoc->Board->L(); // ���� �Է�
		log = "Key_Left";
		break;
	}

	if(pDoc->Board->Win()==1) // �¸������� ���
		AfxMessageBox(_T("You Win!")); // �޽��� ���
	else if(pDoc->Board->Win()==2) // �й������� ���
		AfxMessageBox(_T("You Lose!")); // �޽��� ���
	else
	{
		Data(); 
		Data(GetDC());
		if(l==1) // �α� ���� ����� ���
		{
			int num=0;
			ofstream fout;
			if(count==1) // ù ��° ����̸� ���� �����
				fout.open("log.txt");
			else // �ƴϸ�
				fout.open("log.txt", ios::app); // �̾ ���
			if(fout.fail())
				return;
			fout<<count<<"."<<log<<endl; // �α� ���
			count++; // ī��Ʈ ����
			fout<<"[result]"<<endl; // ���ڿ� ���
			for(int i=0; i<4; i++) // ������ ���� �α׿� ���
			{
				for(int j=0; j<4; j++)
				{
					num=pDoc->Board->Print(i, j); // ���
					if(num!=0)
						fout<<setw(0)<<num<<" ";
					else
						fout<<setw(0)<<" "<<" ";
				}
				fout<<endl;
			}
			fout<<endl<<endl;
			fout.close();	// ���� ����
		}
		Invalidate(true);
		CView::OnKeyDown(nChar, nRepCnt, nFlags);
	}
}

void CProjectView::OnLButtonDown(UINT nFlags, CPoint point) // ���콺 ����
{ 
	Sp = point; // ������
	SetCapture(); 
	Drag = true; // �巡�� 1
	RedrawWindow(); 
	CView::OnLButtonDown(nFlags, point);
}

void CProjectView::OnLButtonUp(UINT nFlags, CPoint point) // ���콺 ����
{
	CProjectDoc* pDoc = GetDocument();
	Ep = point; // ����
	Drag = false; // �巡�� 0
	string log;

	if(Ep.x>Sp.x) // ���� ȸ���� ���
	{
		pDoc->Board->CRotate(); // ���� ȸ��
		log = "Mouse_Left_to_Right";
	}
	else if(Ep.x<Sp.x) // ���� ȸ���� ���
	{
		pDoc->Board->IRotate(); // ���� ȸ��
		log = "Mouse_Right_to_Left";
	}

	if(l==1) // �α� ������ ����ϴ� ���
	{
		int num=0;
		ofstream fout;
		if(count==1) // ī��Ʈ�� 1�� ���
			fout.open("log.txt"); // �α� ���� ����
		else // �׷��� �ʴٸ�
			fout.open("log.txt", ios::app); // �α׿� �̾ ���
		if(fout.fail())
			return;
		fout<<count<<"."<<log<<endl; // �α� ���
		count++; // ī��Ʈ 1 ����
		fout<<"[result]"<<endl;
		for(int i=0; i<4; i++) // ���带 �α׿� ����ϱ� ���� �ݺ���
		{
			for(int j=0; j<4; j++)
			{
				num=pDoc->Board->Print(i, j); // ���
				if(num!=0)
					fout<<setw(0)<<num;
				else
					fout<<setw(0)<<" ";
			}
			fout<<endl;
		}
		fout<<endl<<endl;
		fout.close(); // ���� ����	
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


// CProjectView ����

#ifdef _DEBUG
void CProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectDoc* CProjectView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectDoc)));
	return (CProjectDoc*)m_pDocument;
}
#endif //_DEBUG

void CProjectView::On32784() // ��� �޴�
{
	s=0; // �ñ׳� 0����
	Data(GetDC());
}

void CProjectView::On32785() // ��� �޴�
{
	s=1; // �ñ׳� 1��
	Data(GetDC());
}

void CProjectView::On32786() // �α� �޴�
{
	l=0; // �ñ׳� 0����
}

void CProjectView::On32787() // �α� �޴�
{
	l=1; // �ñ׳� 1��
}

void CProjectView::OnUpdate32784(CCmdUI *pCmdUI)// ��� �޴�
{
	pCmdUI->SetCheck(s==0); // üũ
}

void CProjectView::OnUpdate32785(CCmdUI *pCmdUI)// ��� �޴�
{
	pCmdUI->SetCheck(s==1); // üũ
}

void CProjectView::OnUpdate32786(CCmdUI *pCmdUI)// �α� �޴�
{
	pCmdUI->SetCheck(l==0); // üũ
}

void CProjectView::OnUpdate32787(CCmdUI *pCmdUI)// �α� �޴�
{
	pCmdUI->SetCheck(l==1); // üũ
}
