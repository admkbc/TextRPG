#include "stdafx.h"
#include "Mage.h"


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

bool Mage::WearWeapon(int index)
{
	return weapon = dynamic_cast<Staff*>(items[index]);
}
