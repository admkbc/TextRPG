#include "stdafx.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(std::string name, int hp, int atack, int defense)
	:
	Character(name, hp, atack, defense)
{
}


Enemy::~Enemy()
{
}

void Enemy::HpInfo()
{
	cout << Name << " ma " << Hp << " HP" << endl;
}
