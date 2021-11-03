#pragma once
#include <string>

using namespace std;

class Entity
{
public:
	Entity(const string& Name){}
	string GetName()const { return name; }
private:
	string name;
};

