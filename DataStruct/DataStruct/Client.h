#pragma once
#include <string>

using namespace std;

class Client
{
public:
	Client(const string& Name):name(Name){}
	string GetName() { return name; }
private:
	string name;
};

