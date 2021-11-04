#pragma once
#include<iostream>
#include<map>
#include<list>
#include<string>
#include<memory>
#include"Client.h"

using namespace std;

//방문 기록을 저장하는 구조체
typedef struct HistoryData
{
public:
	HistoryData(string& name, unsigned int num = 0) :name(name), num(num)
	{

	}
	//출력용 함수
	void Log()
	{
		cout << "Name : " << name << "\t전체 " << num << "번째 입장\n";
		
	}
	
private:
	string name;
	unsigned int num;

}HistoryData;

class AccessRecord
{
private:
	AccessRecord() {}
	static AccessRecord* instance;
public:
	 static AccessRecord* const Instance();

	//방문 기록들을 출력합니다.
	void PrintLog();
	//현재 있는 사람들을 출력합니다.
	void PrintCurrentState();

	/*
	새로운 방문자를 기록합니다.
	@ NewName : 새로운 방문자의 이름
	@ NewEntity : 새로운 방문자 객체 정보
	*/
	bool Join( string& NewName,  Client* NewEntity);
	/*
	* 해당 이름의 방문자가 떠납니다.
	*/
	bool Leave(const string& Name);
	/*
	* 프로그램을 종료할 때 호출
	*/
	void Exit();


private:

	//지금 가게에 방문한 방문자들을 저장
	map<string, Client*> currentVisitor;
	//가게에 방문한 사람들의 기록을 저장
	list<HistoryData*> history;
	//오늘 총 방문자 수
	unsigned int visitorCounter=0;
};

