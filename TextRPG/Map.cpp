#include "stdafx.h"
#include "Map.h"
#include "Warrior.h"
#include "Mage.h"


Map::Map()
{
	p = new Warrior("Ja", 20, 20, 20, 10);
	p->AddItem(new Sword("Brazowy miecz", 10));
	p->AddItem(new Sword("Stalowy miecz", 20));
	p->AddItem(new FoodItem("Banan", 100));
	p->AddItem(new Armor("Stalowa zbroja", 20));
}


Map::~Map()
{
}

void Map::LoadLocationFile(std::string name, std::string locfile)
{
	locations.push_back(new Location(name,locfile));
}

void Map::LoadLocation(int id, bool mons)
{
	int locId = id;
	bool monsters = mons;
	while (true)
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
