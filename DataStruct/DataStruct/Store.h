#pragma once
#include"Client.h"
#include<iostream>
using namespace std;

class Store
{
public:
	Store(string name) :storeName(name)
	{
		cout <<"Log : " << storeName << " ���� ����\n";
	}
	~Store()
	{
		//cout << "Log : " <<storeName << " ���� ����\n";
	}

	//�̿��ڸ� �޾Ƶ��� �� ȣ��. �����ϸ� false
	bool AcceptClinet(Client* NewClient);
	//�̿��ڰ� ���� �� ȣ��. �����ϸ� false
	bool LeaveClinet(const string& Name);

	string GetName(){return storeName;}

private:
	//���� �̸�
	string storeName;
};

