#include "stdafx.h"
#include "Warrior.h"
#include <iostream>
#include <conio.h>
#include "Funs.h"

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
	MainStats();
	_getch();
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
	switch(id)
	{
	case -1:
		weapon = NULL;
		break;
	case -2:
		armor = NULL;
		break;
	}
}
