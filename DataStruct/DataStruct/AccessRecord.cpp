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
        cout << "�湮 ����� �����ϴ�.\n";
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
        cout << "Warning : ���ο� �湮�ڰ� �����ϴ�.\n";
        return;

    }
    auto find = currentVisitor.find(NewName);
    if (find != currentVisitor.end())
    {
        cout << "Warning : ���� �湮 ���� ����Դϴ�." << endl;

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
        cout << "Warning : ���� ����Դϴ�." << endl;
        return;
    }

    currentVisitor.erase(find);
    cout << "Log : " << Name << " �� �������ϴ�.\n";

}

void AccessRecord::Exit()
{
   
    currentVisitor.clear();
    for (auto it : history)
    {
        delete it;
    }
   
    

    cout << "�� �ݽ��ϴ�.\n";
}

