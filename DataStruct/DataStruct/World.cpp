#include "World.h"
#include "AccessRecord.h"

World::World()
{

}

void World::Start()
{
    if(store)
    {
        cout<<"Error : "<<store->GetName()<<" 이미 존재하는 가게\n";
        return;
    }

    string StoreName;
    cout<<"## 가게 이름 : ";
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
        cout<<"    "<<store->GetName()<<" 정상영업 합니다. \n";
        cout<<"==============================\n";
        cout<<"1. 전체 방문자 기록 확인\n";
        cout<<"2. 현재 방문자 확인\n";
        cout<<"3. 입장\n";
        cout<<"4. 퇴장\n";
        cout<<"5. 종료\n";
        cout<<"Input : ";
        cin>>input;
        //방문자 이름
        string visitor;
        switch(input)
        {
            case '1':
                AccessRecord::Instance()->PrintLog();

        break;
            case '2':
        break;
           case '3':
              
               cout << "방문자 이름 : ";
               getline(cin, visitor, '\n');
               addNewClinet(visitor);

            break;

        case '4':
            cout << "방문자 이름 : ";
            getline(cin, visitor, '\n');

            leaveClinet(visitor);

           break;

        case '5':
        bPower=false;
        continue;
        break;

           default:
             cout<<"다시 입력해주세요 : ";
            cin>>input;

        }
    }
    

}