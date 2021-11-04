#include "AccessRecord.h"
AccessRecord* AccessRecord::instance = nullptr;
 AccessRecord* const AccessRecord::Instance()
{
    if (!instance)
    {
        instance = new AccessRecord();
    }

    return instance;
}

void AccessRecord::PrintLog()
{
    if (!history.empty())
    {
        cout << "방문 기록이 없습니다.\n";
        return;
    }
    
    auto it = history.begin();
    while (it != history.end())
    {
        cout << *it;
    }


}

void AccessRecord::Join( string& NewName, Client* NewEntity)
{
    if (!NewEntity)
    {
        cout << "Warning : 새로운 방문자가 없습니다.\n";
        return;

    }
    auto find = currentVisitor.find(NewName);
    if (find != currentVisitor.end())
    {
        cout << "Warning : 지금 방문 중인 사람입니다." << endl;

    }

    currentVisitor.insert( pair<string,Client*>( NewName,NewEntity ));

    ++visitorCounter;
    HistoryData* NewData = new HistoryData(NewName, visitorCounter);
    history.push_back(NewData);
}





void AccessRecord::Leave(const string& Name)
{
    auto find = currentVisitor.find(Name);
    if (find != currentVisitor.end())
    {
        cout << "Warning : 없는 사람입니다." << endl;
        return;
    }

    currentVisitor.erase(find);
    cout << "Log : " << Name << " 이 떠났습니다.\n";

}

void AccessRecord::Exit()
{
   
    currentVisitor.clear();
    for (auto it : history)
    {
        delete it;
    }
   
    

    cout << "문 닫습니다.\n";
}

