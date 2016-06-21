#include "stdafx.h"
#include "MainMenu.h"
#include "Windows.h"
#include <iostream>
#include <conio.h>
#include "Funs.h"
#include "Game.h"

using namespace std;

int MainMenu::keyboard()
{
	char ch = '\0';
	int pos = 0;
	while ((ch = _getch()) != 13)
	{
		if (ch == -32 && _kbhit())
		{
			char ch2 = _getch();
			switch (ch2)
			{
			case 72: //up
				if (pos > 0)
				{
					gotoxy(12, pos + 7);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << options[pos--];
					gotoxy(12, pos + 7);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					cout << options[pos];
				}
				break;

			case 80: //down
				if (pos < options.size() - 1)
				{
					gotoxy(12, pos + 7);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << options[pos++];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					gotoxy(12, pos + 7);
					cout << options[pos];
				}
				break;
			}
		}
		else if (ch == 27)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			return 3;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	return pos;
}

MainMenu::MainMenu(string title, int x, int y)
	:
	Title(title),
	X(x),
	Y(y)
{
	options.push_back("Nowa gra");
	options.push_back("Wczytaj gre");
	options.push_back("Wyjscie");
	//Hide cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}


MainMenu::~MainMenu()
{

}

int MainMenu::Show(bool save)
{
	bool saveMenu = true;
	int result = -1;
	while (true)
	{
		system("cls");
		if (save && saveMenu)
		{
			options.insert(options.begin() + 2, "Zapisz gre");
			saveMenu = false;
		}
		cout << "   " << Title << endl;
		for (int i = 0; i < 50; ++i)
			cout << static_cast<char>(205);
		cout << static_cast<char>(188) << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		gotoxy(12, 7);
		cout << options[0] << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		for (int i = 1; i < options.size(); ++i)
		{
			gotoxy(12, 7 + i);
			cout << options[i];
		}
		result = keyboard();
		switch (result)
		{
		case 0:
			g.NewGame();
			break;
		case 1:
			g.LoadGame();
			break;
		case 2:
			if (save)
				g.SaveGame();
			else
				return -1;
			break;
		case 3:
			return -1;
			break;
		}
	}
	saveMenu = true;
	return result;
}

Game MainMenu::g;
