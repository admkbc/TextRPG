#pragma once
#include "Item.h"
class ManaPotion :
	public Item
{
	int value;
public:
	ManaPotion(std::string name, int v);
	~ManaPotion();
	bool Use(Player *p);
};

