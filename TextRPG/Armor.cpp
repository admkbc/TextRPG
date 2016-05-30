#include "stdafx.h"
#include "Armor.h"


Armor::Armor(std::string name, int defendkbonus)
	:
	Item(name),
	defendBonus(defendkbonus)
{
}


Armor::~Armor()
{
}
