#include "stdafx.h"
#include "Sword.h"


Sword::Sword(std::string name, int attackbonus)
	:
	Item(name),
	attackBonus(attackbonus)
{
}


Sword::~Sword()
{
}
