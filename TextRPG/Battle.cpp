#include "stdafx.h"
#include "Battle.h"
#include <iostream>

using namespace std;

Battle::Battle(Player &p1, Player &p2)
	:
	P1(p1), P2(p2)
{

}

Battle::~Battle()
{
}

inline int Battle::Hit(Player &attacker, Player &defender)
{
	double random = (rand() % 4) + 8;
	double damage = static_cast<double>(attacker.Atack/ defender.Defense)*random/10;
	defender.Hp -= static_cast<int>(damage);
	return damage;
}

void Battle::Start()
{
	cout << "  Przeciwnik: " << P2.Name << "(Attack: " << P2.Atack << ", Defense: " << P2.Defense << ")" << endl;
	
	cout << static_cast<char>(200);
	for (int i = 0; i < P2.Name.length() + 41; ++i)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188) << endl;
	
	for (;;)
	{
		cout << "Zadales " << Hit(P1, P2) << " obrazen. ";
		if (P2.Hp <= 0) 
		{
			cout << endl;
			for (int i = 0; i < 70; ++i)
				cout << static_cast<char>(205);
			cout << endl << "Wygrana!" << endl;
			break;
		}
		cout << P2.Name << " ma " << P2.Hp << " HP." << endl;
		cout << "\t" << P2.Name << " zadal Ci " << Hit(P2, P1) << " obrazen. ";
		if (P1.Hp <= 0)
		{
			cout << endl;
			for (int i = 0; i < 70; ++i)
				cout << static_cast<char>(205);
			cout << endl << "\tPorazka" << endl;
			break;
		}
		cout << "Zostalo Ci " << P1.Hp << " HP." << endl;
	}
}
