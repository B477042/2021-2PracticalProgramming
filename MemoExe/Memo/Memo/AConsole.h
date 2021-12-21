#pragma once
#include"Base.h"
#include <stack>
#include <sstream>
using namespace std;

//enum EOrder
//{
//	//작성할 경우
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
	
	//타이틀 화면 출력
	void hello();
	//New Memo
	void newMemo();
	//메모를 적을 때 호출
	void writting(const string& FileName);
	//방향키 조작
	void arrowAction(const int& num);
	//백 스페이스 누를 경우 호출
	void deleteChar(const char& Prev, const string& FileName);
	//다른 이름으로 저장
	void saveFile(const string& Origin);
	

	void loadMemo();
	class AProgram* Program;
	ofstream CurrentWrittingFile;
	ifstream CurrentReadFile;

	//저장된 Text 목록 txt
	fstream SaveData;


	stringstream SS;

};

