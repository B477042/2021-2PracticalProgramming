#include "AConsole.h"
#include "AProgram.h"

AConsole::~AConsole()
{
}

//unsigned int __stdcall AConsole::procThread(LPVOID InputParam)
//{
//
//
//	Console->mainLogic();
//	
//	IpParam->Program.TurnOffPower();
//
//
//	return 0;
//}

void AConsole::StartConsole()
{
	hello();

}

void AConsole::hello()
{
	cout << "\n===========================\n\tMemo\n===========================\n";
	cout << "1. New Memo 2. Load Memo 3. Exit\nInput ======> ";
	char input;
	bool bLoop = true;
	while (bLoop)
	{
		if (_kbhit())
		{
			input = _getch();
			switch (input)
			{
			case '1':
				bLoop = false;
				newMemo();

				break;
			case '2':
				bLoop = false;
				loadMemo();
				break;
			case '3':
				bLoop = false;
				cout << "�����մϴ�.\n" << endl;

				break;
			default:
				cout << "\n�ٽ� �Է����ּ���.";
				break;

			}
		}
	}

}

void AConsole::newMemo()
{
	cout << "\n===========================\n�� �޸� �ۼ�\n";
	cout << "�޸�� �ڵ����� �˴ϴ�.\n";
	cout << "����Ű Ctrl + Z : ��������, Ctrl + Y : ��������, ESC : Ÿ��Ʋ��";


}

void AConsole::loadMemo()
{
	cout << "\n===========================\n�ҷ�����\n";
	cout << "����� ���� ���" << endl;


}
