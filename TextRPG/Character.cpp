#include "stdafx.h"
#include "Character.h"


Character::Character(std::string name,int hp,int atack,int defense)
	:
	Name(name),Hp(hp),Atack(atack),Defense(defense)
{

}

Character::~Character()
{
}
