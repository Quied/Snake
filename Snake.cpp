#include "Snake.h"

void Snake::eat() {
	++currentSizeOfTail;
	++snakeSize;
}

void Snake::moveAction(char &move) {
	
	switch (move){
	case 'w':
	case 'W':
		MoveUp();
		break;

	case 's':
	case 'S':
		MoveDown();
		break;

	case 'a':
	case 'A':
		MoveLeft();
		break;

	case 'd':
	case 'D':
		MoveRight();
		break;

	case 77: MoveRight(); break;
	case 72: MoveUp();    break;
	case 75: MoveLeft();  break;
	case 80: MoveDown();  break;
	}
}

void Snake::MoveDown() {
	++snakeY;
}

void Snake::MoveLeft() {
	snakeX--;
}

void Snake::MoveRight() {
	++snakeX;
}

void Snake::MoveUp() {
	snakeY--;
}