#include "stdafx.h"
#include "GiveItemAction.h"
#include "Sword.h"
#include "Armor.h"
#include <iostream>
#include "Funs.h"
#include "Staff.h"

using namespace std;

GiveItemAction::GiveItemAction(int id, int am, int co)
{
	itemId = id;
	amount = am;
	cost = co;
}


GiveItemAction::~GiveItemAction()
{
}

int GiveItemAction::Do(Player *p)
{
	Item *i;
	if (p->GetMoney() >= cost)
	{
		switch (itemId)
		{
		case 0:
			i = new Sword("Drewniany prosty miecz", 2);
			break;
		case 1:
			i = new Sword("Brazowy miecz", 5);
			break;
		case 2:
			i = new Sword("Stalowy miecz", 10);
			break;
		case 3:
			i = new Sword("Stalowy miecz dwureczny", 20);
			break;
		case 4:
			i = new Sword("Hartowany miecz", 25);
			break;
		case 5:
			i = new Sword("Hartowany miecz dwureczny", 30);
			break;
		case 6:
			i = new Armor("Drewniany pancerz", 2);
			break;
		case 7:
			i = new Armor("Zelazna zbroja", 5);
			break;
		case 8:
			i = new Armor("Stalowa zbroja", 10);
			break;
		case 9:
			i = new Armor("Hartowana stalowa zbroja", 20);
			break;
		case 10:
			i = new Staff("Drewniana rozdzka", 2);
			break;
		case 11:
			i = new Staff("Podmuch wiatru", 5);
			break;
		case 12:
			i = new Staff("Zywiol wody", 10);
			break;
		case 13:
			i = new Staff("Tsunami", 15);
			break;
		case 14:
			i = new Staff("Zywiol ognia", 20);
			break;
		case 15:
			i = new Staff("Uderzenie piorunem", 30);
			break; 
		default:
			i = NULL;
			break;
		}
		p->AddItem(i);
		p->GiveMoney(-cost);
		return 1;
	}
	else
	{
		gotoxy(10, 6);
		cout << "Nie masz wystarczjaco zlotych monet.";
		return 0;
	}
}
