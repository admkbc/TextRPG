#pragma once
#include "Player.h"
#include <vector>

class Battle
{
private:
	Player &P;
	std::vector<Character*> Enemies;
	int calcDamage(Character *attacker, Character *defender);
	void begin();
	void end(bool result);
public:
	Battle(Player &p1, Character *en1,...);
	~Battle();
	void Start();
};

