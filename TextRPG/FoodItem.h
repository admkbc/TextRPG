#pragma once
#include <string>
#include "Item.h"
#include "Player.h"

class FoodItem : public Item
{
private:
	int Hp;
public:
	FoodItem(std::string name, int hp);
	~FoodItem();
	bool Use(Player *p);
};

