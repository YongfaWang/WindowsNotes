// WinMFC.cpp : Defines the entry point for the application.
//

#include "stdafx.h"



//��ܴ�����
class CMyFrameWnd : public CFrameWnd
{
public:


	//���ڴ�����
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};





LRESULT CMyFrameWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:
		AfxMessageBox("WM_CREATE");
		break;
	case WM_PAINT://��ͼ��Ϣ
		{
			PAINTSTRUCT ps = {0};
			HDC hDC = ::BeginPaint(m_hWnd, &ps);  //��"::" ��ʾʹ��ȫ��(Win32��API)

			CHAR  szText[] = "hello world";
			TextOut(hDC, 100, 100, szText, strlen(szText));  //���ı�

			::EndPaint(m_hWnd, &ps);
		}
		break;
	}

	return CFrameWnd::WindowProc(message, wParam, lParam); //ʹ�ø���Ĵ��ڴ�����
}



//Ӧ�ó�����
class CMyApp : public CWinApp
{
public:
	CMyApp();
	virtual BOOL InitInstance();
};

//����CMyApp��ȫ�ֱ���
CMyApp theApp;


CMyApp::CMyApp()
{



}



//��ʼ������
BOOL CMyApp::InitInstance()
{
	//AfxMessageBox("Hello App");

	//�������ڶ���
	CMyFrameWnd  *pWnd = new CMyFrameWnd();

	//��������
	pWnd->Create(NULL, "MyApp");

	//��ʾ����
	pWnd->ShowWindow(SW_SHOW);


	//����������
	m_pMainWnd = pWnd;


	return TRUE; //�������FALSE , ��ֱ���˳�Ӧ�ó�����
}








