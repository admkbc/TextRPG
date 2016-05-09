#pragma once
#include "Player.h"

class Battle
{
private:
	Player &P1;
	Player &P2;
	int Hit(Player &attacker, Player &defender);
public:
	Battle(Player &p1, Player &p2);
	~Battle();
	void Start();
};

