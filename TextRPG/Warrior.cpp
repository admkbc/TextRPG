#include "stdafx.h"
#include "Warrior.h"
#include <iostream>
#include <conio.h>
#include "Funs.h"
#include <fstream>

using namespace std;

Warrior::Warrior(std::string name, int hp, int atack, int defense, int happiness)
	:
	Player(name, hp, atack, defense, happiness)
{
	swordSkill = 10;
}


Warrior::~Warrior()
{
}

int Warrior::GetSkill()
{
	return swordSkill;
}

int Warrior::GetAttackBonus()
{
	if (weapon != NULL)
		return weapon->attackBonus;
	else
		return 0;
}

int Warrior::GetDefendBonus()
{
	if (armor != NULL)
		return armor->defendBonus;
	else
		return 0;
}

void Warrior::WearItem(Item *it)
{
	Sword *tmp;
	tmp = dynamic_cast<Sword*>(it);
	if (tmp != NULL)
		weapon = tmp;
	else
		armor = dynamic_cast<Armor*>(it);
}

void Warrior::ShowStats()
{
	char ch;
	do
	{
		MainStats();
		cout << endl << "Opanowanie miecza:\t" << swordSkill << endl;
		ch = _getch();
		if (Exp >= 50)
		{
			switch (ch)
			{
			case 'a':
			case 'A':
				Exp -= 50;
				++Attack;
				break;
			case 'd':
			case 'D':
				Exp -= 50;
				++Defense;
				break;
			case '1':
				Exp -= 50;
				++swordSkill;
				break;
			}
		}
	} while (ch != 27);
}

void Warrior::ShowEq()
{
	for (int i = 0; i < 160; ++i)
		cout << '\0'; //clear 2 lines
	gotoxy(0, 3);
	cout << "Bron: ";
	if (weapon != NULL)
		cout << weapon->GetName();
	else
		cout << "brak";
	cout << endl;
	cout << "Pancerz: ";
	if (armor != NULL)
		cout << armor->GetName();
	else
		cout << "brak";
	cout << endl << endl;
}

void Warrior::RemoveFromEq(int id)
{
	switch (id)
	{
	case -1:
		weapon = NULL;
		break;
	case -2:
		armor = NULL;
		break;
	}
}

void Warrior::Save(std::ofstream& f)
{
	f << 0 << endl;
	SaveMainStats(f);
	f << swordSkill << endl;
}
