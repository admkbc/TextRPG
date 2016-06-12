#pragma once
#include "Action.h"
class GivePrizeAction :
	public Action
{
	int questId;
public:
	GivePrizeAction(int id);
	~GivePrizeAction();
	int Do(Player *p);
};

