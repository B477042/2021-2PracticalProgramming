#include "Problem2.h"


/*
* ������ ����
*/
void Problem2::Run()
{
	vector<int>InputArray = { 4,4,2,4,-1,-1 };
	//������
	Node* Start = new Node(0);
	//5�� ���
	Node* Node5 = new Node(5);
	//10�� ���
	Node* Node10 = new Node(10);
	//15�� ���
	Node* Node15 = new Node(15);
	//22�� ���
	Node* Node22 = new Node(22);


	//��� ����
	//Start--->19, �ܰ��ѹ���
	Node* pNode = nullptr;
	for (int i = 0; i < 20; ++i)
	{
		//ù �����̶��
		if (i == 0)
		{
			pNode = Start;
			continue;
		}
		//Ư�����
		if (i == 5)
		{
			pNode->next = Node5;
			pNode = pNode->next;
			continue;
		}
		else if (i == 10)
		{
			pNode->next = Node10;
			pNode = pNode->next;
			continue;
		}
		else if (i == 15)
		{
			pNode->next = Node15;
			pNode = pNode->next;
			continue;
		}
		Node* tempNode = new Node(i);
		pNode->next = tempNode;
		if (i == 19)
		{
			pNode = pNode->next;
			pNode->next = Start;
		}
		else
		{
			pNode = pNode->next;
		}
		

	}


	//������ ����
	//5->15
	pNode = Node5;
	for (int i = 20; i < 25; ++i)
	{
		if (i == 22)
		{
			pNode->shortcut = Node22;
			pNode = pNode->shortcut;
			continue;
		}
		
		Node* tempNode = new Node(i);
		pNode->shortcut = tempNode;
		if(i!=24)
			pNode = pNode->shortcut;
		else
		{
			//pNode
		}
		
		

	}



}
