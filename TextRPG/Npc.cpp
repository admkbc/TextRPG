#include "stdafx.h"
#include "Npc.h"


Npc::Npc(std::string name, int hp, int atack, int defense)
	:
	Enemy(name, hp, atack, defense)
{
}


Npc::~Npc()
{
}
