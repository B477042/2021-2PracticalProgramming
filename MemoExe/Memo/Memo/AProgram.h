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

	//�޸� ���� 
	ARecorder* Recorder;
	// ��� ����
	APrinter* Printer;
	// �޸� �δ�
	AReader* Reader;
	// ����� ��ǲ
	AInput* Writer;

};

