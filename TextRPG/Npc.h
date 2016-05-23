#pragma once
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include "Sentence.h"

class Npc :
	public Enemy
{
private:
	void gotoxy(int x, int y);
	void begin();
	void prints(std::string text);
	int position;
	std::vector<Sentence*> sentences;
	std::vector<Sentence*>::iterator sentencesIt;
	void menu();

public:
	Npc(std::string name, int hp, int atack, int defense, std::string npcfile);
	~Npc();
	void Talk(Player &p);
};

