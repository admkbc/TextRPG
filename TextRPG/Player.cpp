#include "stdafx.h"
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(std::string name, int hp, int atack, int defense, int happiness)
	: 
	Character(name, hp, atack, defense), Happiness(happiness)
{

}

Player::~Player()
{
}

void Player::HpInfo()
{
	cout << "Masz " << Hp << " HP" << endl;
}

void Player::Eat(FoodItem *food)
{
	Hp += (*food).GetHp();
}

void Player::AddItem(Item* i)
{
	items.push_back(i);
}
