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
	* 생성한 기능 객체들 제거
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
	* Thread는 총 2개
	* Main이 종료되면 프로그램이 종료되게 
	* Main이 시작되면 1개의 Thread를 만들기
	* 종료 조건은 Main이 종료될 때
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
	* 쓰레드 생성
	* 각 Static 함수 선언해서 넣어줄 것
	*/


	/*
	* 쓰레드 실행
	*/


	//콘솔 실행
	This->Console->StartConsole();
	//콘솔이 종료되면 Main 쓰레드가 종료된다

	return 0;
}


