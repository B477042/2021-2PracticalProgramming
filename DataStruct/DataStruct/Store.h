#pragma once
#include"Client.h"
#include<iostream>
using namespace std;

class Store
{
public:
	Store(string name) :storeName(name)
	{
		cout <<"Log : " << storeName << " 영업 시작\n";
	}
	~Store()
	{
		//cout << "Log : " <<storeName << " 영업 종료\n";
	}

	//이용자를 받아들일 때 호출. 실패하면 false
	bool AcceptClinet(Client* NewClient);
	//이용자가 떠날 때 호출. 실패하면 false
	bool LeaveClinet(const string& Name);

	string GetName(){return storeName;}

private:
	//가게 이름
	string storeName;
};

