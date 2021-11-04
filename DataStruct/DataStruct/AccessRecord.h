#pragma once
#include<iostream>
#include<map>
#include<list>
#include<string>
#include<memory>
#include"Client.h"

using namespace std;

//�湮 ����� �����ϴ� ����ü
typedef struct HistoryData
{
public:
	HistoryData(string& name, unsigned int num = 0) :name(name), num(num)
	{

	}
	//��¿� �Լ�
	void Log()
	{
		cout << "Name : " << name << "\t��ü " << num << "��° ����\n";
		
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

	//�湮 ��ϵ��� ����մϴ�.
	void PrintLog();
	//���� �ִ� ������� ����մϴ�.
	void PrintCurrentState();

	/*
	���ο� �湮�ڸ� ����մϴ�.
	@ NewName : ���ο� �湮���� �̸�
	@ NewEntity : ���ο� �湮�� ��ü ����
	*/
	bool Join( string& NewName,  Client* NewEntity);
	/*
	* �ش� �̸��� �湮�ڰ� �����ϴ�.
	*/
	bool Leave(const string& Name);
	/*
	* ���α׷��� ������ �� ȣ��
	*/
	void Exit();


private:

	//���� ���Կ� �湮�� �湮�ڵ��� ����
	map<string, Client*> currentVisitor;
	//���Կ� �湮�� ������� ����� ����
	list<HistoryData*> history;
	//���� �� �湮�� ��
	unsigned int visitorCounter=0;
};

