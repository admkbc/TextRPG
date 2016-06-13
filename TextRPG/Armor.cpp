#include "stdafx.h"
#include "Armor.h"

using namespace std;

Armor::Armor(std::string name, int defendkbonus)
	:
	Item(name),
	defendBonus(defendkbonus)
{
}


Armor::~Armor()
{
}

bool Armor::Use(Player* p)
{
	p->WearItem(this);
	return false;
}

void Armor::Save(std::ofstream& f)
{
	f << 0 << Name << " " << defendBonus << endl;
}
