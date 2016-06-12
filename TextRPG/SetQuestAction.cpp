#include "stdafx.h"
#include "SetQuestAction.h"


SetQuestAction::SetQuestAction(int id, int ch)
	:
	chPointToSet(ch),
	questId(id)
{
}


SetQuestAction::~SetQuestAction()
{
}

int SetQuestAction::Do(Player* p)
{
	p->quests[questId]->SetCheckpoint(chPointToSet);
	return 0;
}
