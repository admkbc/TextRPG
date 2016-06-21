// TextRPG.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include "MainMenu.h"

int main()
{
	srand(time(NULL));
	MainMenu menu("Menu glowne", 10, 10);
	menu.Show(false);
	return 0;
}

