#include "stdafx.h"
#include "Battle.h"
#include <iostream>
#include <conio.h>
#include <stdarg.h>
#include <algorithm>

using namespace std;

Battle::Battle(Player &p, bool fenemy)
	:
	P(p),
	firstenemy(fenemy)
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
	for (int i = 0; i < 51; ++i)
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
		//Enemies[enemyIndex]->HpInfo();
		return false;
	}
}

void Battle::damage(Character *ch1, Character *ch2, bool tab)
{
	if (tab)
		cout << "\t";
	cout << ch1->Name << " zadal " << ch2->Hit(calcDamage(ch1, ch2)) << " obrazen " << ch2->Name;
	cout << "(HP: " << ch2->GetHp() << ")" << endl;
}

void Battle::enemyHit()
{
	for (int i = 0; i < Enemies.size(); ++i)
	{
		damage(Enemies[i], &P, true);
	}
}

void Battle::Start()
{
	char ch;
	
	begin();
	if(firstenemy)
	{
		enemyHit();
		if (P.IsDead())
		{
			end(false);
			return;
		}
	}
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
		damage(&P, Enemies[enemyIndex], false);
		if (checkDead())
			return;

		if (!MyTeam.empty())
		{
			for (int i = 0; i < MyTeam.size(); ++i)
			{
				damage(MyTeam[i], Enemies[enemyIndex], false);
				if (checkDead())
					return;
			}
		}		

		for (int i = 0; i < Enemies.size(); ++i)
		{
			enemyHit();
			if (P.IsDead())
			{
				end(false);
				return;
			}
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
