#include "stdafx.h"
#include "Map.h"
#include "Warrior.h"
#include "Mage.h"
#include "Paladin.h"
#include "FoodItem.h"
#include <fstream>
#include <iostream>

using namespace std;

Map::Map(Player *P)
{
	p = P;
}

Map::~Map()
{
	for (int i = 0; i < locations.size(); ++i)
		delete locations[i];

	delete p;
}

void Map::LoadLocationFile(std::string name, std::string locfile)
{
	locations.push_back(new Location(name,locfile));
}

void Map::LoadLocation(int id, bool mons)
{
	int locId = id;
	bool monsters = mons;
	while (locId >= 0)
	{
		if (locations.size() > 0)
		{
			if (monsters) 
				locations[locId]->GoTo(p);
			locId = locations[locId]->Menu(p, this);
			monsters = true;
		}
	}
}

std::string Map::GetNameOfLocation(int i)
{
	if (i < locations.size())
		return locations[i]->name;
	else
		return "";
}

void Map::Save(std::ofstream &f)
{
	if (p != NULL)
		p->Save(f);
}

void Map::LoadMapFromFile(std::ifstream& f)
{
	string chType, hp, name, attack, defense, happiness, exp, money, maxhp;
	int chTypeInt;
	getline(f, chType);
	getline(f, name);
	getline(f, hp);
	getline(f, attack);
	getline(f, defense);
	getline(f, happiness);
	getline(f, exp);
	getline(f, money);
	getline(f, maxhp);
	chTypeInt = atoi(chType.c_str());
	switch(chTypeInt)
	{
	case 0:
		p = new Warrior(name, atoi(hp.c_str()), atoi(attack.c_str()), atoi(defense.c_str()), atoi(happiness.c_str()), atoi(exp.c_str()),atoi(money.c_str()),atoi(maxhp.c_str()));
		break;
	case 1:
		p = new Mage(name, atoi(hp.c_str()), atoi(attack.c_str()), atoi(defense.c_str()), atoi(happiness.c_str()), atoi(exp.c_str()), atoi(money.c_str()), atoi(maxhp.c_str()));
		break;
	case 2:
		p = new Paladin(name, atoi(hp.c_str()), atoi(attack.c_str()), atoi(defense.c_str()), atoi(happiness.c_str()), atoi(exp.c_str()), atoi(money.c_str()), atoi(maxhp.c_str()));
		break;
	}
	p->LoadStatsFromFile(f);
}
