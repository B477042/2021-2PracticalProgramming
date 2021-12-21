#pragma once
#include"Base.h"
#include <stack>
#include <sstream>
using namespace std;

//enum EOrder
//{
//	//�ۼ��� ���
//	Write=0,
//	Delete
//};
//typedef struct FOrderLog
//{
//
//};


class AConsole
{
public:
	AConsole(class AProgram* Program) :Program(Program)
	{

	}
	~AConsole();
	//static unsigned int WINAPI procThread(LPVOID InputParam);
	void StartConsole();


private:
	
	//Ÿ��Ʋ ȭ�� ���
	void hello();
	//New Memo
	void newMemo();
	//�޸� ���� �� ȣ��
	void writting(const string& FileName);
	//����Ű ����
	void arrowAction(const int& num);
	//�� �����̽� ���� ��� ȣ��
	void deleteChar(const char& Prev, const string& FileName);
	//�ٸ� �̸����� ����
	void saveFile(const string& Origin);
	

	void loadMemo();
	class AProgram* Program;
	ofstream CurrentWrittingFile;
	ifstream CurrentReadFile;

	//����� Text ��� txt
	fstream SaveData;


	stringstream SS;

};

