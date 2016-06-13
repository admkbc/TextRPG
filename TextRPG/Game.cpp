#include "stdafx.h"
#include "Game.h"
#include "Warrior.h"
#include <iostream>
#include "Player.h"
#include "Npc.h"
#include "Mage.h"
#include "Paladin.h"
#include <fstream>
#include <conio.h>

using namespace std;

void Game::prolog(int &prof, string &name)
{
	system("cls");
	cout << "Podaj swoje imie: ";
	cin >> name;
	Player *p = new Warrior(name, 10, 1, 1, 1,0,0,10);
	Npc *bot = new Npc("Xanthoceras", 200, 80, 80, "xanthoceras");
	prof = bot->Talk(p);
	delete p;
	delete bot;
}

void Game::LoadLocations()
{
	map->LoadLocationFile("Miasto", "town");
	map->LoadLocationFile("Wieza magow", "magictower");
	map->LoadLocationFile("Las", "forest");
	map->LoadLocationFile("Jaskinia smoka", "cave");
}

Game::Game()
{
}


Game::~Game()
{
	if (map != NULL)
		delete map;
}

void Game::NewGame()
{
	int prof = 0;
	string name;
	prolog(prof,name);
	switch(prof)
	{
	case 1:
		map = new Map(new Warrior(name, 10, 1, 1, 1,0,2000,100));
		break;
	case 2:
		map = new Map(new Mage(name, 10, 1, 1, 1, 0, 2000, 100));
		break;
	case 3:
		map = new Map(static_cast<Warrior*>(new Paladin(name, 10, 1, 1, 1, 0, 2000, 100)));
		break;
	}
	LoadLocations();
	map->LoadLocation(0, false);
}

void Game::LoadGame()
{
	string filename;
	system("cls");
	cout << "Podaj nazwe: ";
	cin >> filename;
	filename += ".sav";
	std::ifstream f;
	f.open(filename);
	if (!f.good())
	{
		cout << "Bledna nazwa!";
		_getch();
		return;
	}
	map = new Map(NULL);
	LoadLocations();
	map->LoadMapFromFile(f);
	map->LoadLocation(0, false);
}

void Game::SaveGame()
{
	string filename;
	system("cls");
	cout << "Podaj nazwe: ";
	cin >> filename;
	filename += ".sav";
	std::ofstream f;
	f.open(filename, ios::trunc | ios::out);
	map->Save(f);
	f.close();
}
