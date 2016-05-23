#pragma once
#include "Action.h"
class GiveItem :
	public Action
{
private:
	int itemId;
	int amount;
public:
	GiveItem(int id, int am);
	~GiveItem();
	void Do(Player &p);
};

