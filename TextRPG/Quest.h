#pragma once
#include <string>

class Quest
{
private:
	std::string title;
	std::string description;
	int prize;
	int checkpoint;
	int meta;
public:
	int GetPrize();
	void SetCheckpoint(int value);
	void Next();
	Quest(std::string filename);
	~Quest();
	void Close();
	bool IsTaken();
	std::string GetName();
	void Save(std::ofstream &f);
};

