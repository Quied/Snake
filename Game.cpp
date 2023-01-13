#include "Game.h"

HANDLE Window = GetStdHandle(STD_OUTPUT_HANDLE);

//===< NUMBER OF COLOR >====
enum Colors {
	BLUE = 1,
	GREEN,
	YELLOW = 6,
	WHITE,
	RED = 42
};

Game::Game() {
	FoodGenerate();
}

 int Game::MainMenu() const {
	SetConsoleTextAttribute(Window, Colors::BLUE);
	std::cout << "<===== MENU ====>" << std::endl;
	SetConsoleTextAttribute(Window, Colors::GREEN);

	std::cout << "1: Start " << std::endl;
	std::cout << "2: History " << std::endl;
	std::cout << "3: Exit " << std::endl;
	int Decide; std::cout << ": "; std::cin >> Decide;
	return Decide;

}

void Game::DrawGameArea() {
	if (GameEnd_) return;
	//====<  DRAW UPPER BORDERS >====
	for (int i = 0; i < this->AreaWidth ; i++) {
		std::cout << "X";		
	}

	//===< SCORE >===
	std::cout << "  SCORE: " << score_ << std::endl;

	//====<  DRAW CENTRAL BORDERS AND OBJECTS >====
	for (int i = 0; i < this->AreaHeight; i++) {
		for (int j = 0; j < this->AreaWidth; j++) {
			if (j == 0 || j == this->AreaWidth - 2) std::cout << "X";

				//===< SETUP OUR TAIL >===
				int TailSavePrevMoveX = TailX[0];
				int TailSavePrevMoveY = TailY[0];
				int TailSavePosX, TailSavePosY;

				TailX[0] = SnakeX;
				TailY[0] = SnakeY;

				for (int t = 1; t < CurrentSizeOfTail; t++) {
					TailSavePosX = TailX[t];
					TailSavePosY = TailY[t];

					TailX[t] = TailSavePrevMoveX;
					TailY[t] = TailSavePrevMoveY;

					TailSavePrevMoveX = TailSavePosX;
					TailSavePrevMoveY = TailSavePosY;
				}

		

			//==< SNAKE >===
			 if (i == SnakeY && j == SnakeX) {				 
				 std::cout << SnakeHad;
			 }

			 //==< FOOD >===
			 else if (i == FoodY && j == FoodX) {
				 SetConsoleTextAttribute(Window, Colors::GREEN);
				 std::cout << Food;
				 SetConsoleTextAttribute(Window, Colors::WHITE);
			 }
			 else {
				 //==< TAIL >===

				 bool tailPrint = false;

				 for (int w = 0; w < CurrentSizeOfTail; w++) {
					 if (TailX[w] == j && TailY[w] == i) {
						 // std::cout << SnakeBody;
						 std::cout << "+";
						 tailPrint = true;
					 }
				 }
				 if(!tailPrint)
					 std::cout << " ";
			 }
			
		}
		std::cout << std::endl;
	}

	//====<  DRAW LOWER BORDERS >====
	for (int i = 0; i < this->AreaWidth; i++) {
		std::cout << "X";
	}
	std::cout << std::endl;

	//===< DELAY BETWEEN AREA UPDATES >====
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Game::Move() {
	//===< PUSH BUTTON >===
	if (_kbhit()) {
		char move = _getch();
			switch (move) {
				case 'w':
					SnakeY--;
					break;

				case 's':
					SnakeY++;
					break;

				case 'a':
					SnakeX--;
					break;

				case 'd':
					SnakeX++;
					break;

				case 77:  // right
					SnakeX++;
						break;

				case 72: // up
					SnakeY--;
					break;

				case 75: // left
					SnakeX--;
					break;

				case 80: // down
					SnakeY++;
					break;
			}
	}
}

void Game::CheckCollision() {
	 if (SnakeX > AreaWidth - 2 || SnakeY > AreaHeight - 1 || SnakeX < 0 || SnakeY < 0) {
	 	GameEnd();
	 }
}

void Game::GameEnd() {
	mtx_.lock();
	GameEnd_ = true;
	SetConsoleTextAttribute(Window, Colors::RED);
	std::cout << " =====< GAME IS END >=====" << std::endl;
	SetConsoleTextAttribute(Window, Colors::YELLOW);
	std::cout << "Your score: " << score_ << std::endl;;

	mtx_.unlock();
	
}

void Game::CheckFood() {
	if (SnakeX == FoodX && SnakeY == FoodY) {
		Eat();
	}
}

void Game::Eat() {
	FoodGenerate();
	IncreaseScore();
}

void Game::IncreaseScore() {
	++score_;
}

int Game::GetCurrentScore() const {
	return score_;
}

void Game::FoodGenerate() {
	FoodY = rand() % AreaHeight;
	FoodX = rand() % AreaWidth;
}