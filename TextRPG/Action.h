#pragma once
#include "Player.h"

class Action
{
public:
	Action();
	virtual ~Action();
	virtual void Do(Player &p) = 0;
};

