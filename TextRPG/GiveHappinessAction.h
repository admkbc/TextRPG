#pragma once
#include "Action.h"
class GiveHappinessAction :
	public Action
{
private:
	int value;
	int price;
public:
	GiveHappinessAction(int v, int p);
	~GiveHappinessAction();
	int Do(Player *p);
};

