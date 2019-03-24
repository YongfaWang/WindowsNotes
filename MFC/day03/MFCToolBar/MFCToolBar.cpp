// MFCToolBar.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

#include <afxext.h>


class CToolBarApp : public CWinApp
{
public:
	virtual  BOOL  InitInstance();
};


class CToolBarFrame : public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL PreCreateWindow(CREATESTRUCT &cs);

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg  void OnExit();
	afx_msg void OnAbout();
	afx_msg void OnStd();


	//ID_STD������
	afx_msg void OnUpdateViewStdBar(CCmdUI *pCmdUI);

public:
	CToolBar m_wndToolBar;
};

BEGIN_MESSAGE_MAP(CToolBarFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_EXIT, OnExit)
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_STD, OnStd)
	ON_UPDATE_COMMAND_UI(ID_STD, OnUpdateViewStdBar)
END_MESSAGE_MAP()



void  CToolBarFrame::OnUpdateViewStdBar(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_wndToolBar.IsWindowVisible());
}




void CToolBarFrame::OnStd()
{
	ShowControlBar(&m_wndToolBar, TRUE, FALSE);
}

BOOL CToolBarFrame::PreCreateWindow(CREATESTRUCT &cs)
{
		
	CFrameWnd::PreCreateWindow(cs);
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;

	return TRUE;
}


void CToolBarFrame::OnAbout()
{
	AfxMessageBox("��� ����");
}

int CToolBarFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameWnd::OnCreate(lpCreateStruct);


	//����������
	if(FALSE == m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD|WS_VISIBLE|CBRS_ALIGN_TOP|CBRS_GRIPPER))
	{
		AfxMessageBox("����ʧ��");
		return 0;
	}

	//���ع�������Դ
	if(FALSE ==	m_wndToolBar.LoadToolBar(IDR_MAINFRM))
	{
		AfxMessageBox("����ʧ��");
		return 0;
	}


	//������֧��ͣ��
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//FrameWnd֧��ͣ��
	EnableDocking(CBRS_ALIGN_ANY);
	
	//ͣ��������
	DockControlBar(&m_wndToolBar);


	return 0;
}

void CToolBarFrame::OnExit()
{
	PostQuitMessage(WM_QUIT);
}




CToolBarApp theApp;


BOOL CToolBarApp::InitInstance()
{

	CToolBarFrame *pWnd = new CToolBarFrame();
	pWnd->Create(NULL, "������ʹ�ð���", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU1));
	m_pMainWnd = pWnd;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


















