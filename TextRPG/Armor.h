#pragma once
#include "Item.h"
#include "Player.h"
class Armor :
	public Item
{
private:
	int defendBonus;
public:
	Armor(std::string name, int defendbonus);
	~Armor();
	bool Use(Player *p);
	void Save(std::ofstream &f);

	friend class Warrior;
	friend class Paladin;
};

