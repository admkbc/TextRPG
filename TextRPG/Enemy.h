#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy(std::string name, int hp, int atack, int defense);
	~Enemy();
	int GetSkill();
	int GetHappiness();

	void HpInfo();
};

