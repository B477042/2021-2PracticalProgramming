#pragma once
#include<iostream>
#include<map>
#include<list>
#include<string>
#include<memory>
#include"Entity.h"

using namespace std;

//�湮 ����� �����ϴ� ����ü
typedef struct HistoryData
{
public:
	HistoryData(string& name, unsigned int num = 0) :name(name), num(num)
	{

	}
	//��¿� �Լ�
	friend ofstream& operator << (ofstream& out,const HistoryData& Other)
	{
		cout << "Name : " << Other.name << "\t��ü " << Other.num << "��° ����\n";
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

	//�湮 ��ϵ��� ����մϴ�.
	void PrintLog();
	/*
	���ο� �湮�ڸ� ����մϴ�.
	@ NewName : ���ο� �湮���� �̸�
	@ NewEntity : ���ο� �湮�� ��ü ����
	*/
	void Join( string& NewName,  Entity* NewEntity);
	/*
	* �ش� �̸��� �湮�ڰ� �����ϴ�.
	*/
	void Leave(const string& Name);
	/*
	* ���α׷��� ������ �� ȣ��
	*/
	void Exit();


private:
	map<string, Entity*> CurrentVisitor;
	list<HistoryData*> History;
	unsigned int VisitorCounter;
};

