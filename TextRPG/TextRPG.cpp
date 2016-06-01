// TextRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include "Player.h"
#include "Battle.h"
#include <ctime>
#include "Enemy.h"
#include "Npc.h"
#include "Warrior.h"
#include "MainMenu.h"
#include "Location.h"
#include "Mage.h"
#include "Map.h"
#include <iostream>

class Location;

int main()
{
	srand(time(NULL));

	//Warrior P("Gracz", 1, 1, 1, 1);
	//Npc Xanthoceras("Xanthoceras", 1, 1, 1, "xantoceras");
	//Xanthoceras.Talk(P);

	Map map;
	map.LoadLocationFile("Example Town", "TownExample");
	map.LoadLocationFile("Forest", "forest");
	map.LoadLocation(0, false);

	//Mage Gracz("Gracz", 1, 1, 1, 1);
	//Gracz.AddItem(new Staff("Magiczny kij", 10));
	//Gracz.WearWeapon(0);
	//Location loc("Example Town","TownExample");
	//loc.GoTo(Gracz);
	//loc.Menu(Gracz);
    return 0;
}

