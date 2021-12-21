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
	SaveData.open("File data.txt", ios_base::in | ios_base::app);


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
	string FileName = "temp.txt";
	cout << "\n현재 파일이름 " << FileName << endl;
	CurrentWrittingFile.open(FileName.c_str(), ios_base::out);

	writting(FileName);
}

void AConsole::writting(const string& FileName)
{

	// 텍스트 입력 로직
	char input=0;
	//이전에 엔터나 두 글자가 들어가는 문자를 입력했는데 지울려면 두번 호출해야 돼서
	//char prev;
	//생각해보니까 queue로 저장하는게 낫겠따
	stack<char>prev;


	bool bLoop = true;
	if (!CurrentWrittingFile.is_open())
	{
		cout << "File error" << endl;
		hello();
		return;
	}

	while (bLoop)
	{
		if (_kbhit())
		{
			prev.push( input);
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
				CurrentWrittingFile << "\n";
				break;
			case 19://Ctrl + S
				saveFile(FileName);

				break;
			case 25://Ctrl + Y
				



				break;
			case 26://Ctrl + Z


				
			
				
				break;
			case 8://Backspace
				deleteChar(prev.top(),FileName);
				prev.pop();

				break;
			case 27://Esc
				bLoop = false;
				hello();
				break;
			case -32://arrow
				arrowAction(_getch());
				break;
			default:
				//Key Test
			//	cout <<(int)input<<endl;
				cout << input;
				CurrentWrittingFile << input;
				
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

void AConsole::deleteChar(const char& Prev,const string& FileName)
{
	char input;
	if ((int)Prev == 13)
	{
		//입력 확인 용
		//cout << "ENter"<<endl;
		

		////현재 커서 
		//CONSOLE_SCREEN_BUFFER_INFO presentCur;
		//GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
		//
		////커서를 한 줄 위로
		////presentCur.dwCursorPosition.X -= 2;
		//presentCur.dwCursorPosition.Y -= 1;
		//
		//COORD newCoord;
		//newCoord.X = presentCur.dwCursorPosition.X;
		//newCoord.Y = presentCur.dwCursorPosition.Y;

		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newCoord);
		//
		//

		//파일에 입력
		CurrentWrittingFile.seekp(-2, ios_base::cur);
		CurrentWrittingFile << "  ";
		CurrentWrittingFile.seekp(-2, ios_base::cur);

		// 파일 재출력
		system("cls");

		cout << "\n===========================\n새 메모 작성\n";
		cout << "임시 메모는 자동저장 됩니다.\n";
		cout << "단축키 Ctrl + Z : 이전으로, Ctrl + Y : 다음으로, ESC : 타이틀로, Ctrl + S : 다른 이름으로 저장";
		cout << "\n현재 파일이름 " << FileName << endl;

		CurrentWrittingFile.close();
		CurrentReadFile.open(FileName, ios_base::in);

		while (CurrentReadFile.get(input))
		{
			cout << input;
		}
		CurrentReadFile.close();
		CurrentWrittingFile.open(FileName.c_str(), ios_base::app);
		cout << "clrea once" << endl;
		
	}
	else
	{
		cout << "\b \b";
		CurrentWrittingFile.seekp(-1,ios_base::cur);
		CurrentWrittingFile << " ";
		CurrentWrittingFile.seekp(-1, ios_base::cur);

	}

}

void AConsole::saveFile(const string& Origin)
{
	cout << "\n 새로 저장할 이름 : ";
	string input;
	getline(cin, input, '\n');
	string NewFile = input + ".txt";
	//작성 파일 저장
	CurrentWrittingFile.close();
	//작성 파일 불러오기
	CurrentReadFile.open(Origin, ios_base::in);
	//저장할 파일 작성
	CurrentWrittingFile.open(NewFile, ios_base::out);

	cout << "저장 시작\n";
	char out;
	//내용 옮기기
	while (CurrentReadFile.get(out))
	{
		CurrentWrittingFile << out;
	}

	cout << "저장 완료 " << endl;
	CurrentReadFile.close();


}

void AConsole::loadMemo()
{
	cout << "\n===========================\n불러오기\n";
	/*cout << "저장된 파일 목록" << endl;
	int num = 1;
	char out;
	cout << num << ". ";
	while (SaveData.get(out))
	{
		if (out == '\n')
		{
			++num;
			cout << endl<<num << ". ";
		}
		else
		{
			cout << out;
		}
		
	}*/

	string input;
	
	
	while (!CurrentWrittingFile.is_open())
	{
		input.clear();
		cout << "\n파일 이름 입력 ==> ";
		getline(cin, input, '\n');
		input += ".txt";
		CurrentWrittingFile.open(input, ios_base::app);


	}
	CurrentReadFile.open(input, ios_base::in);
	char out;
	while (CurrentReadFile.get(out))
	{
		cout << out;
	}



	writting(input);


}
