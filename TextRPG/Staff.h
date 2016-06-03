#pragma once
#include "Item.h"
#include "Player.h"
class Staff :
	public Item
{
private:
	int magicBonus;
public:
	Staff(std::string name, int magicbonus);
	~Staff();
	bool Use(Player *p);

	friend class Mage;
};

