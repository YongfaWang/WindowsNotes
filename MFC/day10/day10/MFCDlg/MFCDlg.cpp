// MFCDlg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"


class CMyDialog : public CDialog
{
public:
	CMyDialog();

	//�Ի������ݽ�������
	virtual  void DoDataExchange(CDataExchange *pDX);


	DECLARE_MESSAGE_MAP()


public:
	afx_msg void OnButton1();
public:
	CString m_strEditText;
	CWnd	m_wndButton1;  

};

BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_COMMAND(IDC_BUTTON1, OnButton1)
END_MESSAGE_MAP()




void CMyDialog::OnButton1()
{
	//��������
	//UpdateData(TRUE);

	//AfxMessageBox(m_strEditText);
	//m_strEditText = "������ֿ��ֿ���!";

	m_wndButton1.GetWindowText(m_strEditText);
	AfxMessageBox(m_strEditText);

//	UpdateData(FALSE);
}


void CMyDialog::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);

	//��
	DDX_Text(pDX, IDC_EDIT1, m_strEditText);

	//�󶨰�ť�ؼ�
	DDX_Control(pDX, IDC_BUTTON1, m_wndButton1); 
}





CMyDialog::CMyDialog():CDialog(IDD_DIALOG1)
{
}




class CDlgApp : public CWinApp
{

public:
	virtual BOOL InitInstance();
};

CDlgApp theApp;



BOOL CDlgApp::InitInstance()
{
	CMyDialog  dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return  TRUE;
}
