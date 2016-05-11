#pragma once
#include "Enemy.h"
class Npc :
	public Enemy
{
public:
	Npc(std::string name, int hp, int atack, int defense);
	~Npc();
};

