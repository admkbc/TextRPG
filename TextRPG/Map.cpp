#include "stdafx.h"
#include "Map.h"
#include "Warrior.h"
#include "Mage.h"


Map::Map(Player *P)
	:
	p(P)
{
	//p->AddItem(new Sword("Miecz dwureczny twoja stara", 999));
	//p->AddItem(new Sword("Drewniany miecz", 5));
	//p->AddItem(new Armor("Stalowa zbroja", 10));
	//p->AddItem(new FoodItem("Banan", 100));
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
