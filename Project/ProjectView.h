
// ProjectView.h : CProjectView Ŭ������ �������̽�
//

#include "ProjectDoc.h"
#pragma once
#include <string>

class CProjectView : public CView
{
protected: // serialization������ ��������ϴ�.
	CProjectView();
	DECLARE_DYNCREATE(CProjectView)

// Ư���Դϴ�.
public:
	CProjectDoc* GetDocument() const; // ��ť���� ���� �о�� �Լ�
	int count; // ��ü ī��Ʈ

	CPoint Sp; // ���콺 ������
	CPoint Ep; // ���콺 ����
	bool Drag; // �巹�� �Լ�

// �۾��Դϴ�.
public:
	void Data(CDC *pDC); // ���� ����� �Լ�
	void Data(); // ������ �����͸� �������� �Լ�
	static COLORREF Color(int num); // ���� ���� �Լ�

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void On32784(); // ��� �޴�
	afx_msg void On32785(); // ��� �޴�
	afx_msg void On32786(); // �α� �޴�
	afx_msg void On32787(); // �α� �޴�
	afx_msg void OnUpdate32784(CCmdUI *pCmdUI); // ��� �޴�
	afx_msg void OnUpdate32785(CCmdUI *pCmdUI); // ��� �޴�
	afx_msg void OnUpdate32786(CCmdUI *pCmdUI); // �α� �޴�
	afx_msg void OnUpdate32787(CCmdUI *pCmdUI); // �α� �޴�
};

#ifndef _DEBUG  // ProjectView.cpp�� ����� ����
inline CProjectDoc* CProjectView::GetDocument() const
   { return reinterpret_cast<CProjectDoc*>(m_pDocument); }
#endif

