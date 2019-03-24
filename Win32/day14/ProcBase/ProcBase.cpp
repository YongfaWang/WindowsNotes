// ProcBase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
//#include "psapi.h"

typedef BOOL WINAPI  (*EnumProcessModules)(HANDLE,HMODULE *,DWORD,LPDWORD);


void ProcInfo()
{
	//��ȡ����id
	DWORD iID = GetCurrentProcessId();
	//��ȡ���̾��(α���)
	HANDLE hProc = GetCurrentProcess();

	//��ȡ��ʵ�Ľ��̾��
	HANDLE hProcReal = OpenProcess(PROCESS_ALL_ACCESS, FALSE, iID);

	HMODULE hModules[256] = {0};
	DWORD iNeed  = 0;
	HINSTANCE hDLL = LoadLibrary("PSAPI.DLL");
	if(hDLL)
	{
		EnumProcessModules func = (EnumProcessModules)GetProcAddress(hDLL,"EnumProcessModules");
		if(func)
		{
			func(hProcReal, hModules, 256, &iNeed);
		}
		
		DWORD iCount = iNeed / sizeof(HMODULE);
		for(DWORD i = 0; i < iCount; i++)
		{
			printf("%d:%p\n", i + 1, hModules[i]);
		}
	}
}


void ProcModule()
{
}




int main(int argc, char* argv[])
{
	ProcInfo();
//	printf("Hello World!\n");
	return 0;
}

