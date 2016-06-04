#pragma once
#include "Mage.h"
#include "Warrior.h"

class Paladin :
	virtual public Mage,
	virtual public Warrior
{
public:
	Paladin(std::string name, int hp, int atack, int defense, int happiness);
	~Paladin();
};

