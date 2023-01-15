#pragma once
#ifdef _WIN32 
#define CONSOLE_CLEAR system("cls");
#elif __linux__
#define CSL_CLEAR system("clear");
#endif

#include <Windows.h>

// HANDLE WindowHandl = GetStdHandle(STD_OUTPUT_HANDLE);

enum Colors {
	BLUE = 1,
	GREEN,
	YELLOW = 6,
	WHITE,
	RED = 42
};

enum GameMenu {
	START = 1,
	HISTORY,
	EXIT
};