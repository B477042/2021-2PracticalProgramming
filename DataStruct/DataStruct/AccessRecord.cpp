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
        cout << "�湮 ����� �����ϴ�.\n";
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
        cout << "Warning : ���ο� �湮�ڰ� �����ϴ�.\n";
        return;

    }
    auto find = CurrentVisitor.find(NewName);
    if (find != CurrentVisitor.end())
    {
        cout << "Warning : ���� �湮 ���� ����Դϴ�." << endl;

    }

    CurrentVisitor.insert( pair<string,Entity*>( NewName,NewEntity ));



}

void AccessRecord::Leave(const string& Name)
{
    auto find = CurrentVisitor.find(Name);
    if (find != CurrentVisitor.end())
    {
        cout << "Warning : ���� ����Դϴ�." << endl;
        return;
    }

    CurrentVisitor.erase(find);
    cout << "Log : " << Name << " �� �������ϴ�.\n";

}

void AccessRecord::Exit()
{
   
    CurrentVisitor.clear();
    for (auto it : History)
    {
        delete it;
    }

    cout << "�� �ݽ��ϴ�.\n";
}

