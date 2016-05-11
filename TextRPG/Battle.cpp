#include "stdafx.h"
#include "Battle.h"
#include <iostream>
#include <conio.h>
#include <stdarg.h>
#include <algorithm>

using namespace std;

Battle::Battle(Player &p)
	:
	P(p)
{
	enemyIndex = 0;
}

Battle::~Battle()
{
	for (int i = 0; i < MyTeam.size(); ++i)
		delete MyTeam[i];
	for (int i = 0; i < Enemies.size(); ++i)
		delete Enemies[i];
}

inline int Battle::calcDamage(Character *attacker, Character *defender)
{
	double random = (rand() % 7) + 7;
	double damage = static_cast<double>(max(attacker->Atack-defender->Defense,1)*random/10);
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

bool Battle::checkDead()
{
	if (Enemies[enemyIndex]->IsDead())
	{
		cout << Enemies[enemyIndex]->Name << " zginal" << endl;
		Enemies.erase(Enemies.begin() + enemyIndex);
		enemyIndex = 0;
		if (!Enemies.size())
		{
			end(true);
			return true;
		}
		return false;
	}
	else
	{
		Enemies[enemyIndex]->HpInfo();
		return false;
	}
}

void Battle::ShowDamage()
{

}

void Battle::Start()
{
	begin();
	char ch;
	for (;;)
	{
		while ((ch = _getch()) != ' ')
		{
			if ((static_cast<int>(ch) - 48) <= Enemies.size())
			{
				enemyIndex = static_cast<int>(ch) - 49;
				cout << "Celujesz w " << Enemies[enemyIndex]->Name << endl;
			}
		}
		cout << "Zadales " << Enemies[enemyIndex]->Hit(calcDamage(&P, Enemies[enemyIndex])) << " obrazen. ";
		if (checkDead())
			return;
		if (!MyTeam.empty())
		{
			for (int i = 0; i < MyTeam.size(); ++i)
			{
				cout << MyTeam[i]->Name << " zadal " << Enemies[enemyIndex]->Hit(calcDamage(MyTeam[i], Enemies[enemyIndex])) << " obrazen. ";
				if (checkDead())
					return;
			}
		}
				
		for (int i = 0; i < Enemies.size(); ++i)
		{
			cout << "\t" << Enemies[i]->Name << " zadal Ci " << P.Hit(calcDamage(Enemies[i], &P)) << " obrazen. ";
			if (P.IsDead())
			{
				end(false);
				return;
			}
			P.HpInfo();
		}
	}
}

void Battle::AddToFirstTeam(Character *first,...)
{
		va_list arg;
		va_start(arg, first);
		Character *c;
		for (c = first; c != NULL; c = va_arg(arg, Character*)) {
			MyTeam.push_back(c);
		}
		va_end(arg);
}

void Battle::AddToSecondTeam(Enemy *first,...)
{
	va_list arg;
	va_start(arg, first);
	Enemy *e;
	for (e = first; e != NULL; e = va_arg(arg, Enemy*)) {
		Enemies.push_back(e);
	}
	va_end(arg);
}
