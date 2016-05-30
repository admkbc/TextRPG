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

class Location;

int main()
{
	srand(time(NULL));

	Mage Gracz("Gracz", 100, 30, 30, 10);
	//Enemy *Wilk = new Enemy("Wilk", 1, 1, 5);
	//Enemy *Niedzwiedz = new Enemy("Niedzwiedz", 30, 1, 1);
	//Enemy *Dragon = new Enemy("Dragon", 100, 50, 50);
	// 
	//Enemy *Demon = new Enemy("Demon", 100, 60, 60);
	//Battle walka(Gracz, false);
	//walka.AddToSecondTeam(Dragon, Niedzwiedz, Wilk, NULL);
	//Gracz.AddItem(new Sword("Wooden sword", 10));
	//Gracz.WearSword(0);
	//walka.Start();
	

	//Npc Bot("Bot", 50, 30, 50,"TestNPC");
	//Bot.Talk(Gracz);

	//MainMenu Menu("Menu glowne");
	//Menu.Show();
	Gracz.AddItem(new Staff("Magiczny kij", 10));
	Gracz.WearWeapon(0);
	Location loc("TownExample");
	loc.GoTo(Gracz);
	//Npc mag("Xanthoceras", 500, 100, 100, "xanthoceras");
	//mag.Talk(Gracz);
	_getch();
    return 0;
}

