#pragma once
#include"APrinter.h"
#include"AReader.h"
#include"ARecorder.h"
#include"AInput.h"
#include<unordered_map>
#include <thread>
#include <Windows.h>
#include <process.h>
using namespace std;

//Thread Index ���� ��ũ��
#define  Num_of_Thread 5
#define  Idx_Main 0
#define  Idx_Recorder  1
#define  Idx_Printer  2
#define  Idx_Reader  3
#define  Idx_Writer  4


//Thread�� �Ķ���ͷ� ������ ����ü
template<typename T>
struct FThreadParam
{
public:
	FThreadParam(T* Data):Data(Data){}
	T* Data;
	AProgram Program;

};

class AProgram
{
public:
	AProgram();
	~AProgram();

	void StartProgram();

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
	void turnOffThreads();
	//Main Thread �Լ�
	static unsigned int WINAPI procMainThread(LPVOID InputParam);

	// ũ��Ƽ�� ���� �ʿ��ϸ�

	//==============================================
	// 



private:


	//==============================================
	// Ŭ���� ��ü
	//�޸� ���� 
	ARecorder* Recorder;
	// ��� ����
	APrinter* Printer;
	// �޸� �δ�
	AReader* Reader;
	// ����� ��ǲ
	AInput* Writer;

	//����� ���� �̸��� ���̺�, �ִٸ� True
	unordered_map<string,bool> FileNameTable;

	//===============================================
	//������ ����
	HANDLE hThread[Num_of_Thread];
	DWORD dwThreadId[Num_of_Thread];
};

