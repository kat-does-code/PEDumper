// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

const int version = 1;

int main()
{
	printf("Welcome to Process Dumper, the interactive process dumper, version %i", version);
	printf("Please enter your command. Type 'help' for a list of commands.");

	InputManager im;
	im.ReadInput();
	return 0;
}
