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
	Store* Store;
};

