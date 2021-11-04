#include "Store.h"
#include "AccessRecord.h"


void Store::AcceptClinet(Client* NewClient)
{
	if (!NewClient)
	{
		cout << "Error : �߸��� �湮��\n";
			return;
	}
	 string name = NewClient->GetName();
	 AccessRecord::Instance()->Join(name, NewClient);

}

void Store::LeaveClinet(const string& Name)
{
	AccessRecord::Instance()->Leave(Name);
}
