#pragma once
#include"Store.h"

/*
* UI 제공 클래스
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

