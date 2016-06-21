#pragma once
#include "Mage.h"
#include "Warrior.h"

class Paladin :
	public Mage,
	public Warrior
{
public:
	Paladin(std::string name, int hp, int atack, int defense, int happiness, int exp, int money, int maxhp);
	~Paladin();
	int GetSkill();
	int GetAttackBonus();
	int GetDefendBonus();
	void WearItem(Item *it);
	void ShowStats();
	void ShowEq();
	void RemoveFromEq(int id);
	void Save(std::ofstream &f);
	void LoadStatsFromFile(std::ifstream &f);
};

