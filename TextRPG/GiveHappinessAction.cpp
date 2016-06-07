#include "stdafx.h"
#include "GiveHappinessAction.h"
#include <iostream>
#include "Funs.h"

using namespace std;

GiveHappinessAction::GiveHappinessAction(int v, int p)
	:
	value(v),
	price(p)
{
}


GiveHappinessAction::~GiveHappinessAction()
{
}

int GiveHappinessAction::Do(Player* p)
{
	if (p->GetMoney() >= price)
	{
		p->AddHappiness(value);
	}
	else
	{
		gotoxy(10, 6);
		cout << "Nie masz wystarczjaco zlotych monet.";
		return 0;
	}
}
