#include "stdafx.h"
#include "FoodItem.h"


FoodItem::FoodItem(std::string name, int hp)
	:
	Item(name),
	Hp(hp)
{
}


FoodItem::~FoodItem()
{
}

int FoodItem::GetHp()
{
	return Hp;
}
