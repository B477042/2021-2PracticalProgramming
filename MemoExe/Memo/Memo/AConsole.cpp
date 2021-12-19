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
				cout << "종료합니다.\n" << endl;

				break;
			default:
				cout << "\n다시 입력해주세요.";
				break;

			}
		}
	}

}

void AConsole::newMemo()
{
	cout << "\n===========================\n새 메모 작성\n";
	cout << "메모는 자동저장 됩니다.\n";
	cout << "단축키 Ctrl + Z : 이전으로, Ctrl + Y : 다음으로, ESC : 타이틀로";


}

void AConsole::loadMemo()
{
	cout << "\n===========================\n불러오기\n";
	cout << "저장된 파일 목록" << endl;


}
