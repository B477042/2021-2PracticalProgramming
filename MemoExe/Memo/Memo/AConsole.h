#pragma once
#include"Base.h"
#include <stack>
using namespace std;

enum EOrder
{
	//�ۼ��� ���
	Write=0,
	Delete
};
typedef struct FOrderLog
{

};


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

	void loadMemo();
	class AProgram* Program;


};

