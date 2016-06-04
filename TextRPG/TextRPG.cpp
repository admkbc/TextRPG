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
#include "Game.h"

class Location;

int main()
{
	srand(time(NULL));
	MainMenu menu("Menu glowne",10,10);
	menu.Show(false);
    return 0;
}

