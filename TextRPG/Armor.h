#pragma once
#include "Item.h"
class Armor :
	public Item
{
private:
	int defendBonus;
public:
	Armor(std::string name, int defendbonus);
	~Armor();

	friend class Warrior;
};

