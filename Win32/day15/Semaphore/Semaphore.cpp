// Semaphore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "windows.h"

HANDLE g_hSemaphore = NULL;


DWORD WINAPI ThreadSend(LPVOID pParam)
{
	while(1)
	{
		ReleaseSemaphore(g_hSemaphore, 5, NULL); //�ͷ��ź���
	}

}

DWORD WINAPI ThreadRecv(LPVOID pParam)
{
	while(1)
	{
		WaitForSingleObject(g_hSemaphore, INFINITE);
		printf("hahahahhah-------\n");
		Sleep(1000);
	}

	
	return 0;
}


void Create()
{
	DWORD iThreadID = 0;
	HANDLE hThreads[2] = {0};
	hThreads[0] = CreateThread(NULL, 0, ThreadSend, NULL, 0, &iThreadID);
	hThreads[1] = CreateThread(NULL, 0, ThreadRecv, NULL, 0, &iThreadID);


	WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
}






int main(int argc, char* argv[])
{
	g_hSemaphore= CreateSemaphore(NULL, 5, 10, NULL); //�����ź���

	
	Create(); //�����߳�

	//ReleaseSemaphore(g_hSemaphore); //�ͷ��ź���

	CloseHandle(g_hSemaphore); //�ر��ź���
	printf("Hello World!\n");
	return 0;
}

