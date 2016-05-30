#include "stdafx.h"
#include "Location.h"
#include <fstream>
#include <sstream>
#include "Battle.h"

using namespace std;

void Location::AddEnemy()
{
}

void Location::AddOption()
{
}

Location::Location(string locfile)
{
	ifstream f;
	string path = locfile + ".loc";
	f.open(path);
	string line;
	int pos;
	while (std::getline(f, line))
	{
		if (line[0] == ':')
		{
			line.erase(line.begin());
			istringstream iss(line);
			string probability;
			iss >> probability;
			EnemyProbability *en = new EnemyProbability;
			en->probability = atoi(probability.c_str());
			while (std::getline(f, line))
			{
				if (line[0] == '*')
				{
					string name, hp, attack, defend;
					line.erase(line.begin());
					istringstream e(line);
					e >> name;
					e >> hp;
					e >> attack;
					e >> defend;
					en->enemies.push_back(new Enemy(name, atoi(hp.c_str()), atoi(attack.c_str()), atoi(defend.c_str())));
					pos = f.tellg();
				}
				else
				{
					f.seekg(pos, ios_base::beg);
					break;
				}
			}
			enemies.push_back(en);
		}
		else if (line[0] == '-')
		{
			
		}
	}
}


Location::~Location()
{
}

void Location::GoTo(Player& p)
{
	int random;
	Battle *b;
	for (int i = 0; i < enemies.size(); ++i)
	{
		random = rand() % 100;
		if (random < enemies[i]->probability)
		{
			b = new Battle(p, true);
			for (int k = 0; k < enemies[i]->enemies.size(); ++k)
			{
				b->AddToSecondTeam(enemies[i]->enemies[k], NULL);
			}
			b->Start();
		}
	}
}
