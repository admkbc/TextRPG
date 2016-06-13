#pragma once
#include "Player.h"
#include "Sword.h"
#include "Armor.h"

class Warrior :
	public virtual Player
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
	void WearItem(Item *it);
	void ShowStats();
	void ShowEq();
	void RemoveFromEq(int id);
	void Save(std::ofstream &f);
};

