
#include "AFileReader.h"

AFileReader* AFileReader::Instance = nullptr;

AFileReader::AFileReader()
{
	
}

const AFileReader* AFileReader::GetFileReader()
{
	if (!Instance)
	{
		cout << "Create Instance" << endl;
		Instance = new AFileReader();
		
	}
	else
	{
		cout << "Instance" << endl;
	}

	return Instance;
}

void AFileReader::DeleteInstance()
{
	delete Instance;
}
