#include "stdafx.h"
#include "SetReturnAction.h"


SetReturnAction::SetReturnAction(int v)
	:
	value(v)
{
}


SetReturnAction::~SetReturnAction()
{
}

int SetReturnAction::Do(Player* p)
{
	return value;
}
