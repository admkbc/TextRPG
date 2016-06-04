#pragma once
#include "Player.h"

class Action
{
public:
	Action();
	virtual ~Action();
	virtual int Do(Player *p) = 0;
};

