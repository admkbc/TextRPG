#pragma once
#include "Action.h"

class SetQuestAction :
	public Action
{
private:
	int questId;
	int chPointToSet;
public:
	SetQuestAction(int id, int ch);
	~SetQuestAction();
	int Do(Player *p);
};

