#include<iostream>
#include"World.h"
using namespace std;

/*
* 출입 명부 프로그램
* 
*/

int main()
{
	World world;
	world.Start();
	world.End();
	
	cout << "종료" << endl;
	return 0;
}