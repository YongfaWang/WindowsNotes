// ProcInfo.cpp : Defines the entry point for the console application.
//
//2018-09-02  yqq  
//win32ѧϰ ֮  ���� 

#include "stdafx.h"
#include "windows.h"





void EnvString()
{
	//��ȡ���л�����Ϣ
	LPSTR pszEnv = (LPSTR)GetEnvironmentStrings();
	LPSTR pszTmp = pszEnv;
	while(pszTmp[0])
	{
		printf("%s\n", pszTmp);
		pszTmp += strlen(pszTmp) + 1 ;
	}

	//�ͷŻ�����Ϣ�ַ���
	FreeEnvironmentStrings(pszEnv);
}


void EnvVar(char *pszVarName)
{
	//���û���������ֵ
	SetEnvironmentVariable(pszVarName, "C:\\");
	char szValue[1024] = {0};
	GetEnvironmentVariable(pszVarName, szValue, sizeof(szValue));
	printf("%s\n", szValue);

}







int main(int argc, char* argv[])
{
	//EnvString();
	EnvVar("MYQQQQQ");
	printf("Hello World!\n");
	return 0;
}

