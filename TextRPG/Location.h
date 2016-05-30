#pragma once
#include <vector>
#include "Enemy.h"

class Player;

struct EnemyProbability
{
	std::vector <Enemy*> enemies;
	int probability;
};

class Location
{
protected:
	std::vector <EnemyProbability*> enemies;
	std::vector <std::string> menuOptions;
	void AddEnemy();
	void AddOption();
public:
	Location(std::string locfile);
	~Location();
	void GoTo(Player &p);
};

