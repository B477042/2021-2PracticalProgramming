#pragma once
#include<iostream>
#include<map>
#include<list>
#include<string>
#include<memory>
#include"Entity.h"

using namespace std;

//방문 기록을 저장하는 구조체
typedef struct HistoryData
{
public:
	HistoryData(string& name, unsigned int num = 0) :name(name), num(num)
	{

	}
	//출력용 함수
	friend ofstream& operator << (ofstream& out,const HistoryData& Other)
	{
		cout << "Name : " << Other.name << "\t전체 " << Other.num << "번째 입장\n";
		return out;
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
	const static AccessRecord* Instance();

	//방문 기록들을 출력합니다.
	void PrintLog();
	/*
	새로운 방문자를 기록합니다.
	@ NewName : 새로운 방문자의 이름
	@ NewEntity : 새로운 방문자 객체 정보
	*/
	void Join( string& NewName,  Entity* NewEntity);
	/*
	* 해당 이름의 방문자가 떠납니다.
	*/
	void Leave(const string& Name);
	/*
	* 프로그램을 종료할 때 호출
	*/
	void Exit();


private:
	map<string, Entity*> CurrentVisitor;
	list<HistoryData*> History;
	unsigned int VisitorCounter;
};

