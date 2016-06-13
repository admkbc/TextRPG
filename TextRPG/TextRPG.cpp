// TextRPG.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <ctime>
#include "MainMenu.h"
#include <conio.h>


#ifdef _DEBUG 
#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 
#endif 
#endif  // _DEBUG

int main()
{
	{
		srand(time(NULL));
		MainMenu menu("Menu glowne", 10, 10);
		menu.Show(false);
	}
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF);
	//_CrtDumpMemoryLeaks();
    return 0;
}

