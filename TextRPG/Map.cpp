#include "stdafx.h"
#include "Map.h"
#include "Warrior.h"
#include "Mage.h"
#include "FoodItem.h"
#include <fstream>
#include <iostream>


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
	p;
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

