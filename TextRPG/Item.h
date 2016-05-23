#pragma once
#include <string>

class Item
{
protected:
	std::string Name;
public:
	Item(std::string name);
	~Item();
};

