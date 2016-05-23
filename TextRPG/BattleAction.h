#pragma once
#include "Action.h"
#include "Enemy.h"

class BattleAction :
	public Action
{
private:
	Enemy *opponent;

public:
	BattleAction(Enemy *op);
	~BattleAction();
	void Do(Player &p);
};

