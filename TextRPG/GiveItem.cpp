#include "stdafx.h"
#include "GiveItemAction.h"
#include "Sword.h"


GiveItem::GiveItem(int id, int am)
{
	itemId = id;
	amount = am;
}


GiveItem::~GiveItem()
{
}

void GiveItem::Do(Player &p)
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
	p.AddItem(i);
}
