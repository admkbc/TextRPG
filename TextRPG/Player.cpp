#include "stdafx.h"
#include "Player.h"


Player::Player(std::string name, int hp, int atack, int defense, int happiness)
	: 
	Character(name, hp, atack, defense), Happiness(happiness)
{
}

Player::~Player()
{
}
