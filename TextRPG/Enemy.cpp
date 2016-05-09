#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(std::string name, int hp, int atack, int defense)
	:
	Character(name, hp, atack, defense)
{
}


Enemy::~Enemy()
{
}
