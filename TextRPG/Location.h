#pragma once
#include <vector>
#include "Enemy.h"
#include "Npc.h"

class Map;

#include "Map.h"

class Player;

struct EnemyProbability
{
	std::vector <Enemy*> enemies;
	int probability;
};

class Location
{
private:
	std::string name;
	std::vector <EnemyProbability*> enemies;
	std::vector <Npc*> npcs;
	std::vector <int> locations;
	void header();
public:
	Location(std::string n, std::string locfile);
	~Location();
	void GoTo(Player *p);
	int Menu(Player *p, Map *m);

	friend class Map;
};

