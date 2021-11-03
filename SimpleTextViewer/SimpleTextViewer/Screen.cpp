#include "Screen.h"
#include <conio.h>
Screen* Screen::Instance = nullptr;

Screen::Screen()
{
	wordsOnLine = 30;
}

const Screen* Screen::GetInstance()
{
	if (!Instance)
	{
		Instance = new Screen();
	}
	

	return Instance;
    
}

void Screen::DeleteInstance()
{
	delete Instance;
}

void Screen::Print(const string& ToPrint)
{
	const string Enter = "\n";
	string EditableText = ToPrint;
	int insertPos = 0;
	//�� �ԷµǴ� ���� ��
	const int totalLine = ToPrint.length() / wordsOnLine;
	//���͸� Editable Text�� �����ϴ� ����
	for (int i = 0; i < totalLine; ++i)
	{
		insertPos += wordsOnLine * (i + 1);
		EditableText.insert(insertPos, Enter);
		insertPos + 1;
	}
	cout << EditableText << "\n";
	cout<<"====================================================\n\
		\t<- Prev \t Next-> \t h : back to home\n";
	



}

void Screen::SetWordsOnLine(const int& NewValue)
{
	wordsOnLine = NewValue;
}

void Screen::initScreen()
{
	OptionTxt.open("");
}

void Screen::clearScreen()
{
	system("cls");
}
