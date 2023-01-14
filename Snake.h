#pragma once
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

enum SnakeMove {
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
};



class Snake {		
public: 
	
		Snake();
		Snake(int x, int y) : SnakeX(x), SnakeY(y){}

		void DirectionMove();

		void MoveUp(int &);

		void MoveDown(int &);

		void MoveRight(int &);

		void MoveLeft(int &);
	
		void SnakeGetFood();

private:

	//===< SNAKE TAIL >=====
	int TailX[50], TailY[50], CurrentSizeOfTail = 0;

	//====< CURRENT SNAKE COORDINATES >=====
//	int SnakeX = AreaWidth / 2, SnakeY = AreaHeight / 2;
	int SnakeX, SnakeY;

	char LastSnakeMove;

	const char SnakeHad = '*';
	const char SnakeBody = '#';
	const char Food = '@';

	uint32_t Snake_Size = 0;
	const uint32_t Max_Snake_Size = 50;

};