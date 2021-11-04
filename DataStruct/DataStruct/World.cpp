#include "World.h"
#include "AccessRecord.h"
#include <Windows.h>
#include<conio.h>
World::World()
{
    store = nullptr;
    input = NULL;
}

void World::Start()
{
    if(store)
    {
        cout<<"Error : "<<store->GetName()<<" �̹� �����ϴ� ����\n";
        return;
    }

    string StoreName;
    cout<<"## ���� �̸� : ";
    getline(cin, StoreName,'\n');
    store=new Store(StoreName);

    run();

}

void World::End()
{
    AccessRecord::Instance()->Exit();
    delete store;
    delete AccessRecord::Instance();
}

void World::run()
{
    bool bPower=true;
    cout << "\n==============================\n";
    cout << "    " << store->GetName() << " ���󿵾� �մϴ�. \n";
    cout << "==============================\n";
    cout << "1. ��ü �湮�� ��� Ȯ��\n";
    cout << "2. ���� �湮�� Ȯ��\n";
    cout << "3. ����\n";
    cout << "4. ����\n";
    cout << "5. ����\n";
    cout << "Input : ";

    while(bPower)
    {
        if (!_kbhit())
        {
            Sleep(66);
            continue;
        }
        
        
        input=_getch();
        //�湮�� �̸�
        string visitor;
        switch(input)
        {
            case '1':
                
                cout << "1\n==============================\n";
                AccessRecord::Instance()->PrintLog();

        break;
            case '2':
              
                cout << "2\n==============================\n";
                AccessRecord::Instance()->PrintCurrentState();
        break;
           case '3':
               cout << "3\n";
               cout << "�湮�� �̸� : ";
               getline(cin, visitor, '\n');
              
               addNewClinet(visitor);

            break;

        case '4':
            cout << "4\n";
            cout << "�湮�� �̸� : ";
            getline(cin, visitor, '\n');
          
            leaveClinet(visitor);

           break;

        case '5':
        bPower=false;
        continue;
        break;

           default:
             cout<<"�ٽ� �Է����ּ��� \n";

        }


        cout << "\n==============================\n";
        cout << "    " << store->GetName() << " ���󿵾� �մϴ�. \n";
        cout << "==============================\n";
        cout << "1. ��ü �湮�� ��� Ȯ��\n";
        cout << "2. ���� �湮�� Ȯ��\n";
        cout << "3. ����\n";
        cout << "4. ����\n";
        cout << "5. ����\n";
        cout << "Input : ";

    }
    

}

void World::addNewClinet(string& Name)
{
   

    Client* NewClient = new Client(Name);
 
    bool bResult = store->AcceptClinet(NewClient);
    if (!bResult)
    {
        delete NewClient;
    }
}

void World::leaveClinet(string& Name)
{
    bool bResult = store->LeaveClinet(Name);

}
