#pragma once
#include "Player.h"
#include "Sword.h"
#include "Armor.h"

class Warrior :
	public Player
{
protected:
	int swordSkill;
	Sword *weapon;
	Armor *armor;
public:
	Warrior(std::string name, int hp, int atack, int defense, int happiness);
	~Warrior();
	int GetSkill();
	int GetAttackBonus();
	int GetDefendBonus();
	bool WearWeapon(int index);
};

