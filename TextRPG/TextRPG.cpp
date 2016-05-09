// TextRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Battle.h"
#include <ctime>


int main()
{
	srand(time(NULL));

	Player Stefan("Gracz", 100, 2, 1, 1);
	Player Mietek("Wilk", 50, 1, 1, 1);
	Battle walka(Stefan,Mietek);
	walka.Start();
	_getch();
    return 0;
}

