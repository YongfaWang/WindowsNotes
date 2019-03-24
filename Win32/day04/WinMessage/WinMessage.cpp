#include <windows.h>

HINSTANCE g_hInst = NULL;

LRESULT CALLBACK WndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	switch(nMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		return 0;
	}


	return DefWindowProc(hWnd, nMsg, wParam, lParam);
}



BOOL RegisterWnd(LPSTR pszClassName)
{
	WNDCLASSEX wce = {0};
	wce.cbSize = sizeof(wce);
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = HBRUSH(COLOR_BTNFACE + 1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInst;
	wce.lpfnWndProc = WndProc;  //���ڴ�����
	wce.lpszClassName = pszClassName;
	wce.lpszMenuName = NULL;
	wce.style = CS_VREDRAW | CS_HREDRAW;

	ATOM nAtom = RegisterClassEx(&wce);
	if(0 == nAtom)
		return FALSE;

	return TRUE;
}


HWND CreateWnd(LPSTR pszClassName)
{
	return CreateWindowEx(0, pszClassName, "MyWnd", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
						CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, g_hInst, NULL);
}



void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}


/*

BOOL GetMessage(  
	LPMSG lpMsg,  //��Ż�ȡ������Ϣ����
	HWND hWnd,    //��ȡָ�����ھ������Ϣ
	UINT wMsgFilterMin,  //��Ϣ���˵���ʼ��Ϣ
	UINT wMsgFilterMax );  //��Ϣ���˵���ֹ��Ϣ
	��ȡ����Ϣʱ����TRUE
	����ȡ�� WM_QUIT��Ϣʱ����FALSE



void PostQuitMessage(  int nExitCode ); 




BOOL TranslateMessage(  const MSG* lpMsg );  
 //��������Ϣת��Ϊ�ַ���Ϣ
     1.�����Ƿ��Ǽ��̰�����Ϣ
	       �����:  �����ݰ���,����һ���ַ���Ϣ, ����һ��GetMessageִ��ʱ���ܵ������Ϣ
	       �������: �����κδ���



LONG DispatchMessage(  const MSG* lpmsg );
//������Ϣ�����ڴ��ھ��, �ҵ�������ڵĴ�����, ���ô�����, ������Ϣ����
//���MSG�й�, HWND���ھ��Ϊ��, DispatchMessage�����κδ���


 LRESULT DefWindowProc(  
  HWND hWnd,  
  UINT Msg,  
  WPARAM wParam, 
  LPARAM lParam ); 
//ʹ��ϵͳĬ�ϴ�����������Ϣ




typedef struct tagMSG {     // msg  
   HWND hwnd;   //ָ����Ϣ�����Ĵ��ھ��
   UINT message;   //��Ϣ
   WPARAM wParam;  //��Ϣ������ֵ
   LPARAM lParam;  ///��Ϣ������ֵ
   DWORD time;     
   POINT pt;  //�������λ��
} MSG;



 ������Ϣ:
	1.WM_DESTROY   //��������ʱ����Ϣ,   (�������˳�����)
	2.WM_CREATE    //���ڴ�����, ���ڴ������յ��ĵ�һ����Ϣ,  (��������ʼ������,�����Ӵ���)
	3.WM_SIZE   //�����ڴ�С�����仯ʱ,���յ�����Ϣ   (�������ڵ������ڲ���)
	4.WM_SYSCOMMAND  //ϵͳ������Ϣ,  ������˵�ѡ��Ͱ�ťʱ���յ�����Ϣ.(�����������Ϣ����ʾ�û���������)
	5.WM_PAINT   //��ͼ��Ϣ, 
	6.������Ϣ
	7.�����Ϣ
	8.WM_TIMER  //��ʱ����Ϣ


 */




void Message()
{
	MSG msg = {0};
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}



int WINAPI WinMain(
				   HINSTANCE hInst,
				   HINSTANCE hPrevInst,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	g_hInst = hInst;

	RegisterWnd("MyWnd1");
	HWND hWnd1 =  CreateWnd("MyWnd1");
	DisplayWnd(hWnd1);
	Message();


	return 0;
}