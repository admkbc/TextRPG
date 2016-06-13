#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <conio.h>
#include "Windows.h"
#include "Funs.h"
#include <fstream>
#include "Item.h"
#include <sstream>
#include "Sword.h"
#include "Staff.h"
#include "ManaPotion.h"
#include "FoodItem.h"
#include "Armor.h"

using namespace std;

void Player::inventoryHead()
{
	system("cls");
	cout << "   Ekwipunek" << endl;
	for (int i = 0; i < 50; ++i)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188) << endl;
}

int Player::printItems()
{
	int pos = 0;
	char ch = '\0';
	for (int i = 0; i < 80 * (items.size() + 1); ++i)
		cout << '\0';
	gotoxy(0, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	if (items.size() > 0)
		cout << items[0]->GetName() << endl;;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	for (int i = 1; i < items.size(); ++i)
		cout << items[i]->GetName() << endl;
	while ((ch = _getch()) != 13)
	{
		if (ch == '1')
			return -1;
		else if (ch == '2')
			return -2;
		else if (ch == 27)
			return -3;
		else if (ch == -32 && _kbhit())
		{
			char ch2 = _getch();
			switch (ch2)
			{
			case 72: //up
				if (pos > 0)
				{
					gotoxy(0, pos + 6);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << items[pos--]->GetName() << endl;
					gotoxy(0, pos + 6);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					cout << items[pos]->GetName() << endl;
				}
				break;

			case 80: //down
				if (pos < items.size() - 1)
				{
					gotoxy(0, pos + 6);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << items[pos++]->GetName() << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					gotoxy(0, pos + 6);
					cout << items[pos]->GetName() << endl;
				}
				break;
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	return pos;
}

void Player::LoadQuests()
{
	Quest *q = new Quest("killdragon");
	quests.push_back(q);
}

Player::Player(std::string name, int hp, int atack, int defense, int happiness, int exp, int money, int maxhp)
	:
	Character(name, hp, atack, defense), Happiness(happiness)
{
	LoadQuests();
	Exp = exp;
	coins = money;
	maxHp = maxhp;
}

Player::~Player()
{
	for (int i = 0; i < items.size(); ++i)
		delete items[i];

	for (int i = 0; i < quests.size(); ++i)
		delete quests[i];
}

void Player::HpInfo()
{
	cout << "Masz " << Hp << " HP" << endl;
}

void Player::AddHp(int value)
{
	Hp = min(Hp + value, maxHp);
}

void Player::AddItem(Item* i)
{
	items.push_back(i);
}

int Player::GetHappiness()
{
	return Happiness;
}

void Player::AddExp(int value)
{
	Exp += value;
}

void Player::ShowInventory()
{
	int id = 0;
	inventoryHead();
	while (id != -3)
	{
		gotoxy(0, 3);
		ShowEq();
		gotoxy(0, 6);
		id = printItems();
		if (id >= 0)
		{
			if (items[id]->Use(this))
			{
				delete items[id];
				items.erase(items.begin() + id);
			}
		}
		else if (id > -3)
			this->RemoveFromEq(id);
	}
}

void Player::MainStats()
{
	system("cls");
	cout << "   Statystyki" << endl;
	for (int i = 0; i < 50; ++i)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188) << endl << endl;

	cout << "HP:\t\t" << Hp << "/" << maxHp << "\t\t\tExp:\t\t" << Exp << endl;
	cout << "Atak:\t\t" << Attack << "\t\t\tObrona:\t\t" << Defense << endl;
	cout << "Szczescie:\t" << Happiness << "\t\t\tMonety:\t\t" << coins << endl;
}

void Player::GiveMoney(int value)
{
	coins += value;
}

int Player::GetMoney()
{
	return coins;
}

void Player::AddHappiness(int value)
{
	Happiness += value;
}

void Player::ShowQuests()
{
	system("cls");
	cout << "   Zadanie" << endl;
	for (int i = 0; i < 50; ++i)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188) << endl << endl;
	for (int i = 0; i < quests.size(); ++i)
		if (quests[i]->IsTaken())
			cout << quests[i]->GetName() << endl;
	_getch();
}

void Player::SaveMainStats(std::ofstream &f)
{
	f << Name << endl;
	f << Hp << endl;
	f << Attack << endl;
	f << Defense << endl;
	f << Happiness << endl;
	f << Exp << endl;
	f << coins << endl;
	f << maxHp << endl;
}

void Player::SaveItemsAndQuests(std::ofstream& f)
{
	f << "I" << endl;
	for (int i = 0; i < items.size(); ++i)
		items[i]->Save(f);
	f << "Q" << endl;
	for (int i = 0; i < quests.size(); ++i)
		quests[i]->Save(f);
}

void Player::LoadItemsAndQuests(std::ifstream& f)
{
	string line, name, tmp;
	getline(f, line);
	int itemType;
	if (line[0] == 'I')
	{
		while (getline(f, line) && line[0] != 'Q')
		{
			itemType = static_cast<int>(line[0]) - 48;
			line.erase(line.begin());
			istringstream iss(line);
			iss >> name;
			while (iss >> tmp)
				if (!isdigit(tmp[0]))
					name = name + ' ' + tmp;

			switch (itemType)
			{
			case 0:
				items.push_back(new Armor(name, atoi(tmp.c_str())));
				break;
			case 1:
				items.push_back(new FoodItem(name, atoi(tmp.c_str())));
				break;
			case 2:
				items.push_back(new ManaPotion(name, atoi(tmp.c_str())));
				break;
			case 3:
				items.push_back(new Staff(name, atoi(tmp.c_str())));
				break;
			case 4:
				items.push_back(new Sword(name, atoi(tmp.c_str())));
				break;
			}
		}
	}
	for (int i = 0; getline(f, line); ++i)
	{
		quests[i]->SetCheckpoint(atoi(line.c_str()));
	}
}
