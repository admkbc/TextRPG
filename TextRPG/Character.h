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
	
	

public:
	Character(std::string name, int hp, int atack, int defense);
	virtual ~Character() = 0;
	virtual void HpInfo() = 0;
	bool IsDead();
	int Hit(int value);
	int GetHp();

	friend class Battle;
};

