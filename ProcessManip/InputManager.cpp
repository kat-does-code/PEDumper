#include "stdafx.h"
#include "InputManager.h"
#include <iostream>

using namespace std;

char* cmd;

void InputManager::ReadInput()
{
	cin >> cmd;
	
	if (iscmd(help))
		PrintHelp();
	else if(iscmd())
}

bool InputManager::iscmd(PCHAR pdcmd)
{
	return strcmp(cmd, pdcmd) == 0;
}
