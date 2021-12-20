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
	cout << "임시 메모는 자동저장 됩니다.\n";
	cout << "단축키 Ctrl + Z : 이전으로, Ctrl + Y : 다음으로, ESC : 타이틀로, Ctrl + S : 다른 이름으로 저장";
	string FileName = "temp";
	cout << "현재 파일이름 " << FileName << endl;
	
	writting(FileName);
}

void AConsole::writting(const string& FileName)
{

	// 텍스트 입력 로직
	char input;
	bool bLoop = true;
	
	while (bLoop)
	{
		if (_kbhit())
		{
			input = _getch();
			switch (input)
			{
				/*
				* 13 : enter
				* 26 : ctrl+z
				* 25 : ctrl+y
				* 19 : ctrl+s
				*/
			case 13://Enter
				cout << "\n";
				break;
			case 25://Ctrl + Z
				cout << "되돌리기\n";
				break;
			case 26://Ctrl + y
				cout << "앞으로\n";
				break;
			case 8://Backspace
				cout << "\b \b";
				break;
			case 27://Esc
				bLoop = false;
				break;
			case -32://arrow
				arrowAction(_getch());
				break;
			default:
				cout <<(int)input<<endl;
				break;

			}
		}
	}
}

void AConsole::arrowAction(const int& num)
{
	switch (num)
	{
	case 72://up
		//cout << " up ";
		break;
	case 80://down
		//cout << " down ";
		break;
	case 75://left
		//cout << " left ";
		break;
	case 77://right
		//cout << " right ";
		break;
	}
}

void AConsole::loadMemo()
{
	cout << "\n===========================\n불러오기\n";
	cout << "저장된 파일 목록" << endl;


}
