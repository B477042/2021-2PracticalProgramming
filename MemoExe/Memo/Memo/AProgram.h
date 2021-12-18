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

//Thread Index 관련 메크로
#define  Num_of_Thread 5
#define  Idx_Main 0
#define  Idx_Recorder  1
#define  Idx_Printer  2
#define  Idx_Reader  3
#define  Idx_Writer  4


//Thread에 파라메터로 보내는 구조체
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
	void turnOffThreads();
	//Main Thread 함수
	static unsigned int WINAPI procMainThread(LPVOID InputParam);

	// 크리티컬 섹션 필요하면

	//==============================================
	// 



private:


	//==============================================
	// 클래스 객체
	//메모 저장 
	ARecorder* Recorder;
	// 출력 관리
	APrinter* Printer;
	// 메모 로더
	AReader* Reader;
	// 사용자 인풋
	AInput* Writer;

	//저장된 파일 이름들 테이블, 있다면 True
	unordered_map<string,bool> FileNameTable;

	//===============================================
	//쓰레드 관련
	HANDLE hThread[Num_of_Thread];
	DWORD dwThreadId[Num_of_Thread];
};

