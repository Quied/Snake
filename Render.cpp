#include "Render.h"

void Render::drawArea(State &state, Snake &snake) {

		CONSOLE_CLEAR;
		//====< DRAW UPPER BORDERS >====
		for (int i = 0; i < this->AreaWidth; i++) {
			std::cout << "X";
		}

		std::cout << "  SCORE: " << state.score_ << " | " << state.lastMoveDirection << std::endl;

		//====< DRAW CENTRAL BORDERS AND OBJECTS >====
		for (int i = 0; i < this->AreaHeight; i++) {
			for (int j = 0; j < this->AreaWidth; j++) {
				if (j == 0 || j == this->AreaWidth - 2) std::cout << "X";



				//==< DRAW SNAKE >===
				if (i == snake.snakeY && j == snake.snakeX) {
					std::cout << snake.snakeHad;
				}

				//==< DRAW FOOD >===
				else if (i == foodY_ && j == foodX_) {
					//SetConsoleTextAttribute(WindowHandl, Colors::GREEN);
					std::cout << snake.food;
					//SetConsoleTextAttribute(WindowHandl, Colors::WHITE);
				}
				else {


					//==< DRAW TAIL >===
					bool tasilIsDraw = false;
					for (int w = 0; w < snake.currentSizeOfTail; w++) {
						if (snake.tailX[w] == j && snake.tailY[w] == i) {
							std::cout << snake.snakeBody;
							tasilIsDraw = true;
						}
					}
					if (!tasilIsDraw) std::cout << " ";
				}
			}
			std::cout << std::endl;
		}

		//====<  DRAW LOWER BORDERS >====
		for (int i = 0; i < this->AreaWidth; i++) {
			std::cout << "X";
		}
		std::cout << std::endl;

		//===< SETUP OUR TAIL >===
		int TailSavePrevMoveX = snake.tailX[0];
		int TailSavePrevMoveY = snake.tailY[0];
		int TailSavePosX, TailSavePosY;

		snake.tailX[0] = snake.snakeX;
		snake.tailY[0] = snake.snakeY;

		for (int t = 1; t < snake.currentSizeOfTail; t++) {

			//===< CURRENT POSITION >===
			TailSavePosX = snake.tailX[t];
			TailSavePosY = snake.tailY[t];

			//===< CHANGE COORDINATES OF TAIL >===
			snake.tailX[t] = TailSavePrevMoveX;
			snake.tailY[t] = TailSavePrevMoveY;

			TailSavePrevMoveX = TailSavePosX;
			TailSavePrevMoveY = TailSavePosY;
		}
}

Render::Render() {
	foodGenerate();
}

void Render::snakeTailCollision(State &state, Snake &snake) {
	for (int i = 0; i < snake.currentSizeOfTail; i++) {
		if (snake.tailX[i] == snake.snakeX && snake.tailY[i] == snake.snakeY) {
			gameEnd(state, snake);
		}
	}
}

void Render::foodFind(State &state, Snake& snake) {
	if (snake.snakeX == this->foodX_ && snake.snakeY == this->foodY_) {
		snake.eat();
		foodGenerate();
		++state.score_;
	}
}

void Render::resetData(State &state, Snake &snake) {
	state.score_ = 1;
	snake.currentSizeOfTail = 0;
	snake.snakeX = this->AreaHeight / 2;
	snake.snakeY = this->AreaWidth / 2;
	state.lastMoveDirection = 'W';
}

void Render::gameEnd(State& state, Snake &snake) {
	
	state.gameActive = false;

	CONSOLE_CLEAR;
	std::cout << "Game Over" << std::endl;
	std::cout << "Your Score: " << state.score_ << std::endl << std::endl;
	// saveLog();

	resetData(state, snake);

	state.menu();

}

void Render::gameWin(State& state, Snake& snake) {

	if (snake.snakeSize == snake.maxSnakeSize_) {

		state.gameActive = false;

		CONSOLE_CLEAR;
		std::cout << "You Win" << std::endl;
		std::cout << "Score: " << state.score_ << std::endl << std::endl;
		// saveLog();

		resetData(state, snake);
		
		state.menu();
	}
}

void Render::delayBetweenWindowUpdate(State& state) {
	std::this_thread::sleep_for(std::chrono::milliseconds(state.updateDelay));
}

void Render::checkBorders(State &state, Snake &snake) {
	if (snake.snakeX > AreaWidth - 2 || 
		snake.snakeY > AreaHeight - 1||
		snake.snakeX < 0 ||
		snake.snakeY < 0) {

		 gameEnd(state, snake);
		 gameWin(state, snake);
	}
}

void Render::foodGenerate() {
	foodY_ = rand() % AreaHeight;
	foodX_ = rand() % AreaWidth;
}

