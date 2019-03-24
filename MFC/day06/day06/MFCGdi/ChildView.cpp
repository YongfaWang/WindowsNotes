// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "MFCGdi.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_COMMAND(ID_PEN, OnPen)
	ON_COMMAND(ID_BRUSH, OnBrush)
	ON_COMMAND(ID_BITMAP, OnBitmap)
	ON_COMMAND(ID_IMAGE, OnImage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}


void CChildView::OnPen() 
{
	//��������
	CPen pen(PS_SOLID, 10, RGB(0, 0, 255));

	//�ͻ���DC
	CClientDC dc(this);

	//ѡ�񻭱�
	CPen *pOldPen = dc.SelectObject(&pen);

	//��ͼ
	dc.Rectangle(300, 300, 200, 200);

	//ѡ������
	dc.SelectObject(pOldPen);

}



void CChildView::OnBrush() 
{
	//������ˢ
	CBrush brush(HS_CROSS, RGB(0, 0, 255));
	//�ͻ���DC
	CClientDC dc(this);

	//ѡ��ˢ
	CBrush *pOldBrush = dc.SelectObject(&brush);

	//��ͼ
	dc.Rectangle(500, 500, 150, 150);

	dc.SelectObject(pOldBrush);
}

void CChildView::OnBitmap() 
{
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	
	//����dc
	CClientDC dc(this);
	CDC dcBmp;
	dcBmp.CreateCompatibleDC(&dc);

	//��λͼ����DC��
	CBitmap *pOldBmp = dcBmp.SelectObject(&bmp);

	//����λͼ
	dc.BitBlt(500, 500, 100, 100, &dcBmp, 0, 0, SRCCOPY);

	//ѡ��λͼ
	dcBmp.SelectObject(pOldBmp);

}

void CChildView::OnImage() 
{
	// TODO: Add your command handler code here
	HANDLE hImg =	LoadImage(NULL, "C:\\Sunset.bmp", IMAGE_BITMAP, 
						0,
						0,
						LR_DEFAULTCOLOR|LR_LOADFROMFILE|LR_DEFAULTSIZE);
	
	BITMAP bitmap = {0};
	GetObject(hImg, sizeof(bitmap), &bitmap);
	

	//����λͼ����
	CBitmap bmp;
	bmp.Attach(hImg);


	//����dc
	CClientDC dc(this);
	CDC dcBmp;
	dcBmp.CreateCompatibleDC(&dc);
	CBitmap *pOldBmp = dcBmp.SelectObject(&bmp);
	dc.BitBlt(0, 0, bitmap.bmWidth, bitmap.bmHeight, &dcBmp, 0, 0, SRCCOPY);

	dc.SelectObject(pOldBmp);
}
