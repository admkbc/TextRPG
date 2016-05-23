#include "stdafx.h"
#include "Npc.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <sstream>
#include "GiveItemAction.h"
#include "BattleAction.h"

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

void Npc::prints(string text)
{
	gotoxy(10, 5);
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	gotoxy(12, 7);
	cout << (*sentencesIt)->GetAnswer(0) << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	for (int i = 1; i < (*sentencesIt)->AnswersSize(); ++i)
	{ 
		gotoxy(12, 7+i);
		cout << (*sentencesIt)->GetAnswer(i);
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
					gotoxy(12, pos + 7);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << (*sentencesIt)->GetAnswer(pos--);
					gotoxy(12, pos + 7);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					cout << (*sentencesIt)->GetAnswer(pos);
				}
				break;

			case 80: //down
				if (pos < (*sentencesIt)->AnswersSize() - 1)
				{
					gotoxy(12, pos + 7);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << (*sentencesIt)->GetAnswer(pos++);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					gotoxy(12, pos + 7);
					cout << (*sentencesIt)->GetAnswer(pos);
				}
				break;
			}
		}
	}
	position = (*sentencesIt)->GetQuestionId(pos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

Npc::Npc(string name, int hp, int atack, int defense, string npcfile)
	:
	Enemy(name, hp, atack, defense),
	position(0)
{
	ifstream f;
	string path = npcfile + ".npc";
	f.open(path);
	string line;
	int pos;
	while(std::getline(f, line))
	{
		Sentence *s = new Sentence;
		int dot = line.find('.');
		line.erase(line.begin(), line.begin() + dot + 1);
		string command;
		int slash = line.find('/');
		if (slash >= 0)
		{
			command = line.substr(slash + 1, line.length());
			line.erase(line.begin() + slash, line.end());
			istringstream iss(command);
			string actionName; 
			iss >> actionName;

			if (actionName == "giveitem")
			{
				string arg1String, arg2String;
				int arg1, arg2;
				iss >> arg1String;
				iss >> arg2String;
				arg1 = atoi(arg1String.c_str());
				arg2 = atoi(arg2String.c_str());
				GiveItem *action = new GiveItem(arg1, arg2);
				s->SetAction(action);
			}
			else if (actionName == "battle")
			{
				BattleAction *action = new BattleAction(this);
				s->SetAction(action);
			}
		}
		else
		{
			s->SetAction(NULL);
		}
		s->SetQuestion(line);
		
		while (std::getline(f, line))
		{
			if (line[0] == '-')
			{
				line.erase(0, 1);
				int colon = line.find(':');
				s->AddNextQuestionId(atoi(line.substr(colon + 1, line.length()).c_str()));
				line.erase(line.begin() + colon, line.end());
				s->AddAnswer(line);
				pos = f.tellg();
			}
			else
			{
				f.seekg(pos, ios_base::beg);
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
	while(!end)
	{
		sentencesIt = sentences.begin() + position;
		gotoxy(10, 5);
		for (int i = 0; i < 12 * 80; ++i)
			cout << " ";
		prints((*sentencesIt)->GetQuestion());
		(*sentencesIt)->DoAction(p);
		menu();
		if (position < 0)
			end = true;
	}
}
