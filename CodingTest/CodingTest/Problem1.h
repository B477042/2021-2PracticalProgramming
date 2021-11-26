#pragma once
#include "master.h"
using namespace std;

class Problem1
{
public:
	Problem1(){}
	void Run() const;
private:
	//한 개의 숫자 범위를 입력 받습니다. 
	void inputNumber(int From, int To);
	void calcRange();
	
};

