#pragma once
#include "Action.h"
class GiveItemAction :
	public Action
{
private:
	int itemId;
	int amount;
	int cost;
public:
	GiveItemAction(int id, int am, int co);
	~GiveItemAction();
	int Do(Player *p);
};

