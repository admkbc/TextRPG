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

bool FoodItem::Use(Player* p)
{
	p->AddHp(Hp);
	return true;
}
