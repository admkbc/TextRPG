#include "stdafx.h"
#include "Npc.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void Npc::gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Npc::begin()
{
	cout << "  Rozmowca: " << Name << endl;
	for (int i = 0; i < 50; ++i)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188) << endl;
}

void Npc::prints(std::string text)
{
	for (int i = 0; i < text.length(); ++i)
	{
		cout << text[i];
		Sleep(80);
	}
	cout << endl;
}

void Npc::menu()
{
	int pos = 0;
	auto it = sentences.begin() + position;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	cout << (*it)->answers[0] << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	for (int i = 1; i < (*it)->answers.size(); ++i)
	{
		cout << (*it)->answers[i] << endl;
	}
	char ch = '\0';
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
					gotoxy(0, pos + 3);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << (*it)->answers[pos] << endl;
					--pos;
					gotoxy(0, pos + 3);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					cout << (*it)->answers[pos] << endl;
				}
				break;

			case 80: //down
				if (pos < (*it)->answers.size() - 1)
				{
					gotoxy(0, pos + 3);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << (*it)->answers[pos] << endl;
					++pos;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					cout << (*it)->answers[pos] << endl;
				}
				break;
			}
		}
	}
	position = (*it)->nextq[pos];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

Npc::Npc(std::string name, int hp, int atack, int defense, std::string npcfile)
	:
	Enemy(name, hp, atack, defense),
	position(0)
{
	std::ifstream f;
	std::string path = npcfile + ".npc";
	f.open(path);
	std::string line;
	int pos;
	while(std::getline(f, line))
	{
		int dot = line.find('.');
		line.erase(line.begin(), line.begin() + dot + 1);
		Sentence *s = new Sentence;
		s->question = line;
		
		while (std::getline(f, line))
		{
			if (line[0] == '-')
			{
				line.erase(0, 1);
				int colon = line.find(':');
				s->nextq.push_back(atoi(line.substr(colon + 1, line.length()).c_str()));
				line.erase(line.begin() + colon, line.end());
				s->answers.push_back(line);
				pos = f.tellg();
			}
			else
			{
				f.seekg(pos, std::ios_base::beg);
				break;
			}
		}
		sentences.push_back(s);
	}
	f.close();
}


Npc::~Npc()
{
	for (auto it = sentences.begin(); it != sentences.end(); ++it)
	{
		delete *it;
	}
}

void Npc::Talk(Player &p)
{
	bool end = false;
	begin();
	auto it = sentences.begin();
	while(!end)
	{
		it = sentences.begin() + position;
		gotoxy(0, 2);
		for (int i = 0; i < 20 * 80; ++i)
			cout << " ";
		gotoxy(0, 2);
		prints((*it)->question);
		menu();
		if (position < 0)
			end = true;
	}
}
