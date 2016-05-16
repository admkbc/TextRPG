#include "stdafx.h"
#include "Npc.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void Npc::gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Npc::begin()
{
	cout << "  Rozmowca: " << Name << endl;
	for (int i = 0; i < 50; ++i)
		cout << static_cast<char>(205);
	cout << static_cast<char>(188) << endl;
}

Npc::Npc(std::string name, int hp, int atack, int defense)
	:
	Enemy(name, hp, atack, defense)
{
}


Npc::~Npc()
{
}

void Npc::Talk(Player &p)
{
	begin();
	string tekst = "Witaj! Co slychac?";
	for (int i = 0; i < tekst.length(); ++i)
	{
		cout << tekst[i];
		Sleep(80);
	}
}
