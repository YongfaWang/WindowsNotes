// WinHeap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Heap()
{
	//������
	HANDLE hHeap = HeapCreate(HEAP_GENERATE_EXCEPTIONS, 1024 * 1024, 0);
	printf("HeapCreate: %p\n", hHeap);

	//�����ڴ�
	char *pszBuf = (char *)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, 100);
	strcpy(pszBuf, "hello");
	printf("%s\n", pszBuf);

	//�ڴ��ͷ�
	HeapFree(hHeap, 0, pszBuf);

	//�ͷŶ�
	HeapDestroy(hHeap);
}


void HeapInfo()
{
	HANDLE hHeap = GetProcessHeap();


	//��ȡ��ǰ�������еĶ�
	HANDLE hHeaps[256] = {0};
	DWORD dwCount = GetProcessHeaps(256, hHeaps); 

	for(DWORD i = 0; i < dwCount; i++)
	{
		printf("%d: %p\n", i + 1, hHeaps[i]);
	}

}


int main(int argc, char* argv[])
{
	char *pszBuf = (char *)malloc(100);

	HeapInfo();

	Heap();
	//printf("Hello World!\n");
	return 0;
}

