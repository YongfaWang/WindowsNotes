#include <windows.h>
#include <stdio.h>

HINSTANCE g_hInst  = NULL;

//
LRESULT CALLBACK WndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	//OutputDebugString("hello");
	switch(nMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		return 0;
	}

	return DefWindowProc(hWnd, nMsg, wParam, lParam);
}


//��������
HWND CreateButton()
{
	HWND hWnd = CreateWindow("EDIT", "Button", WS_OVERLAPPEDWINDOW, 
		0, 0, 500, 500, NULL, NULL, g_hInst, NULL);


	return hWnd;
}


//��ʾ����
void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}


//��Ϣѭ��
void Message()
{
	MSG msg = {0};
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


/*
typedef struct {
    UINT cbSize;         //�ṹ��Ĵ�С
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCTSTR lpszMenuName;
    LPCTSTR lpszClassName;
    HICON hIconSm;       //Сͼ��
} WNDCLASSEX, *PWNDCLASSEX;

style����:
	CS_HREDRAW   ����ˮƽˮƽ�仯, ���»��ƴ���
	CS_VREDRAW     ���ڴ�ֱˮƽ�仯, ���»��ƴ���
	CS_GLOBALCLASS  ����Ӧ�ó���ȫ�ִ�����
	CS_DBLCLKS    ���ڿ��Խ������˫����Ϣ
	CS_CLASSDC   �����������͵Ĵ���ʹ��ͬһ��DC��ͼ
	CS_OWNDC     ÿ���������Լ���DC
	CS_PARENTDC   ʹ�ø����ڵ�DC
	CS_NOCLOSE   ���ùر�����

cbClsExtra����:
	cbClsExtra�����ڴ������������Ϣ���ڴ�Ĵ�С
	DWORD SetClassLong(   HWND hWnd,   int nIndex,   LONG dwNewLong);  //����Ϣ���浽�ڴ���
	DWORD GetClassLong(   HWND hWnd,   int nIndex); //����Ϣ���ڴ��л�ȡ

cbWndExtra����:
	�ڴ��ڵ�������Ϣ������Լ�����Ϣ
	LONG SetWindowLong(   HWND hWnd,   int nIndex,   LONG dwNewLong);  
	LONG GetWindowLong(   HWND hWnd,   int nIndex); 



���������غ���:

//ע�ᴰ����
ATOM RegisterClassEx(CONST WNDCLASSEX *lpwcx);

//ע��������
BOOL UnregisterClass(   LPCTSTR lpClassName,   HINSTANCE hInstance); 

//��ȡע����Ϣ
 BOOL GetClassInfoEx(
	HINSTANCE hinst,
    LPCTSTR lpszClass,
    LPWNDCLASSEX lpwcx
);



������������ζ�λ������:
   1.����Ӧ�ó���ֲ��Ĵ�����
   2.����ҵ�����һ�µĴ�����, ��Ƚ�HINSTANCE���
          ���һ��:��ʹ���ҵ��Ĵ�������Ϣ����������Ϣ
		  �����ͬ, ��������
   3.���δ�ҵ�����һ�µĴ�����, �������Ӧ�ó���ȫ�ִ������в���
          ����ҵ�: ֱ�Ӵ�������
		  ���δ�ҵ�: ȥϵͳȫ�ִ������в���, ����ҵ�,�򴴽�����; ���δ�ҵ�,����ʧ��.

 
  ����˳��: Ӧ�þֲ�������-->Ӧ�ó���ȫ����-->ϵͳȫ�ִ�����



����������غ���:
HWND CreateWindow(   
	LPCTSTR lpClassName,   
	LPCTSTR lpWindowName, 
	DWORD dwStyle,   
	int x,   
	int y,   
	int nWidth,   
	int nHeight, 
	HWND hWndParent,  
	HMENU hMenu,   
	HANDLE hInstance,   
	PVOID lpParam ); 

HWND CreateWindowEx(  
		DWORD dwExStyle,  
		LPCTSTR lpClassName, 
		LPCTSTR lpWindowName,   
		DWORD dwStyle,   
		int x,  
		int y,   
		int nWidth, 
		int nHeight,   
		HWND hWndParent,  
		HMENU hMenu,  
		HINSTANCE hInstance, 
		LPVOID lpParam ); 




*/


BOOL RegisterWnd(LPSTR pszClassName)
{
	WNDCLASSEX wce = {0};
	wce.cbSize		= sizeof(wce);
	wce.style		= CS_HREDRAW | CS_VREDRAW;   //CS_GLOBALCLASSȫ��
	wce.lpfnWndProc	= WndProc;
	wce.cbClsExtra	= 100;    //���洰������Ϣ
	wce.cbWndExtra	= 100;     //�洰�ڵ���Ϣ
	wce.hCursor		= NULL;
	wce.hIcon		= NULL;
	wce.hbrBackground = HBRUSH(COLOR_BTNFACE + 1);
	wce.lpszClassName = pszClassName;
	wce.hInstance		= g_hInst;

	ATOM nAtom =   RegisterClassEx(&wce); 
	if(0 == nAtom)
		return FALSE;
	
	return TRUE;
}


//���ø�����Ϣ
void SetExtra(HWND hWnd)
{
	SetClassLong(hWnd, 0, 100);
	SetWindowLong(hWnd, 0, 200);
}


void GetExtra(HWND hWnd)
{
	DWORD nClss = GetClassLong(hWnd, 0);
	DWORD nWnd = GetWindowLong(hWnd, 0);


	CHAR szText[1024] = {0};
	sprintf(szText, "%d   %d", nClss, nWnd);

	MessageBox(hWnd, szText, "tip", MB_OK);
}



HWND CreateWnd(LPSTR pszClassName)
{

	HWND hWnd = CreateWindow(pszClassName, "MyWnd", WS_OVERLAPPEDWINDOW, 0, 0, 
		1000, 500, NULL, NULL, g_hInst, NULL);
	return hWnd;
}


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR pszCmdLine, int nShowCmd)
{
	g_hInst = hInst;
	//HWND hWnd =  CreateButton();
	//DisplayWnd(hWnd);


	RegisterWnd("MyWnd1");
	HWND hMyWnd1 = CreateWnd("MyWnd1");
	HWND hMyWnd2 = CreateWnd("MyWnd1");
	SetExtra(hMyWnd1);
	GetExtra(hMyWnd1);

	//SetExtra(hMyWnd2);
	GetExtra(hMyWnd2);

	DisplayWnd(hMyWnd1);
	Message();

	return 0;
}