#pragma once
#include <string>
#include <fstream>

class Player;

class Item
{
protected:
	std::string Name;
public:
	Item(std::string name);
	virtual ~Item();
	std::string GetName();
	virtual bool Use(Player *p) = 0;
	virtual void Save(std::ofstream &f) = 0;
};

