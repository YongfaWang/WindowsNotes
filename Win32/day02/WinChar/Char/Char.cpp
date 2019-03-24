// Char.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>


void C_wChar()
{
	wchar_t cStr = 'a';
	//wchar_t *pszCh = L"ABCD";
	wchar_t *pszCh = L"���ﳤ��";
	printf("len=%d\n", wcslen(pszCh));
	//printf("%s\n", pszCh);
	wprintf(L"%s\n", pszCh);

	char *pCh = "���ﳤ��";
	printf("len=%d\n", strlen(pCh));
	printf("%s\n", pCh);
}



void CodePage(int nCodePage)
{
	SetConsoleOutputCP(nCodePage); //�޸ĵ�ǰ����̨������ַ���  

	for(int i = 0; i < 256; i++)
	{
		printf("%c ", i);
	}
}

void PrintASCII()
{
	for(int i = 0; i < 256; i++)
	{
		printf("%c ", i);
	}
}

void Multi2Wide()
{
	CHAR *pszText = "Multi2Wide";
	
	//1.�Ȼ�ȡת����ĳ���
	int iLen = MultiByteToWideChar(CP_ACP/*ascii code page*/, 0, pszText, strlen(pszText), NULL/* ���ؽ��*/, 0 );
	WCHAR *pwszText  = (WCHAR *)malloc(iLen + 1);

	//2.Ȼ��Ż�ȡ����ֲ
	MultiByteToWideChar(CP_ACP/*ascii code page*/, 0, pszText, strlen(pszText), pwszText/* ���ؽ��*/, 0 );
	free(pwszText);

	MessageBoxW(NULL, pwszText, L"Wide", MB_OK);
}


int main(int argc, char* argv[])
{
	//printf("Hello World!\n");
	//PrintASCII();

	//CodePage(437);
	//C_wChar();
	Multi2Wide();
	return 0;
}

