#include "stdafx.h"
#include "Quest.h"
#include <fstream>

using namespace std;

int Quest::GetPrize()
{
	if (checkpoint == meta)
		return prize;
	else
		return -1;
}

void Quest::SetCheckpoint(int value)
{
	checkpoint = value;
}

void Quest::Next()
{
	++checkpoint;
}

Quest::Quest(std::string filename)
{
	checkpoint = 0;
	ifstream f;
	string path = "quest/" + filename + ".que";
	f.open(path);
	string line;
	getline(f, line);
	title = line;
	getline(f, line);
	description = line;
	getline(f, line);
	meta = atoi(line.c_str());
	getline(f, line);
	prize = atoi(line.c_str());
	f.close();
}


Quest::~Quest()
{
}

void Quest::Close()
{
	checkpoint = -1;
}

bool Quest::IsTaken()
{
	if (checkpoint > 0 && checkpoint < meta)
		return true;
	else
		return false;
}

std::string Quest::GetName()
{
	return title;
}
