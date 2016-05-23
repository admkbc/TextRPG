#pragma once
#include <string>
#include "Item.h"

class FoodItem : public Item
{
private:
	int Hp;
public:
	FoodItem(std::string name, int hp);
	~FoodItem();
	int GetHp();
};

