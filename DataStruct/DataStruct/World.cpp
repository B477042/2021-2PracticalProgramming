#include "World.h"


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
    cin>>StoreName;
    store=new Store(StoreName);

    run();

}

void World::End()
{
    delete store;
}

void World::run()
{
    bool bPower=true;
    while(bPower)
    {
        cout<<"==============================\n"
        cout<<"|    "<<store->GetName()<<" ���󿵾� �մϴ�. |\n";
        cout<<"==============================\n";
        cout<<"1. ��ü �湮�� ��� Ȯ��\n";
        cout<<"2. ���� �湮�� Ȯ��\n";
        cout<<"3. ����\n";
        cout<<"4. ����\n";
        cout<<"5. ����\n";
        cout<<"Input : ";
        cin>>input;

        switch(input)
        {
            case '1':
        break;
              case '2':
        break;
           case '3':
            break;
        case '4':
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