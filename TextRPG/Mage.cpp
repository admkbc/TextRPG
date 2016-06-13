#include "stdafx.h"
#include "Mage.h"
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <fstream>

using namespace std;

Mage::Mage(std::string name, int hp, int atack, int defense, int happiness)
	:
	Player(name, hp, atack, defense, happiness)
{
	maxMana = 10;
	mana = 10;
}


Mage::~Mage()
{
}

int Mage::GetAttackBonus()
{
	if (mana > 0 && weapon != NULL)
	{
		--mana;
		return weapon->magicBonus;
	}
	else
	{
		return 0;
	}
}

int Mage::GetDefendBonus()
{
	return 0;
}

int Mage::GetSkill()
{
	if (mana > 0)
		return magicSkill;
	else
		return 0;
}

void Mage::WearItem(Item *it)
{
	weapon = dynamic_cast<Staff*>(it);
}

void Mage::ShowStats()
{
	char ch;
	do
	{
		MainStats();
		cout << endl << "Poziom magii:\t" << magicSkill << endl;
		cout << "Mana:\t\t" << mana << "/" << maxMana << endl;
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
				++magicSkill;
				break;
			case '2':
				Exp -= 50;
				++maxMana;
				break;
			}
		}
	} while (ch != 27);
}

void Mage::ShowEq()
{
	for (int i = 0; i < 80; ++i) //clear line
		cout << '\0';
	for (int i = 0; i < 80; ++i) //return to begin
		cout << '\b';
	cout << "Bron: ";
	if (weapon != NULL)
		cout << weapon->GetName();
	else
		cout << "brak";
	cout << endl << endl;
}

void Mage::RemoveFromEq(int id)
{
	if (id == -1)
		weapon == NULL;
}

void Mage::AddMana(int value)
{
	mana = min(mana + value, maxMana);
}

void Mage::Save(std::ofstream& f)
{
	f << 1 << endl;
	SaveMainStats(f);
	f << mana << endl;
	f << maxMana << endl;
	f << magicSkill << endl;
}
