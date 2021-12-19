#pragma once
#include "AConsole.h"
#include "ADataManager.h"
#include <unordered_map>

using namespace std;

//Thread Index 관련 메크로
#define  Num_of_Thread 4
#define  Idx_Main 0
#define Idx_Save 1

class AProgram;
//Thread에 파라메터로 보내는 구조체
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
* 이 클래스가 프로그램의 중심 클래스 역할을 수행합니다
* 자동저장을 위해 Thread를 하나 배정했습니다
* 
*/
class AProgram
{
public:
	AProgram();
	~AProgram();

	void StartProgram();
	//프로그램 종료
	void TurnOffPower();
private:
	//==============================================
	// 프로그램 메인 함수들
	// 
	//쓰레드와 프로그램 정보 초기화
	void init() ;
	//메인 루프 실행
	void run();
	//프로그램 종료 단계
	void closing();
	

	//==============================================
	// 쓰레드 관련 함수들
	//Thread를 실행
	void startThreads();
	//Thread를 종료
	void TurnOffThreads();
	//Main Thread 함수
	static unsigned int WINAPI procMainThread(LPVOID InputParam);

	// 크리티컬 섹션 필요하면

	//==============================================
	// 
public:
	//==============================================
	// Thread 공유 자원



private:


	//==============================================
	// 클래스 객체
	AConsole* Console;

	//저장된 파일 이름들 테이블, 있다면 True
	unordered_map<string,bool> FileNameTable;

	//===============================================
	//쓰레드 관련
	HANDLE hThread[Num_of_Thread];
	DWORD dwThreadId[Num_of_Thread];
	//false가 되면 MainThread 종료
	bool bPower;
};

