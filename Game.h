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

#include "Loger.h"

class Game {

public:
	Game();

	int GetCurrentScore() const;

	void Move();

	void FoodGenerate();

	void MainMenu();

	void CheckCollision();

	void CheckFood();

	void RecordGameTime();

	void DrawGameArea();

	void GameEnd();

	void GameWin();

	void Eat();

	void IncreaseScore();


private:

	Loger log;

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
	uint32_t UpdateDelay{ 400 };


	// bool GameEnd_ = false;
	bool GameEnd_ = true;
	bool MenuIsActive = true;

	char LastSnakeMove;

	const char SnakeHad = '*';
	const char SnakeBody = '#';
	const char Food = '@';

};