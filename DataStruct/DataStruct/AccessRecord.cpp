#include "AccessRecord.h"
AccessRecord* AccessRecord::instance = nullptr;
const AccessRecord* AccessRecord::Instance()
{
    if (!instance)
    {
        instance = new AccessRecord();
    }

    return instance;
}

void AccessRecord::PrintLog()
{
    if (!History.empty())
    {
        cout << "방문 기록이 없습니다.\n";
        return;
    }
    
    auto it = History.begin();
    while (it != History.end())
    {
        cout << *it;
    }


}

void AccessRecord::Join( string& NewName, Entity* NewEntity)
{
    if (!NewEntity)
    {
        cout << "Warning : 새로운 방문자가 없습니다.\n";
        return;

    }
    auto find = CurrentVisitor.find(NewName);
    if (find != CurrentVisitor.end())
    {
        cout << "Warning : 지금 방문 중인 사람입니다." << endl;

    }

    CurrentVisitor.insert( pair<string,Entity*>( NewName,NewEntity ));



}

void AccessRecord::Leave(const string& Name)
{
    auto find = CurrentVisitor.find(Name);
    if (find != CurrentVisitor.end())
    {
        cout << "Warning : 없는 사람입니다." << endl;
        return;
    }

    CurrentVisitor.erase(find);
    cout << "Log : " << Name << " 이 떠났습니다.\n";

}

void AccessRecord::Exit()
{
   
    CurrentVisitor.clear();
    for (auto it : History)
    {
        delete it;
    }

    cout << "문 닫습니다.\n";
}

