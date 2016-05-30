#include "stdafx.h"
#include "Warrior.h"


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

bool Warrior::WearWeapon(int index)
{
	return weapon = dynamic_cast<Sword*>(items[index]);
}
