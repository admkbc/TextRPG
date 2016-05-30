#pragma once
#include "Player.h"
#include "Staff.h"

class Mage :
	public Player
{
protected:
	int mana;
	int maxMana;
	int magicSkill;
	Staff *weapon;
	
public:
	Mage(std::string name, int hp, int atack, int defense, int happiness);
	~Mage();
	int GetAttackBonus();
	int GetDefendBonus();
	int GetSkill();
	bool WearWeapon(int index);
};

