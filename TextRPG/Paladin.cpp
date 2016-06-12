#include "stdafx.h"
#include "Paladin.h"
#include <iostream>
#include <conio.h>

using namespace std;

Paladin::Paladin(std::string name, int hp, int atack, int defense, int happiness)
	:
	Mage(name, hp, atack, defense, happiness),
	Warrior(name, hp, atack, defense, happiness),
	Player(name, hp, atack, defense, happiness)
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
	return GetDefendBonus();
}

void Paladin::WearItem(Item* it)
{
	WearItem(it);
}

void Paladin::ShowStats()
{
	char ch;
	do
	{
		MainStats();
		cout << endl << "Poziom magii:\t" << magicSkill << endl;
		cout << "Mana:\t\t" << mana << "/" << maxMana << endl;
		cout << endl << "Opanowanie miecza:\t" << swordSkill << endl;
		ch = _getch();
		if (Exp >= 50)
		{
			switch (ch)
			{
			case 'a':
			case 'A':
				Exp -= 50;
				++Atack;
				break;
			case 'd':
			case 'D':
				Exp -= 50;
				++Defense;
				break;
			case '1':
				Exp -= 50;
				++magicSkill;
				break;
			case '2':
				Exp -= 50;
				++maxMana;
				break;
			case '3':
				Exp -= 50;
				++swordSkill;
				break;
			}
		}
	} while (ch != 27);
}

void Paladin::ShowEq()
{
	Warrior::ShowEq();
}

void Paladin::RemoveFromEq(int id)
{
	Warrior::RemoveFromEq(id);
}
