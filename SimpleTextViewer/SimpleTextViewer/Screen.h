#pragma once
#include<string>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

// ȭ�鿡 �����ִ� ������ �ϴ� Ŭ����
// �� �ٿ� 30���ڸ� �����ִ� ���� �⺻���� ����



class Screen
{
private:
	Screen();
	static Screen* Instance;
public:
	static const Screen* GetInstance();
	static void DeleteInstance();
	// ���ϴ� ������ �ؽ�Ʈ�� ����ϴ� �Լ�
	void Print(const string& ToPrint);
	
	// �� �ٴ� ��µǴ� ���� �� ����
	void SetWordsOnLine(const int& NewValue);

private:
	//�ʱ� ��ü ���� �������� ȣ��. �ʱ�ȭ�� �ʿ��� ���� txt ���Ͽ��� �ҷ��ɴϴ�.
	void initScreen();
	// ȭ���� �����ִ� �Լ�
	void clearScreen();
private:
	// �� �ٴ� ��µǴ� ���� �� �����ϴ� ����
	int  wordsOnLine;
	const char* FileAddress = "Text\Option\ScreenOption.txt";
	fstream OptionTxt;
};

