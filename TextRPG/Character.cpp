#include "stdafx.h"
#include "Character.h"


Character::Character(std::string name,int hp,int atack,int defense)
	:
	Name(name),Hp(hp),Atack(atack),Defense(defense),Dead(false)
{

}

Character::~Character()
{
}

int Character::Hit(int value)
{
	Hp -= value;
	if (Hp <= 0)
		Dead = true;
	return value;
}

bool Character::IsDead()
{
	return Dead;
}
