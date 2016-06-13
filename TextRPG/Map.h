#pragma once
#include <vector>

class Location;

#include "Location.h"

class Map
{
private:
	std::vector<Location*> locations;
	
	int nextLocation;
public:
	Map(Player *P);
	~Map();
	void LoadLocationFile(std::string name, std::string locfile);
	void LoadLocation(int id, bool mons);
	std::string GetNameOfLocation(int i);
	void Save(std::ofstream &f);
	void Test();
	Player *p;
};

