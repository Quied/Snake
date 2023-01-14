#pragma once
#include <iostream>
<<<<<<< HEAD
#include <conio.h>
#include <thread>
#include <chrono>
=======
>>>>>>> abb268d (First with update)

enum SnakeMove {
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
};


<<<<<<< HEAD

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
=======
class Snake {
public:

	Snake();
	Snake(int areaHeight, int areaWidth) :  snakeX(areaHeight / 2), snakeY(areaWidth / 2){}

	void MoveUp();

	void MoveDown();

	void MoveRight();

	void MoveLeft();

	void eat();

	void moveAction(char&);

	const char snakeHad = '*';
	const char snakeBody = '#';
	const char food = '@';

	int tailX[50], tailY[50], currentSizeOfTail = 0;

	int snakeX, snakeY;
	
	uint32_t snakeSize = 0;
	const uint32_t maxSnakeSize_ = 50;
>>>>>>> abb268d (First with update)

};