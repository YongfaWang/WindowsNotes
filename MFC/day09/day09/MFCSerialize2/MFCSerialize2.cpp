// MFCSerialize2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCSerialize2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;


//1.�̳�CObject
class CAnimal : public CObject
{
public:
	//2.������к�
	DECLARE_SERIAL(CAnimal)

public:
	virtual void Serialize(CArchive &ar);


public:
	int			m_nLeg;
	CString		m_strName;
	int			m_nHand;
};
//3.ʵ�ֺ�
IMPLEMENT_SERIAL(CAnimal, CObject, VERSIONABLE_SCHEMA | 0)


void CAnimal::Serialize(CArchive &ar)
{
	CObject::Serialize(ar); //���ø�������л�����

	UINT uSchema = ar.GetObjectSchema() ;
	if(0 == uSchema ) //�жϰ汾��
	{
		if(ar.IsLoading()) //��
		{
			ar >> m_nLeg;
			ar >> m_strName;
		}
		else if(ar.IsStoring()) //д
		{
			ar << m_nLeg;
			ar << m_strName;
		}
	}
	else //if(1 == uSchema)
	{
		if(ar.IsLoading()) //��
		{
			ar >> m_nLeg;
			ar >> m_strName;
			ar >> m_nHand;
		}
		else if(ar.IsStoring()) //д
		{
			ar << m_nLeg;
			ar << m_strName;
			ar << m_nHand;
		}
	}

}

void TestStore()
{
	CFile file;
	file.Open("C:\\obj.dat", CFile::modeCreate | CFile::modeWrite);

	//����洢��ar
	CArchive ar(&file, CArchive::store);

	CAnimal *pAnimal  = new CAnimal();
	pAnimal->m_nLeg = 9;
	pAnimal->m_strName = "����";
	pAnimal->m_nHand = 5555;
	

	//animal.Serialize(ar);

	ar << pAnimal;

	ar.Close();

	file.Close();
}

void TestLoad()
{
	CFile file;
	file.Open("C:\\obj.dat",  CFile::modeRead);

	//����洢��ar
	CArchive ar(&file, CArchive::load);

	CAnimal animal;


	//��ȡ����������
	//animal.Serialize(ar);


	//��ȡ����
	CAnimal *pAnimal = NULL;
	ar >> pAnimal;

	cout << pAnimal->m_nLeg << endl;
	cout << (LPCTSTR)pAnimal->m_strName << endl;
	cout << pAnimal->m_nHand << endl;
	ar.Close();

	file.Close();
}



int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	TestStore();
	TestLoad();
	return 0;
}


