#pragma once
#include "AConsole.h"
#include "ADataManager.h"
#include <unordered_map>

using namespace std;

//Thread Index ���� ��ũ��
#define  Num_of_Thread 4
#define  Idx_Main 0
#define Idx_Save 1

class AProgram;
//Thread�� �Ķ���ͷ� ������ ����ü
template<typename T>
struct FThreadParam
{
public:
	FThreadParam(T* Data,AProgram& Program):Data(Data),Program(Program){}
	T* Data;
	AProgram& Program;

};


/*
* Main Class
* �� Ŭ������ ���α׷��� �߽� Ŭ���� ������ �����մϴ�
* �ڵ������� ���� Thread�� �ϳ� �����߽��ϴ�
* 
*/
class AProgram
{
public:
	AProgram();
	~AProgram();

	void StartProgram();
	//���α׷� ����
	void TurnOffPower();
private:
	//==============================================
	// ���α׷� ���� �Լ���
	// 
	//������� ���α׷� ���� �ʱ�ȭ
	void init() ;
	//���� ���� ����
	void run();
	//���α׷� ���� �ܰ�
	void closing();
	

	//==============================================
	// ������ ���� �Լ���
	//Thread�� ����
	void startThreads();
	//Thread�� ����
	void TurnOffThreads();
	//Main Thread �Լ�
	static unsigned int WINAPI procMainThread(LPVOID InputParam);

	// ũ��Ƽ�� ���� �ʿ��ϸ�

	//==============================================
	// 
public:
	//==============================================
	// Thread ���� �ڿ�



private:


	//==============================================
	// Ŭ���� ��ü
	AConsole* Console;

	//����� ���� �̸��� ���̺�, �ִٸ� True
	unordered_map<string,bool> FileNameTable;

	//===============================================
	//������ ����
	HANDLE hThread[Num_of_Thread];
	DWORD dwThreadId[Num_of_Thread];
	//false�� �Ǹ� MainThread ����
	bool bPower;
};

