// TextRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include "Player.h"
#include "Battle.h"
#include <ctime>
#include "Enemy.h"
#include "Npc.h"

int main()
{
	srand(time(NULL));

	Player Gracz("Gracz", 100, 60, 40, 1);
	//Enemy *Wilk = new Enemy("Wilk", 1, 1, 5);
	//Enemy *Niedzwiedz = new Enemy("Niedzwiedz", 30, 1, 1);
	//Enemy *Dragon = new Enemy("Dragon", 200, 50, 50);

	//Enemy *Demon = new Enemy("Demon", 100, 60, 60);
	//Battle walka(Gracz, false);
	//walka.AddToSecondTeam(Dragon, NULL);
	//walka.Start();
	//_getch();

	Npc Bot("Bot", 10, 10, 10,"TestNPC");
	Bot.Talk(Gracz);
    return 0;
}

