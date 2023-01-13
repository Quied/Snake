#pragma once
#include <iostream>
#include <conio.h>

enum SnakeMove {
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
};

class Snake {	
	
	int posX, posY;

	uint32_t Snake_Size = 0;
	const uint32_t Max_Snake_Size = 50;
	
public: 
	
		Snake();
		Snake(int x, int y) : posX(x), posY(y){}

		void MoveUp();

		void MoveDown();

		void MoveRight();

		void MoveLeft();
	
		void SnakeGetFood();
};