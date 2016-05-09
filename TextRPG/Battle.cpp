#include "stdafx.h"
#include "Battle.h"
#include <iostream>
#include <conio.h>
#include <stdarg.h>

using namespace std;

Battle::Battle(Player &p1, Character *en1,...)
	:
	P(p1)
{
	va_list arg;
	va_start(arg, en1);
	Character *en;
	for (en = en1; en != NULL; en = va_arg(arg, Character*)) {
		Enemies.push_back(en);
	}
	va_end(arg);
}

Battle::~Battle()
{
}

inline int Battle::calcDamage(Character *attacker, Character *defender)
{
	double random = (rand() % 4) + 8;
	double damage = static_cast<double>(attacker->Atack/ defender->Defense)*random/10;
	return damage;
}

void Battle::begin()
{
	for (int i = 0; i < Enemies.size(); ++i)
	{
		cout << "  Przeciwnik: " << Enemies[i]->Name << "(Attack: " << Enemies[i]->Atack << ", Defense: " << Enemies[i]->Defense << ")" << endl;
	}
	cout << static_cast<char>(200);
	for (int i = 0; i < 50; ++i)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188) << endl;
}

void Battle::end(bool result)
{
	cout << endl;
	for (int i = 0; i < 70; ++i)
		cout << static_cast<char>(205);
	if (result)
		cout << endl << "Wygrana!" << endl; 
	else
		cout << endl << "\tPorazka" << endl;
}

void Battle::Start()
{
	begin();
	int enemyIndex = 0;
	for (;;)
	{
		_getch();
		cout << "Zadales " << Enemies[enemyIndex]->Hit(calcDamage(&P, Enemies[enemyIndex])) << " obrazen. ";
		if (Enemies[enemyIndex]->IsDead()) 
		{
			if (enemyIndex == Enemies.size() - 1)
			{
				end(true);
				break;
			}
			else
			{
				++enemyIndex;
			}
				
		}
		cout << Enemies[enemyIndex]->Name << " ma " << Enemies[enemyIndex]->Hp << " HP." << endl;
		
		for (int i = enemyIndex; i < Enemies.size(); ++i)
		{
			cout << "\t" << Enemies[i]->Name << " zadal Ci " << P.Hit(calcDamage(Enemies[i], &P)) << " obrazen. ";
			if (P.IsDead())
			{
				end(false);
				return;
			}
			cout << "Zostalo Ci " << P.Hp << " HP." << endl;
		}
	}
}
