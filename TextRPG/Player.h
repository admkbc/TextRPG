#pragma once
#include "Character.h"
class Player :
	public Character
{
private:
	int Happiness;

public:
	Player(std::string name, int hp, int atack, int defense, int happiness);
	~Player();

	friend class Battle;
};

