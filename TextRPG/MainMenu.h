#pragma once
#include <string>
#include <vector>
#include "Game.h"

class MainMenu
{
private:
	std::string Title;
	int keyboard();
	std::vector <std::string> options;
	int X;
	int Y;
	Game g;
public:
	MainMenu(std::string title, int X, int Y);
	~MainMenu();
	int Show(bool save);
};

