#pragma once
#include "Item.h"
#include "Player.h"
class Sword :
	public Item
{
private:
	int attackBonus;
public:
	Sword(std::string name, int attackbonus);
	~Sword();
	bool Use(Player *p);

	friend class Warrior;
	friend class Paladin;
};

