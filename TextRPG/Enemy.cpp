#include "stdafx.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(std::string name, int hp, int atack, int defense, int quest = -1)
	:
	Character(name, hp, atack, defense),
	questId(quest)
{
}


Enemy::~Enemy()
{
}

int Enemy::GetSkill()
{
	return 0;
}

int Enemy::GetHappiness()
{
	return 1;
}

void Enemy::HpInfo()
{
	cout << Name << " ma " << Hp << " HP" << endl;
}
