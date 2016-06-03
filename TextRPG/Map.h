#pragma once
#include <vector>

class Location;

#include "Location.h"

class Map
{
private:
	std::vector<Location*> locations;
	Player *p;
	int nextLocation;
public:
	Map();
	~Map();
	void LoadLocationFile(std::string name, std::string locfile);
	void LoadLocation(int id, bool mons);
	std::string GetNameOfLocation(int i);
};
