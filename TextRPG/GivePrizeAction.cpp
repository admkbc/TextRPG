#include "stdafx.h"
#include "GivePrizeAction.h"
#include <iostream>
#include "Funs.h"


GivePrizeAction::GivePrizeAction(int id)
	:
	questId(id)
{
}


GivePrizeAction::~GivePrizeAction()
{
}

int GivePrizeAction::Do(Player* p)
{
	int value = p->quests[questId]->GetPrize();
	gotoxy(10, 6);
	if (value >= 0)
	{
		std::cout << "Brawo, lap nagrode.";
		p->GiveMoney(value);
		p->quests[questId]->Close();
		return 1;
	}
	std::cout << "Nie wykonales zadania.";
	return 0;
}
