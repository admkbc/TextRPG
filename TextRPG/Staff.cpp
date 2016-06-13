#include "stdafx.h"
#include "Staff.h"

using namespace std;

Staff::Staff(string name, int magicbonus)
	:
	Item(name),
	magicBonus(magicbonus)
{
}


Staff::~Staff()
{
}

bool Staff::Use(Player* p)
{
	p->WearItem(this);
	return false;
}

void Staff::Save(std::ofstream& f)
{
	f << 3 << Name << " " << magicBonus << endl;
}
