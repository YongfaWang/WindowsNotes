// MFCSplit.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"


UINT iIndicators[] = {
		ID_SEPARATOR,
		ID_INDICATOR_NUM,
		ID_INDICATOR_CAPS,
		ID_INDICATOR_OVR
};




class   CMyView1 : public CView
{
public:
	virtual void OnInitialUpdate();


	DECLARE_DYNCREATE(CMyView1)  //��̬��������
public:
	virtual void OnDraw(CDC *pDC);
};

IMPLEMENT_DYNCREATE(CMyView1, CView) //��̬��������(ʵ��)

void CMyView1::OnInitialUpdate()
{
//	AfxMessageBox("OnInitialUpdate");
}

void CMyView1::OnDraw(CDC *pDC)
{
	pDC->TextOut(50, 50, "����һ��view");
}


class   CMyView2 : public CHtmlView
{
public:
	virtual void OnInitialUpdate();


	DECLARE_DYNCREATE(CMyView2)  //��̬��������
public:
	virtual void OnDraw(CDC *pDC);
};

IMPLEMENT_DYNCREATE(CMyView2, CView) //��̬��������(ʵ��)

void CMyView2::OnInitialUpdate()
{
//	AfxMessageBox("OnInitialUpdate");

	//��html�ļ�
	/*
	void Navigate(
    LPCTSTR URL,  
    DWORD dwFlags = 0,  
    LPCTSTR lpszTargetFrameName = NULL,  
    LPCTSTR lpszHeaders = NULL,  
    LPVOID lpvPostData = NULL,  
    DWORD dwPostDataLen = 0);*/


//	Navigate("http://www.baidu.com");
	//Navigate("C:\\");

}

void CMyView2::OnDraw(CDC *pDC)
{
	pDC->TextOut(50, 50, "view2");
}







class CSplitFrame : public CFrameWnd
{


public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpCreateStruct, CCreateContext *pContext);
	DECLARE_MESSAGE_MAP()
public:

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

public:
	CToolBar m_wndToolBar;
	CStatusBar m_wndStatusBar;

	//�зִ���
	CSplitterWnd m_wndSplitter;

	CSplitterWnd m_wndSplitterRight; //�з��Ҳര��

};


BEGIN_MESSAGE_MAP(CSplitFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()


BOOL CSplitFrame::OnCreateClient(LPCREATESTRUCT lpCreateStruct, 
								CCreateContext *pContext)
{
#define STATIC_CREATE
#ifdef STATIC_CREATE	//��̬�з�
	m_wndSplitter.CreateStatic(this, 1, 2); //�����з�
	m_wndSplitterRight.CreateStatic(&m_wndSplitter/*����*/, 2, 1, 
								WS_CHILD|WS_VISIBLE, 
								m_wndSplitter.IdFromRowCol(0, 1));

	//������ͼ


	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMyView1), CSize(200, 200), pContext);
	m_wndSplitterRight.CreateView(0, 0, RUNTIME_CLASS(CMyView2), CSize(200, 200), pContext);
	m_wndSplitterRight.CreateView(1, 0, RUNTIME_CLASS(CMyView2), CSize(200, 200), pContext);

	CMyView2 *pView1 = (CMyView2 *)m_wndSplitterRight.GetPane(0, 0);
	pView1->Navigate2("http://www.baidu.com");

	CMyView2 *pView2 = (CMyView2 *)m_wndSplitterRight.GetPane(1, 0);
	pView2->Navigate2("C:\\");

	m_wndSplitterRight.SetActivePane(1, 0);
#else //��̬�з�
	CCreateContext context;

	//��ȡCMyView1������ʱ����Ϣ
	context.m_pNewViewClass = RUNTIME_CLASS(CMyView1) ;

	//�����зִ���
	m_wndSplitter.Create(this, 2, 2, CSize(50, 50), &context); // ���� 2x2ʱ, MFC�ᾯ��, ����������
#endif


	return TRUE;
}



int CSplitFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameWnd::OnCreate(lpCreateStruct);

#if 1
	m_wndToolBar.CreateEx(this);
	m_wndToolBar.LoadToolBar(IDR_MAINFRM);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

#endif

	//״̬��
	m_wndStatusBar.CreateEx(this);
	m_wndStatusBar.SetIndicators(iIndicators, sizeof(iIndicators)/sizeof(UINT));



	return 0;
}








class CSplitApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};


CSplitApp theApp;


BOOL CSplitApp::InitInstance()
{
	CSplitFrame *pWnd = new CSplitFrame();
	pWnd->LoadFrame(IDR_MAINFRM);
	m_pMainWnd = pWnd;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}











