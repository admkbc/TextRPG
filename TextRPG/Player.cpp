#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <conio.h>
#include "Windows.h"
#include "Funs.h"

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

Player::Player(std::string name, int hp, int atack, int defense, int happiness)
	:
	Character(name, hp, atack, defense), Happiness(happiness)
{
	Exp = 0;
	maxHp = 100;
	coins = 200;
}

Player::~Player()
{

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
	cout << "Atak:\t\t" << Atack << "\t\t\tObrona:\t\t" << Defense << endl;
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
