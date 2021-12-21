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
	cout << "�ӽ� �޸�� �ڵ����� �˴ϴ�.\n";
	cout << "����Ű Ctrl + Z : ��������, Ctrl + Y : ��������, ESC : Ÿ��Ʋ��, Ctrl + S : �ٸ� �̸����� ����";
	string FileName = "temp.txt";
	cout << "\n���� �����̸� " << FileName << endl;
	CurrentWrittingFile.open(FileName.c_str(), ios_base::out);

	writting(FileName);
}

void AConsole::writting(const string& FileName)
{

	// �ؽ�Ʈ �Է� ����
	char input=0;
	//������ ���ͳ� �� ���ڰ� ���� ���ڸ� �Է��ߴµ� ������� �ι� ȣ���ؾ� �ż�
	//char prev;
	//�����غ��ϱ� queue�� �����ϴ°� ���ڵ�
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
		//�Է� Ȯ�� ��
		//cout << "ENter"<<endl;
		

		////���� Ŀ�� 
		//CONSOLE_SCREEN_BUFFER_INFO presentCur;
		//GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
		//
		////Ŀ���� �� �� ����
		////presentCur.dwCursorPosition.X -= 2;
		//presentCur.dwCursorPosition.Y -= 1;
		//
		//COORD newCoord;
		//newCoord.X = presentCur.dwCursorPosition.X;
		//newCoord.Y = presentCur.dwCursorPosition.Y;

		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newCoord);
		//
		//

		//���Ͽ� �Է�
		CurrentWrittingFile.seekp(-2, ios_base::cur);
		CurrentWrittingFile << "  ";
		CurrentWrittingFile.seekp(-2, ios_base::cur);

		// ���� �����
		system("cls");

		cout << "\n===========================\n�� �޸� �ۼ�\n";
		cout << "�ӽ� �޸�� �ڵ����� �˴ϴ�.\n";
		cout << "����Ű Ctrl + Z : ��������, Ctrl + Y : ��������, ESC : Ÿ��Ʋ��, Ctrl + S : �ٸ� �̸����� ����";
		cout << "\n���� �����̸� " << FileName << endl;

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
	cout << "\n ���� ������ �̸� : ";
	string input;
	getline(cin, input, '\n');
	string NewFile = input + ".txt";
	//�ۼ� ���� ����
	CurrentWrittingFile.close();
	//�ۼ� ���� �ҷ�����
	CurrentReadFile.open(Origin, ios_base::in);
	//������ ���� �ۼ�
	CurrentWrittingFile.open(NewFile, ios_base::out);

	cout << "���� ����\n";
	char out;
	//���� �ű��
	while (CurrentReadFile.get(out))
	{
		CurrentWrittingFile << out;
	}

	cout << "���� �Ϸ� " << endl;
	CurrentReadFile.close();


}

void AConsole::loadMemo()
{
	cout << "\n===========================\n�ҷ�����\n";
	/*cout << "����� ���� ���" << endl;
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
		cout << "\n���� �̸� �Է� ==> ";
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
