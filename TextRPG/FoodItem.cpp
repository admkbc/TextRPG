#include "stdafx.h"
#include "FoodItem.h"

using namespace std;

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

void FoodItem::Save(std::ofstream& f)
{
	f << 1 << Name << " " << Hp << endl;
}
