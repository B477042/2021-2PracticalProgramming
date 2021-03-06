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
    if (history.empty())
    {
        cout << "방문 기록이 없습니다.\n";
        return;
    }
    
    for (auto it : history)
    {
        it->Log();
    }


}

void AccessRecord::PrintCurrentState()
{
    cout<<"현재 가게에 있는 사람들입니다.\n";
    int i = 1;
    for(auto it:currentVisitor)
    {
        cout<<i<<" : "<<it.first << "\n";
        ++i;
    }
}


bool AccessRecord::Join( string& NewName, Client* NewEntity)
{
    
    if (!NewEntity)
    {
        cout << "Warning : 새로운 방문자가 없습니다.\n";
        return false;

    }
    auto find = currentVisitor.find(NewName);
    if (find != currentVisitor.end())
    {
        cout << "Warning : 지금 방문 중인 사람입니다." << endl;
        return false;
    }

    currentVisitor.insert( pair<string,Client*>( NewName,NewEntity ));

    ++visitorCounter;
    HistoryData* NewData = new HistoryData(NewName, visitorCounter);
    history.push_back(NewData);
    return true;
}





bool AccessRecord::Leave(const string& Name)
{
    auto find = currentVisitor.find(Name);
    if (find == currentVisitor.end())
    {
        cout << "Warning : 없는 사람입니다." << endl;
        return false;
    }

    currentVisitor.erase(find);
    cout << "Log : " << Name << " 이 떠났습니다.\n";
    return true;
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

