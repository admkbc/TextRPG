#pragma once
#include "Item.h"
class Staff :
	public Item
{
private:
	int magicBonus;
public:
	Staff(std::string name, int magicbonus);
	~Staff();
	

	friend class Mage;
};

