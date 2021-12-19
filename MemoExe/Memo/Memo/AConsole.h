#pragma once
#include"Base.h"
using namespace std;


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
	void loadMemo();
	class AProgram* Program;
};

