#pragma once

#include<fstream>
#include<iostream>
using namespace std;
/*
* 텍스트 파일을 불러오는 클래스입니다.
* 싱글톤으로 만들었습니다.
* 목적 : 내장되어 있는 텍스트 파일을 불러옵니다. 
*/

class AFileReader
{
	// 싱글톤 처리
private:
	AFileReader();
	static AFileReader* Instance ;
public:
	static const AFileReader* GetFileReader();
	static void DeleteInstance();


};
