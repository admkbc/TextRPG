#pragma once
#include "Enemy.h"
#include "Player.h"
#include <list>
#include <vector>

struct Sentence
{
	std::string question;
	std::vector<std::string> answers;
	std::vector<int> nextq;
};

class Npc :
	public Enemy
{
private:
	void gotoxy(int x, int y);
	void begin();
	void prints(std::string text);
	int position;
	std::vector<Sentence*> sentences;
	void menu();

public:
	Npc(std::string name, int hp, int atack, int defense, std::string npcfile);
	~Npc();
	void Talk(Player &p);
};

