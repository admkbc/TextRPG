#pragma once
#include "Character.h"
#include "Item.h"
#include <vector>
#include "FoodItem.h"

class Player :
	public Character
{
private:
	int Happiness;
	std::vector<Item*> items;
public:
	Player(std::string name, int hp, int atack, int defense, int happiness);
	~Player();
	void HpInfo();
	void Eat(FoodItem *food);
	void AddItem(Item *i);

	friend class Battle;
};

