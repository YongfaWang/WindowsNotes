// MFCMdi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

class CMdiDocument : public CDocument
{
	DECLARE_DYNCREATE(CMdiDocument)
public:
	
};
IMPLEMENT_DYNCREATE(CMdiDocument, CDocument)


class CMdiView : public CEditView
{
	DECLARE_DYNCREATE(CMdiView)
public:

};
IMPLEMENT_DYNCREATE(CMdiView, CEditView)


class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:

};
IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)


class CMainFrame : public CMDIFrameWnd
{

};





class CMdiApp: public CWinApp
{
		DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNew();
public:
	virtual BOOL InitInstance();
};
BEGIN_MESSAGE_MAP(CMdiApp, CWinApp)
	ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()



void CMdiApp::OnNew()
{
	OnFileNew();
}

CMdiApp theApp;

BOOL CMdiApp::InitInstance()
{
	//�������ĵ�ģ��
	CMultiDocTemplate * pDocTemp = NULL;
	pDocTemp = new CMultiDocTemplate(
				IDR_MAINFRM,
				RUNTIME_CLASS(CMdiDocument),
				RUNTIME_CLASS(CChildFrame),
				RUNTIME_CLASS(CMdiView)
				);

	//�����ĵ�ģ��
	AddDocTemplate(pDocTemp);

	//����������
	CMainFrame *pFrame = new CMainFrame();
	pFrame->LoadFrame(IDR_MAINFRM);
	m_pMainWnd = pFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();


	
	//�����ĵ�
	OnFileNew();
	return TRUE;
}

