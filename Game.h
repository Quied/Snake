#pragma once
#ifdef _WIN32 
#define CSL_CLEAR system("cls");
#elif __linux__
#define CSL_CLEAR system("clear");
#endif

#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include <Windows.h>
#include "Snake.h"

class Game {

	//====< GAME AREA SIZE >====
	const int AreaHeight = 30, AreaWidth = 50;

	//====< CURRENT SNAKE COORDINATES >=====
	int SnakeX = AreaWidth / 2, SnakeY = AreaHeight / 2;

	//====< FOOD SPAWN COORDINATES >=====
	int FoodX, FoodY;

	//===< SNAKE TAIL >=====
	int TailX[50], TailY[50], CurrentSizeOfTail = 0;
	

	mutable std::mutex mtx_;
	// std::atomic<uint32_t> score_ { 1 };
	uint32_t score_{ 1 };
	bool GameEnd_ = false;

	const char SnakeHad = '*';
	const char SnakeBody = '#';
	const char Food = '@';


public:
		 Game();

		 int GetCurrentScore() const;

		 void Move();

		 void FoodGenerate();

		 int MainMenu() const;

		 void CheckCollision();

		 void CheckFood();

		 void RecordGameTime();

		 void DrawGameArea();

		 void GameEnd();

		 void GameWin();

		 void Eat();

		 void IncreaseScore();
};