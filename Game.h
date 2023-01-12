#pragma once
#ifdef _WIN32 
#define CSL_CLEAR system("cls");
#elif __linux__
#define CSL_CLEAR system("clear");
#endif

#include <thread>
#include <mutex>
#include <chrono>
#include <Windows.h>
#include "Snake.h"

class Game {

	//====< GAME AREA SIZE >====
	const int AreaHeight = 30, AreaWidth = 50;

	//====< SNAKE COORDINATES >=====
	int SnakeX = AreaWidth / 2, SnakeY = AreaHeight / 2;

	//====< FOOD COORDINATES >=====
	int FoodX, FoodY;

	mutable std::mutex mtx_;
	mutable uint32_t score_ = 0;

	const char SnakeHad = '*';
	const char SnakeBody = '#';
	const char Food = '@';

public:
		 Game() { FoodGenerate(); }

		 static int GetCurrentScore();

		 void FoodGenerate();

		 int MainMenu() const;

		 void DrawGameArea() const;

		 bool GameEnd() const;

		 void IncreaseScore() const;

};