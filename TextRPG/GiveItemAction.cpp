#include "stdafx.h"
#include "GiveItemAction.h"
#include "Sword.h"


GiveItemAction::GiveItemAction(int id, int am)
{
	itemId = id;
	amount = am;
}


GiveItemAction::~GiveItemAction()
{
}

void GiveItemAction::Do(Player *p)
{
	Item *i;
	switch (itemId)
	{
	case 0:
		i = new Sword("Wooden sword", 5);
		break;
	default:
		i = NULL;
		break;
	}
	p->AddItem(i);
}
