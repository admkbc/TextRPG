#pragma once
#include "Item.h"
class Sword :
	public Item
{
private:
	int attackBonus;
public:
	Sword(std::string name, int attackbonus);
	~Sword();
};

