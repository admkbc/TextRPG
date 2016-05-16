#pragma once
#include "Enemy.h"
#include "Player.h"

class Npc :
	public Enemy
{
private:
	void gotoxy(int x, int y);
	void begin();
public:
	Npc(std::string name, int hp, int atack, int defense);
	~Npc();
	void Talk(Player &p);
};

