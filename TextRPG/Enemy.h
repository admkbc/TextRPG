#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy(std::string name, int hp, int atack, int defense);
	~Enemy();
};

