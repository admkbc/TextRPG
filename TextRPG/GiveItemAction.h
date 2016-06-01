#pragma once
#include "Action.h"
class GiveItemAction :
	public Action
{
private:
	int itemId;
	int amount;
public:
	GiveItemAction(int id, int am);
	~GiveItemAction();
	void Do(Player *p);
};

