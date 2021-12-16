#pragma once
#include"APrinter.h"
#include"AReader.h"
#include"ARecorder.h"
#include"AInput.h"

class AProgram
{
public:
	AProgram();
	~AProgram();

	void StartProgram()const;

private:
	void init();

private:

	//메모 저장 
	ARecorder* Recorder;
	// 출력 관리
	APrinter* Printer;
	// 메모 로더
	AReader* Reader;
	// 사용자 인풋
	AInput* Writer;

};

