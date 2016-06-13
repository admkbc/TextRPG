#pragma once
#include <string>
#include "Map.h"

class Game
{
private:
	void prolog(int &prof, std::string &name);
	void LoadLocations();
	Map *map;
public:
	Game();
	~Game();
	void NewGame();
	void LoadGame();
	void SaveGame();
};

