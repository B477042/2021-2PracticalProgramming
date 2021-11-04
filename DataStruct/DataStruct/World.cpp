#include "World.h"
#include "AccessRecord.h"

World::World()
{

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
    while(bPower)
    {
        cout << "==============================\n";
        cout<<"    "<<store->GetName()<<" ���󿵾� �մϴ�. \n";
        cout<<"==============================\n";
        cout<<"1. ��ü �湮�� ��� Ȯ��\n";
        cout<<"2. ���� �湮�� Ȯ��\n";
        cout<<"3. ����\n";
        cout<<"4. ����\n";
        cout<<"5. ����\n";
        cout<<"Input : ";
        cin>>input;
        //�湮�� �̸�
        string visitor;
        switch(input)
        {
            case '1':
                AccessRecord::Instance()->PrintLog();

        break;
            case '2':
        break;
           case '3':
              
               cout << "�湮�� �̸� : ";
               getline(cin, visitor, '\n');
               addNewClinet(visitor);

            break;

        case '4':
            cout << "�湮�� �̸� : ";
            getline(cin, visitor, '\n');

            leaveClinet(visitor);

           break;

        case '5':
        bPower=false;
        continue;
        break;

           default:
             cout<<"�ٽ� �Է����ּ��� : ";
            cin>>input;

        }
    }
    

}