
// ProjectView.h : CProjectView 클래스의 인터페이스
//

#include "ProjectDoc.h"
#pragma once
#include <string>

class CProjectView : public CView
{
protected: // serialization에서만 만들어집니다.
	CProjectView();
	DECLARE_DYNCREATE(CProjectView)

// 특성입니다.
public:
	CProjectDoc* GetDocument() const; // 다큐에서 보드 읽어올 함수
	int count; // 전체 카운트

	CPoint Sp; // 마우스 시작점
	CPoint Ep; // 마우스 끝점
	bool Drag; // 드레그 함수

// 작업입니다.
public:
	void Data(CDC *pDC); // 보드 만드는 함수
	void Data(); // 보드의 데이터를 결정짓는 함수
	static COLORREF Color(int num); // 색을 정할 함수

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void On32784(); // 출력 메뉴
	afx_msg void On32785(); // 출력 메뉴
	afx_msg void On32786(); // 로그 메뉴
	afx_msg void On32787(); // 로그 메뉴
	afx_msg void OnUpdate32784(CCmdUI *pCmdUI); // 출력 메뉴
	afx_msg void OnUpdate32785(CCmdUI *pCmdUI); // 출력 메뉴
	afx_msg void OnUpdate32786(CCmdUI *pCmdUI); // 로그 메뉴
	afx_msg void OnUpdate32787(CCmdUI *pCmdUI); // 로그 메뉴
};

#ifndef _DEBUG  // ProjectView.cpp의 디버그 버전
inline CProjectDoc* CProjectView::GetDocument() const
   { return reinterpret_cast<CProjectDoc*>(m_pDocument); }
#endif

