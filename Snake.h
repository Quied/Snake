#pragma once
#include <iostream>

enum SnakeMove {
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
};


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

};