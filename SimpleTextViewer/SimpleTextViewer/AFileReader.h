#pragma once

#include<fstream>
#include<iostream>
using namespace std;
/*
* �ؽ�Ʈ ������ �ҷ����� Ŭ�����Դϴ�.
* �̱������� ��������ϴ�.
* ���� : ����Ǿ� �ִ� �ؽ�Ʈ ������ �ҷ��ɴϴ�. 
*/

class AFileReader
{
	// �̱��� ó��
private:
	AFileReader();
	static AFileReader* Instance ;
public:
	static const AFileReader* GetFileReader();
	static void DeleteInstance();


};
