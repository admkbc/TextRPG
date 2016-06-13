#include "stdafx.h"
#include "Game.h"
#include "Warrior.h"
#include <iostream>
#include "Player.h"
#include "Npc.h"
#include "Mage.h"
#include "Paladin.h"
#include <fstream>

using namespace std;

void Game::prolog(int &prof, string &name)
{
	system("cls");
	cout << "Podaj swoje imie: ";
	cin >> name;
	Player *p = new Warrior(name, 10, 1, 1, 1);
	Npc *bot = new Npc("Xanthoceras", 200, 80, 80, "xanthoceras");
	prof = bot->Talk(p);
	delete p;
	delete bot;
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
		map = new Map(new Warrior(name, 10, 1, 1, 1));
		break;
	case 2:
		map = new Map(new Mage(name, 10, 1, 1, 1));
		break;
	case 3:
		map = new Map(static_cast<Warrior*>(new Paladin(name, 10, 1, 1, 1)));
		break;
	}
	map->LoadLocationFile("Miasto", "town");
	map->LoadLocationFile("Wieza magow", "magictower");
	map->LoadLocationFile("Las", "forest");
	map->LoadLocationFile("Jaskinia smoka", "cave");
	map->LoadLocation(0, false);
}

void Game::LoadGame()
{
	Warrior *w = new Warrior("test", 100, 20, 20, 20);
	map = new Map(w);
	map->LoadLocationFile("Miasto", "town");
	map->LoadLocationFile("Wieza magow", "magictower");
	map->LoadLocationFile("Las", "forest");
	map->LoadLocationFile("Jaskinia smoka", "cave");
	map->LoadLocation(0, false);
	
}

void Game::SaveGame()
{
	std::ofstream f;
	f.open("test", ios::trunc | ios::out);
	map->Save(f);
	f.close();
}
