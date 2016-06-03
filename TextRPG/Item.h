#pragma once
#include <string>

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
};

