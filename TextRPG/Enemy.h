#pragma once
#include "Character.h"
class Enemy :
	public Character
{
private:
	int questId;
public:
	Enemy(std::string name, int hp, int atack, int defense, int quest);
	~Enemy();
	int GetSkill();
	int GetHappiness();

	void HpInfo();

	friend class Battle;
};

