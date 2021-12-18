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
	* Thread는 총 5가지
	* Main이 종료되면 프로그램이 종료되게 
	* Main이 시작되면 4개의 Thread를 생성하게 만들기
	* 종료 조건은 Main이 종료될 때
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
	* 4가지 쓰레드를 동작 시킨다.
	*/




	return 0;
}


