#include "stdafx.h"
#include "Npc.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <sstream>
#include "GiveItemAction.h"
#include "BattleAction.h"
#include "SetReturnAction.h"

using namespace std;

void Npc::begin()
{
	system("cls");
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

void Npc::AddAction(string &line, Sentence *s)
{
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
			string arg1String, arg2String, arg3String;
			int arg1, arg2, arg3;
			iss >> arg1String;
			iss >> arg2String;
			iss >> arg3String;
			arg1 = atoi(arg1String.c_str());
			arg2 = atoi(arg2String.c_str());
			arg3 = atoi(arg3String.c_str());
			GiveItemAction *action = new GiveItemAction(arg1, arg2, arg3);
			s->SetAction(action);
		}
		else if (actionName == "battle")
		{
			BattleAction *action = new BattleAction(this);
			s->SetAction(action);
		}
		else if (actionName == "setreturn")
		{
			string arg1String;
			int arg1;
			iss >> arg1String;
			arg1 = atoi(arg1String.c_str());
			SetReturnAction *action = new SetReturnAction(arg1);
			s->SetAction(action);
		}
	}
	else
	{
		s->SetAction(NULL);
	}	
}

void Npc::AddQuestion(string &line, Sentence *s)
{
	int dot = line.find('.');
	line.erase(line.begin(), line.begin() + dot + 1);
	s->SetQuestion(line);
}

void Npc::AddAnswer(string &line, Sentence *s)
{
	line.erase(0, 1);
	int colon = line.find(':');
	s->AddNextQuestionId(atoi(line.substr(colon + 1, line.length()).c_str()));
	line.erase(line.begin() + colon, line.end());
	s->AddAnswer(line);
}

Npc::Npc(string name, int hp, int atack, int defense, string npcfile)
	:
	Enemy(name, hp, atack, defense),
	position(0)
{
	ifstream f;
	string path = "npc/" + npcfile + ".npc";
	f.open(path);
	string line;
	int pos;
	while(getline(f, line))
	{
		Sentence *s = new Sentence;
		
		AddAction(line, s);
		AddQuestion(line, s);
		while (std::getline(f, line))
		{
			if (line[0] == '-')
			{
				AddAnswer(line, s);
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

int Npc::Talk(Player *p)
{
	position = 0;
	bool end = false;
	int value = 0;
	int ret = 0;
	begin();
	while(!end)
	{
		sentencesIt = sentences.begin() + position;
		gotoxy(10, 5);
		for (int i = 0; i < 12 * 80; ++i)
			cout << " ";
		prints((*sentencesIt)->GetQuestion());
		value = (*sentencesIt)->DoAction(p);
		if (value != 0)
			ret = value;
		menu();
		if (position < 0)
			end = true;
	}
	return ret;
}

std::string Npc::GetName()
{
	return Name;
}
