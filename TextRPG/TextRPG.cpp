// TextRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Battle.h"
#include <ctime>
#include "Enemy.h"


int main()
{
	srand(time(NULL));

	Player Gracz("Gracz", 100, 2, 1, 1);
	Enemy Wilk("Wilk", 50, 2, 1);
	Enemy Niedzwiedz("Niedzwiedz", 70, 1, 1);
	Enemy Lis("Lis", 10, 1, 1);
	Battle walka(Gracz,&Wilk,&Niedzwiedz, &Lis, NULL);
	walka.Start();
	_getch();
    return 0;
}

