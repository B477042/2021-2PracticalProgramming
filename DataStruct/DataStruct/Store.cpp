#include "Store.h"
#include "AccessRecord.h"


bool Store::AcceptClinet(Client* NewClient)
{
	if (!NewClient)
	{
		cout << "Error : �߸��� �湮��\n";
			return false;
	}
	 string name = NewClient->GetName();
	return AccessRecord::Instance()->Join(name, NewClient);
	 
}

bool  Store::LeaveClinet(const string& Name)
{
	return AccessRecord::Instance()->Leave(Name);
	
}
