#pragma once
#include "Mage.h"
#include "Warrior.h"

class Paladin :
	public virtual Mage,
	public virtual Warrior
{
public:
	Paladin(std::string name, int hp, int atack, int defense, int happiness);
	~Paladin();
	int GetSkill();
	int GetAttackBonus();
	int GetDefendBonus();
	void WearItem(Item *it);
	void ShowStats();
	void ShowEq();
	void RemoveFromEq(int id);
	void Save(std::ofstream &f);
};

