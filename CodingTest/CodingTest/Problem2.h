#pragma once
#include "master.h"

using namespace std;

typedef struct Node
{
public:
	Node(int num,Node* next=nullptr,Node* shortcut=nullptr) :num(num),next(next),shortcut(shortcut)
	{

	}
	~Node()
	{
		if (next != nullptr)
		{
			delete next;
			next = nullptr;
		}
		if (shortcut != nullptr)
		{
			delete shortcut;
			shortcut = shortcut;
		}
	}
	int num;
	Node* next;
	Node* shortcut;
}Node;

class Problem2
{
public:
	Problem2(){}
	void Run();

	
};

