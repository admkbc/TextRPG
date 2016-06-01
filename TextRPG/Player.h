#pragma once
#include "Character.h"
#include "Item.h"
#include <vector>
#include "FoodItem.h"

class Player :
	public Character
{
protected:
	int Happiness;
	std::vector<Item*> items;
	int Exp;
	int coins;

public:
	Player(std::string name, int hp, int atack, int defense, int happiness);
	virtual ~Player();
	void HpInfo();
	void Eat(FoodItem *food);
	void AddItem(Item *i);
	int GetHappiness();
	virtual int GetSkill() = 0;
	virtual int GetAttackBonus() = 0;
	virtual int GetDefendBonus() = 0;
	virtual bool WearWeapon(int index) = 0;
	void AddExp(int value);
};

