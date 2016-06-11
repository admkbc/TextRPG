#include "stdafx.h"
#include "Location.h"
#include <fstream>
#include <sstream>
#include "Battle.h"
#include <conio.h>
#include <iostream>
#include "MainMenu.h"

using namespace std;

void Location::header()
{
	cout << "   " << name << endl;
	for (int i = 0; i < 50; ++i)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188) << endl;
}

Location::Location(string n, string locfile)
	:
	name(n)
{
	ifstream f;
	string path = "loc/" + locfile + ".loc";
	f.open(path);
	string line;
	int pos;
	while (std::getline(f, line))
	{
		if (line[0] == ':')
		{
			line.erase(line.begin());
			istringstream iss(line);
			string probability;
			iss >> probability;
			EnemyProbability *en = new EnemyProbability;
			en->probability = atoi(probability.c_str());
			while (std::getline(f, line))
			{
				if (line[0] == '*')
				{
					string name, hp, attack, defend;
					line.erase(line.begin());
					istringstream e(line);
					e >> name;
					e >> hp;
					e >> attack;
					e >> defend;
					en->enemies.push_back(new Enemy(name, atoi(hp.c_str()), atoi(attack.c_str()), atoi(defend.c_str())));
					pos = f.tellg();
				}
				else
				{
					f.seekg(pos, ios_base::beg);
					break;
				}
			}
			enemies.push_back(en);
		}
		else if (line[0] == '+')
		{
			line.erase(line.begin());
			istringstream iss(line);
			string name, hp, attack, defend, filename;
			iss >> name;
			iss >> hp;
			iss >> attack;
			iss >> defend;
			iss >> filename;
			Npc *n = new Npc(name, atoi(hp.c_str()), atoi(attack.c_str()), atoi(defend.c_str()), filename);
			npcs.push_back(n);
		}
		else if (line[0] == '-')
		{
			line.erase(line.begin());
			istringstream iss(line);
			string id;
			iss >> id;
			locations.push_back(atoi(id.c_str()));
		}
	}
}


Location::~Location()
{
	for (int i = 0; i < npcs.size(); ++i)
		delete npcs[i];

	for (int i = 0; i < enemies.size(); ++i)
	{
		for (int k = 0; k < (enemies[i]->enemies).size(); ++k)
		{
			delete enemies[i]->enemies[k];
		}
		delete enemies[i];
	}
}

void Location::GoTo(Player* p)
{
	int random;
	Battle *b;
	for (int i = 0; i < enemies.size(); ++i)
	{
		random = rand() % 100;
		if (random < enemies[i]->probability)
		{
			b = new Battle(p, true);
			for (int k = 0; k < enemies[i]->enemies.size(); ++k)
			{
				b->AddToSecondTeam(enemies[i]->enemies[k], NULL);
			}
			b->Start();
		}
	}
}

int Location::Menu(Player *p, Map *m)
{
	MainMenu *menu;
	int pos = 0;
	vector<string> options;
	for (int i = 0; i < npcs.size(); ++i)
		options.push_back("Rozmawiaj z " + npcs[i]->GetName());
	for (int i = 0; i < locations.size(); ++i)
		options.push_back("Idz do " + m->GetNameOfLocation(locations[i]));
	while (1)
	{
		system("cls");
		header();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		gotoxy(12, 7);
		cout << options[0] << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		for (int i = 1; i < options.size(); ++i)
		{
			gotoxy(12, 7 + i);
			cout << options[i];
		}
		char ch = '\0';
		while ((ch = _getch()) == (-32))
		{
			if (_kbhit())
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
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		switch (ch)
		{
		case 'i':
		case 'I':
			p->ShowInventory();
			break;
		case 's':
		case 'S':
			p->ShowStats();
			break;
		case 27:
			menu = new MainMenu("Paused", 10, 10);
			if (menu->Show(true) == -1)
			{
				delete menu;
				return -1;
			}
			delete menu;
			break;
		}
		if (ch == 13) //enter
		{
			if (pos < npcs.size()) //npcs
			{
				npcs[pos]->Talk(p);
			}
			else //travel to location
			{
				return locations[pos - npcs.size()];
			}
		}
	}
}
