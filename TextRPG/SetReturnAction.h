#pragma once
#include "Action.h"
class SetReturnAction :
	public Action
{
private:
	int value;
public:
	SetReturnAction(int v);
	~SetReturnAction();
	int Do(Player *p);
};

