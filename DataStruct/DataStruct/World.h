#pragma once
#include"Store.h"

/*
* UI ���� Ŭ����
* 
*/
class World
{
public:
	World();
	~World()
	{
		End();
	}
	void Start();
	void End();
private:
	void run();
	void addNewClinet(string& Name);
	void leaveClinet(string& Name);

	Store* store;
	char input;
};

