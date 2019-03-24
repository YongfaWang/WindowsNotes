// UseDll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../DllInterface/mymath.h"

typedef IMath *( *CREATEINSTANCE)();

IMath *CreateInst()
{
	//���ض�̬��
	HMODULE hDll = (HMODULE)LoadLibrary("DllInterface.dll");

	//��ȡ�����ӿڵĺ���
	CREATEINSTANCE CreateInstance = (CREATEINSTANCE) GetProcAddress(hDll, "CreateInstance");
	
	//�����ӿ�
	IMath *piMath = CreateInstance();

	return piMath;
}

int main(int argc, char* argv[])
{
	IMath *piMath = CreateInst();
	piMath->AddRef(); //�������ü���

	printf("%d\n", piMath->Add(100, 100));

	piMath->Release(); //�������ü���
	
	return 0;
}

