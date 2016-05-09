#pragma once
#include <string>

class Character
{
protected:
	std::string Name;
	int Hp;
	int Atack;
	int Defense;
	bool Dead;
	int Hit(int value);
	bool IsDead();

public:
	Character(std::string name, int hp, int atack, int defense);
	virtual ~Character() = 0;


	friend class Battle;
};

