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
        cout << "�湮 ����� �����ϴ�.\n";
        return;
    }
    
    for (auto it : history)
    {
        it->Log();
    }


}

void AccessRecord::PrintCurrentState()
{
    cout<<"���� ���Կ� �ִ� ������Դϴ�.\n";
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
        cout << "Warning : ���ο� �湮�ڰ� �����ϴ�.\n";
        return false;

    }
    auto find = currentVisitor.find(NewName);
    if (find != currentVisitor.end())
    {
        cout << "Warning : ���� �湮 ���� ����Դϴ�." << endl;
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
        cout << "Warning : ���� ����Դϴ�." << endl;
        return false;
    }

    currentVisitor.erase(find);
    cout << "Log : " << Name << " �� �������ϴ�.\n";
    return true;
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

