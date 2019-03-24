// WinMap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"


void Map()
{
	//�����ļ�
	HANDLE hFile = CreateFile("C:\\VC\\day13\\map.dat", GENERIC_READ|GENERIC_WRITE,
		0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	//�����ļ�ӳ��
	HANDLE hMap = CreateFileMapping(hFile, NULL, 
		PAGE_READWRITE, 0, 1024 * 1024, NULL);


	//ӳ���ַ
	char *pszText = (char *)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS,  0, 0, 1024 * 1024);


	strcpy(pszText, "hello world hahahha I'm happy!\n");
	printf("%s\n", pszText);


	//ж��ӳ���ַ
	UnmapViewOfFile(pszText);



	//�ر��ļ�ӳ�� 
	CloseHandle(hMap);

	
	//�ر��ļ�
	CloseHandle(hFile);
}



int main(int argc, char* argv[])
{
	Map();
	printf("Hello World!\n");
	return 0;
}

