#pragma once
#include<string>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

// 화면에 보여주는 역할을 하는 클래스
// 한 줄에 30글자를 보여주는 것을 기본으로 설정



class Screen
{
private:
	Screen();
	static Screen* Instance;
public:
	static const Screen* GetInstance();
	static void DeleteInstance();
	// 원하는 내용의 텍스트를 출력하는 함수
	void Print(const string& ToPrint);
	
	// 한 줄당 출력되는 글자 수 수정
	void SetWordsOnLine(const int& NewValue);

private:
	//초기 객체 생성 과정에서 호출. 초기화에 필요한 값을 txt 파일에서 불러옵니다.
	void initScreen();
	// 화면을 지워주는 함수
	void clearScreen();
private:
	// 한 줄당 출력되는 글자 수 제한하는 변수
	int  wordsOnLine;
	const char* FileAddress = "Text\Option\ScreenOption.txt";
	fstream OptionTxt;
};

