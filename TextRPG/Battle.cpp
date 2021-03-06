#include "stdafx.h"
#include "Battle.h"
#include <iostream>
#include <conio.h>
#include <stdarg.h>
#include <algorithm>
#include <cstdlib>
#include <windows.h>

using namespace std;

Battle::Battle(Player *p, bool fenemy)
	:
	P(p),
	firstenemy(fenemy)
{
	enemyIndex = 0;
}

Battle::~Battle()
{

}

inline int Battle::calcDamage(Character *attacker, Character *defender)
{
	Player *p;
	int skill, armorBonus, weaponBonus, randomSkill;
	//if attacker is player, calculate happiness and skill bonus
	if (p = dynamic_cast<Player*>(attacker))
	{
		weaponBonus = p->GetAttackBonus();
		if (weaponBonus != 0)
		{
			randomSkill = rand() % p->GetHappiness();
			skill = p->GetSkill();
		}
		else
		{
			randomSkill = 0;
			skill = 0;
		}
		armorBonus = 0;
	}
	else
	{
		p = dynamic_cast<Player*>(defender);
		randomSkill = 0;
		skill = 0;
		weaponBonus = 0;
		armorBonus = p->GetDefendBonus();
	}
	double random = (rand() % 7) + 7;
	//calc damage
	double damage = static_cast<double>(max(attacker->Attack+weaponBonus+skill*randomSkill-defender->Defense-armorBonus,1)*random/10);
	return damage;
}

int Battle::calcItemBonus()
{
	return 0;
}

//Show info about enemies
void Battle::begin()
{
	system("cls");
	for (int i = 0; i < Enemies.size(); ++i)
	{
		cout << "  Przeciwnik: " << Enemies[i]->Name << "(Attack: " << Enemies[i]->Attack << ", Defense: " << Enemies[i]->Defense << ")" << endl;
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
	{
		cout << endl << "Wygrana!" << endl;
	}
	else
	{
		cout << endl << "\tPorazka" << endl;
		if (!P->items.empty()) 
		{
			//rand item id
			int random = rand() % P->items.size();
			cout << endl << "Przeciwnik zabral Ci " << P->items[random]->GetName();
			//delete random item
			P->items.erase(P->items.begin() + random);
			//remove item from eq because deleted item may be used
			P->RemoveFromEq(-1);
			P->RemoveFromEq(-2);
		}
		//Set HP to 0
		P->Hp = 0;
	}
	_getch();
}

bool Battle::checkDead()
{
	if (Enemies[enemyIndex]->IsDead())
	{
		cout << Enemies[enemyIndex]->Name << " zginal" << endl;
		int exp = (Enemies[enemyIndex]->Attack + Enemies[enemyIndex]->Defense) * 10;
		P->AddExp(exp);
		cout << "Otrzymales " << exp << " EXP." << endl;
		//If enemies had quest
		if (Enemies[enemyIndex]->questId >= 0)
			P->quests[Enemies[enemyIndex]->questId]->Next();

		Enemies.erase(Enemies.begin() + enemyIndex);
		//Choose first enemy
		enemyIndex = 0;
		//If all enemies is dead
		if (!Enemies.size())
		{
			end(true);
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}

//Function show damage info
void Battle::damage(Character *ch1, Character *ch2, bool tab)
{
	if (tab)
		cout << "\t";
	cout << ch1->Name << " zadal " << ch2->Hit(calcDamage(ch1, ch2)) << " obrazen " << ch2->Name;
	cout << "(HP: " << ch2->GetHp() << ")" << endl;
}

bool Battle::enemyHit()
{
	for (int i = 0; i < Enemies.size(); ++i)
	{
		damage(Enemies[i], P, true);
		if (P->IsDead())
		{
			end(false);
			return true;
		}
	}
	return false;
}

void Battle::Start()
{
	char ch;
	
	begin();
	if(firstenemy)
	{
		if(enemyHit())
			return;
	}
	for (;;)
	{
		while ((ch = _getch()) != ' ')
		{
			//Choose enemy
			if ((static_cast<int>(ch) - 48) <= Enemies.size())
			{
				enemyIndex = static_cast<int>(ch) - 49;
				cout << "Celujesz w " << Enemies[enemyIndex]->Name << endl;
			}
		}
		//damage info
		damage(P, Enemies[enemyIndex], false);
		if (checkDead())
			return;

		//Somebody in my team alive
		if (!MyTeam.empty())
		{
			for (int i = 0; i < MyTeam.size(); ++i)
			{
				damage(MyTeam[i], Enemies[enemyIndex], false);
				if (checkDead())
					return;
			}
		}		
		if (enemyHit())
			return;
	}
}

//Function add character to first team
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

//Function add character to enemy team
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
