#include "stdafx.h"
#include "Mage.h"
#include <iostream>
#include <conio.h>

using namespace std;

Mage::Mage(std::string name, int hp, int atack, int defense, int happiness)
	:
	Player(name, hp, atack, defense, happiness)
{
	maxMana = 5;
	mana = 5;
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
	MainStats();
	cout << endl << "Poziom magii:\t" << magicSkill << endl;
	cout << "Mana:\t\t" << mana << "/" << maxMana << endl;
	_getch();
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
