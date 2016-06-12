#include "stdafx.h"
#include "Paladin.h"
#include <iostream>
#include <conio.h>

using namespace std;

Paladin::Paladin(std::string name, int hp, int atack, int defense, int happiness)
	:
	Mage(name, hp, atack, defense, happiness),
	Warrior(name, hp, atack, defense, happiness)
{
	maxMana = 10;
	mana = 10;
}


Paladin::~Paladin()
{
}

int Paladin::GetSkill()
{
	if (mana > 0)
		return swordSkill + magicSkill;
	return 0;
}

int Paladin::GetAttackBonus()
{
	if (mana > 1 && Warrior::weapon != NULL)
	{
		mana = mana - 2;
		return Warrior::weapon->attackBonus;
	}
	else
	{
		return 0;
	}
}

int Paladin::GetDefendBonus()
{
	return Warrior::GetDefendBonus();
}

void Paladin::WearItem(Item* it)
{
	Warrior::WearItem(it);
}

void Paladin::ShowStats()
{
	Warrior::MainStats();
	cout << endl << "Poziom magii:\t" << magicSkill << endl;
	cout << "Mana:\t\t" << mana << "/" << maxMana << endl;
	cout << endl << "Opanowanie miecza:\t" << swordSkill << endl;
	_getch();
}

void Paladin::ShowEq()
{
	Warrior::ShowEq();
}

void Paladin::RemoveFromEq(int id)
{
	Warrior::RemoveFromEq(id);
}
