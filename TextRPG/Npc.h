#pragma once
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include "Sentence.h"
#include "Funs.h"

class Npc :
	public Enemy
{
private:
	void begin();
	void prints(std::string text);
	int position;
	std::vector<Sentence*> sentences;
	std::vector<Sentence*>::iterator sentencesIt;
	void menu();
	void AddAction(std::string &line, Sentence *s);
	void AddQuestion(std::string &line, Sentence *s);
	void AddAnswer(std::string &line, Sentence *s);

public:
	Npc(std::string name, int hp, int atack, int defense, std::string npcfile);
	~Npc();
	int Talk(Player *p);
	std::string GetName();
};

