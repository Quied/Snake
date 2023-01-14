#include "Input.h"

void Input::directionUpdate(State &state) {
	
	// Mutex lock ~

	while (true) {
		if (_kbhit()) {
			char move = _getch();
			switch (move) {
			case 'w': state.lastMoveDirection = 'w';
			case 'W': state.lastMoveDirection = 'W';
				break;

			case 's': state.lastMoveDirection = 's';
			case 'S': state.lastMoveDirection = 'S';
				break;

			case 'a': state.lastMoveDirection = 'a';
			case 'A': state.lastMoveDirection = 'A';
				break;

			case 'd': state.lastMoveDirection = 'd';
			case 'D': state.lastMoveDirection = 'D';
				break;

			case 77: state.lastMoveDirection = 77;  break;
			case 72: state.lastMoveDirection = 72;  break;
			case 75: state.lastMoveDirection = 75;  break;
			case 80: state.lastMoveDirection = 80;  break;
			}
		}
	}
	
}

void Input::snakeMove(State &state, Snake &snake){

	// switch (state.lastMoveDirection) {
	// case 'w':
	// case 'W':
	// 	snake.MoveUp();
	// 	break;
	// 
	// case 's':
	// case 'S':
	// 	snake.MoveDown();
	// 	break;
	// 
	// case 'a':
	// case 'A':
	// 	snake.MoveLeft();
	// 	break;
	// 
	// case 'd':
	// case 'D':
	// 	snake.MoveRight();
	// 	break;
	// 
	// case 77: snake.MoveRight(); break;
	// case 72: snake.MoveUp();    break;
	// case 75: snake.MoveLeft();  break;
	// case 80: snake.MoveDown();  break;
	// }

}