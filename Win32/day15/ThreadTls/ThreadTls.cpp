// ThreadTls.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdio.h"
#include "stdlib.h"
#include <windows.h>

//__declspec(thread) char *g_pszText = NULL;   //ÿ���̵߳�����һ��

char *g_pszText = NULL; //����̹߳���һ��, �ᵼ�º����߸���ǰ������� 



//����������
DWORD g_iTlsIndex = 0;



void Print()
{
//	printf("%s\n", g_pszText);

	//3.��TLS�����л�ȡֵ
	CHAR *pszText = (CHAR *)TlsGetValue(g_iTlsIndex);
	printf("Tls: %s\n", pszText);
}

DWORD WINAPI ThreadProc(LPVOID lParam)
{
	char *pszText = (char *)lParam;
	g_pszText = (CHAR *)malloc(strlen(pszText) + 1);
	memset(g_pszText, 0, strlen(pszText) + 1);
	strcpy(g_pszText, (CHAR *)lParam);


	//2.��ֵ���浽TLS��������
	TlsSetValue(g_iTlsIndex, g_pszText);

	while(1)
	{
		Print();
		Sleep(1000);
	}
}

void Create()
{
	HANDLE hThread = NULL;
	DWORD iThreadID = 0;

	CHAR szText[]  = "Thread Proc1---------";

	hThread = CreateThread(NULL, 0, ThreadProc, szText, 0, &iThreadID);
	

	CHAR szText2[]  = "Thread Proc2---------";
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadProc, szText2, 0, &iThreadID);
	WaitForSingleObject(hThread, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
}



int main(int argc, char* argv[])
{

	//1.����TLS����������
	g_iTlsIndex = TlsAlloc();

	Create();

	//�ͷ�������
	TlsFree(g_iTlsIndex);
	printf("Hello World!\n");
	return 0;
}

