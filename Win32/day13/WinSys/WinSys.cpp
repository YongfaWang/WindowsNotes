// WinSys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"


void ShowSys()
{
	SYSTEM_INFO info = {0};
	GetSystemInfo(&info);

	printf("�ڴ�ҳ�Ĵ�С:%d\n", info.dwPageSize);
	printf("���õ���С�ڴ�:%d\n", info.lpMinimumApplicationAddress);
	printf("�ڴ��������:%d\n", info.dwAllocationGranularity);

}





int main(int argc, char* argv[])
{
	ShowSys();

	printf("Hello World!\n");
	return 0;
}

