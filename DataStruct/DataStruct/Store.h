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
		cout << "Log : " <<storeName << " ���� ����\n";
	}

	//�̿��ڸ� �޾Ƶ��� �� ȣ��
	void AcceptClinet(Client* NewClient);
	//�̿��ڰ� ���� �� ȣ��
	void LeaveClinet(const string& Name);



private:
	//���� �̸�
	string storeName;
};

