// WinDir.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"



void ShowDirectory()
{
	//��ȡwindows Ŀ¼
	CHAR szWindow[MAX_PATH] = {0};
	GetWindowsDirectory(szWindow, MAX_PATH);
	printf("WindowsDirectory: %s\n", szWindow);

	//��ȡsystemĿ¼
	CHAR szSystem[MAX_PATH] = {0};
	GetSystemDirectory(szSystem, MAX_PATH);
	printf("SystemDirectory: %s\n", szSystem);


	//��ȡ��ʱ�ļ�Ŀ¼
	CHAR szTemp[MAX_PATH] = {0};
	GetTempPath(MAX_PATH, szTemp);
	printf("szTempDirectory: %s\n", szTemp);


	//���õ�ǰĿ¼
	SetCurrentDirectory("C:\\");

	//��ȡ��ǰĿ¼
	CHAR szCur[MAX_PATH] = {0};
	GetCurrentDirectory(MAX_PATH, szCur);
	printf("CurDirectory: %s\n", szCur);

}







int main(int argc, char* argv[])
{
	ShowDirectory();
	printf("Hello World!\n");
	return 0;
}

