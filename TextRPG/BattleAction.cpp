#include "stdafx.h"
#include "BattleAction.h"
#include "Battle.h"


BattleAction::BattleAction(Enemy *op)
{
	opponent = op;
}


BattleAction::~BattleAction()
{
}

int BattleAction::Do(Player* p)
{
	Battle f(p, false);
	f.AddToSecondTeam(opponent, NULL);
	f.Start();
	return 0;
}
