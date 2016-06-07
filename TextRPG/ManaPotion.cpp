#include "stdafx.h"
#include "ManaPotion.h"
#include "Mage.h"

using namespace std;

ManaPotion::ManaPotion(string name,int v) 
	:
	Item(name),
	value(v)
{
}


ManaPotion::~ManaPotion()
{
}

bool ManaPotion::Use(Player* p)
{
	Mage *m = dynamic_cast<Mage*>(p);
	if (m != NULL)
	{
		m->AddMana(value);
		return true;
	}
	return false;		
}
