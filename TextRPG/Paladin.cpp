#include "stdafx.h"
#include "Paladin.h"


Paladin::Paladin(std::string name, int hp, int atack, int defense, int happiness)
	:
	Mage(name, hp, atack, defense, happiness),
	Warrior(name, hp, atack, defense, happiness)
{
}


Paladin::~Paladin()
{
}
