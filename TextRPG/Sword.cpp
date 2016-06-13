#include "stdafx.h"
#include "Sword.h"

using namespace std;

Sword::Sword(std::string name, int attackbonus)
	:
	Item(name),
	attackBonus(attackbonus)
{
}


Sword::~Sword()
{
}

bool Sword::Use(Player* p)
{
	p->WearItem(this);
	return false;
}

void Sword::Save(std::ofstream& f)
{
	f << 4 << Name << " " << attackBonus << endl;
}
