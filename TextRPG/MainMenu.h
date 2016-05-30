#pragma once
#include <string>
#include <vector>

class MainMenu
{
private:
	std::string Title;
	void keyboard();
	std::vector <std::string> options;
	int X;
	int Y;
public:
	MainMenu(std::string title, int X, int Y);
	~MainMenu();
	void Show();
};

