// ProcUse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <stdlib.h>

//��������
void Create()
{
	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};
	/*
	CreateProcess("C:\\WINDOWS\\System32\\winmine.exe", 
			NULL, NULL, NULL, FALSE,
			0, NULL, NULL, &si, &pi);
			*/

	CreateProcess("ChildProc.exe", 
			NULL, NULL, NULL, FALSE,
			CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);  //CREATE_NEW_CONSOLE �ӽ��̴����µĿ���̨

	


}


void Terminate(DWORD dwProcID)
{
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcID);
	TerminateProcess(hProc, 0); //��������
}


void Wait()
{
	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};
	
	CreateProcess("C:\\WINDOWS\\System32\\winmine.exe", 
			NULL, NULL, NULL, FALSE,
			0, NULL, NULL, &si, &pi);
	printf("winmine.exe is running....\n");
	WaitForSingleObject(pi.hProcess, INFINITE);  //�����ȴ��ӽ��̽���
}

int main(int argc, char* argv[])
{
	Wait();
	//Create();
	//Terminate(488); 
	printf("Hello World!\n");
	system("pause");
	return 0;
}

