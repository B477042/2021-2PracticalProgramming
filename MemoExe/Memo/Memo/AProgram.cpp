#include "AProgram.h"

AProgram::AProgram()
{
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

void AProgram::init()
{

}

void AProgram::run()
{
	startThreads();
}

void AProgram::closing()
{

}

void AProgram::startThreads() 
{
	/*
	* Thread�� �� 5����
	* Main�� ����Ǹ� ���α׷��� ����ǰ� 
	* Main�� ���۵Ǹ� 4���� Thread�� �����ϰ� �����
	* ���� ������ Main�� ����� ��
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
	* 4���� �����带 ���� ��Ų��.
	*/




	return 0;
}


