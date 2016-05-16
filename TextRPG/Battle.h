#pragma once
#include "Player.h"
#include <vector>
#include "Enemy.h"

class Battle
{
private:
	Player &P;
	std::vector<Character*> MyTeam;
	std::vector<Enemy*> Enemies;
	int enemyIndex;
	int calcDamage(Character *attacker, Character *defender);
	void begin();
	void end(bool result);
	bool checkDead();
	void damage(Character *ch1, Character *ch2, bool tab);
public:
	Battle(Player &p);
	~Battle();
	void Start();
	void AddToFirstTeam(Character *first,...);
	void AddToSecondTeam(Enemy *first,...);
};

