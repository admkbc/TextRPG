#pragma once
#include "Character.h"
#include "Item.h"
#include <vector>
#include "FoodItem.h"

class Player :
	public Character
{
private:
	void inventoryHead();
	int printItems();

protected:
	int Happiness;
	std::vector<Item*> items;
	int Exp;
	int coins;
	int maxHp;

public:
	Player(std::string name, int hp, int atack, int defense, int happiness);
	virtual ~Player();
	virtual int GetSkill() = 0;
	virtual int GetAttackBonus() = 0;
	virtual int GetDefendBonus() = 0;
	virtual void WearItem(Item *it) = 0;
	virtual void ShowStats() = 0;
	virtual void ShowEq() = 0;
	virtual void RemoveFromEq(int id) = 0;
	void HpInfo();
	void AddHp(int value);
	void AddItem(Item *i);
	int GetHappiness();
	void AddExp(int value);
	void ShowInventory();
	void MainStats();
};

