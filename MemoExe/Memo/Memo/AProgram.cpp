#include "AProgram.h"

AProgram::AProgram()
{
	bPower = true;
}

AProgram::~AProgram()
{
}

void AProgram::StartProgram()
{
	init();
	run();
	closing();
}

void AProgram::TurnOffThreads()
{
}

void AProgram::init()
{
	Console = new AConsole(this);
}

void AProgram::run()
{
	startThreads();
}

void AProgram::closing()
{
	/*
	* ������ ��� ��ü�� ����
	*/
	delete Console;
}

void AProgram::TurnOffPower()
{
	bPower = false;
}

void AProgram::startThreads() 
{
	/*
	* Thread�� �� 2��
	* Main�� ����Ǹ� ���α׷��� ����ǰ� 
	* Main�� ���۵Ǹ� 1���� Thread�� �����
	* ���� ������ Main�� ����� ��
	* 
	*/
	hThread[Idx_Main] = (HANDLE)
		_beginthreadex(
			NULL,
			0,
			AProgram::procMainThread,
			(LPVOID)(this),
			CREATE_SUSPENDED,
			(unsigned*)&dwThreadId[Idx_Main]
		);

	ResumeThread(hThread[Idx_Main]);


	WaitForSingleObject(hThread[Idx_Main], INFINITE);

}

unsigned int __stdcall AProgram::procMainThread(LPVOID InputParam)
{
	auto This = (AProgram*)InputParam;
	if (!This)
	{
		cout << "Casting FAiled\n";
		delete This;
		return -1;
	}

	

	/*
	* ������ ����
	* �� Static �Լ� �����ؼ� �־��� ��
	*/


	/*
	* ������ ����
	*/


	//�ܼ� ����
	This->Console->StartConsole();
	//�ܼ��� ����Ǹ� Main �����尡 ����ȴ�

	return 0;
}


