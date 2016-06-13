#pragma once
#include "Player.h"
#include "Staff.h"

class Mage :
	public virtual Player
{
protected:
	int mana;
	int maxMana;
	int magicSkill;
	Staff *weapon;
	
public:
	Mage(std::string name, int hp, int atack, int defense, int happiness, int exp, int money, int maxhp);
	~Mage();
	int GetAttackBonus();
	int GetDefendBonus();
	int GetSkill();
	void WearItem(Item *it);
	void ShowStats();
	void ShowEq();
	void RemoveFromEq(int id);
	void AddMana(int value);
	void Save(std::ofstream &f);
	void LoadStatsFromFile(std::ifstream &f);
};

