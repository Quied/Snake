#include "Game.h"

HANDLE Window = GetStdHandle(STD_OUTPUT_HANDLE);


enum Colors {
	BLUE = 1,
	GREEN,
	YELLOW = 6,
	WHITE,
	RED = 42
};

enum Menu {
	START = 1,
	HISTORY, 
	EXIT
};

Game::Game() {
	FoodGenerate();
}

 void Game::MainMenu() {

	SetConsoleTextAttribute(Window, Colors::BLUE);
	std::cout << "<===== MENU ====>" << std::endl;
	SetConsoleTextAttribute(Window, Colors::GREEN);

	std::cout << "1: Start " << std::endl;
	std::cout << "2: History " << std::endl;
	std::cout << "3: Exit " << std::endl;
	int Decide; std::cout << ": "; std::cin >> Decide;


	switch (Decide) {
	case Menu::START:
		MenuIsActive = false;
		break;


	case Menu::HISTORY:
		log.ShowHistory();

		MainMenu();
		break;

	case Menu::EXIT:
		exit(0);
		break;
	}

}

void Game::DrawGameArea() {
	if (!MenuIsActive) {
		Move();

		//====< DRAW UPPER BORDERS >====
		for (int i = 0; i < this->AreaWidth; i++) {
			std::cout << "X";
		}

		std::cout << "  SCORE: " << score_ << std::endl;

		//====< DRAW CENTRAL BORDERS AND OBJECTS >====
		for (int i = 0; i < this->AreaHeight; i++) {
			for (int j = 0; j < this->AreaWidth; j++) {
				if (j == 0 || j == this->AreaWidth - 2) std::cout << "X";


				if (score_ >= 5) UpdateDelay -= 200;

				//==< DRAW SNAKE >===
				if (i == SnakeY && j == SnakeX) {
					std::cout << SnakeHad;
				}

				//==< DRAW FOOD >===
				else if (i == FoodY && j == FoodX) {
					SetConsoleTextAttribute(Window, Colors::GREEN);
					std::cout << Food;
					SetConsoleTextAttribute(Window, Colors::WHITE);
				}
				else {


					//==< DRAW TAIL >===
					bool tailPrint = false;
					for (int w = 0; w < CurrentSizeOfTail; w++) {
						if (TailX[w] == j && TailY[w] == i) {
							std::cout << SnakeBody;
							tailPrint = true;
						}
					}
					if (!tailPrint)
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

		//===< SETUP OUR TAIL >===
		int TailSavePrevMoveX = TailX[0];
		int TailSavePrevMoveY = TailY[0];
		int TailSavePosX, TailSavePosY;

		TailX[0] = SnakeX;
		TailY[0] = SnakeY;

		for (int t = 1; t < CurrentSizeOfTail; t++) {

			//===< CURRENT POSITION >===
			TailSavePosX = TailX[t];
			TailSavePosY = TailY[t];

			//===< CHANGE COORDINATES OF TAIL >===
			TailX[t] = TailSavePrevMoveX;
			TailY[t] = TailSavePrevMoveY;

			TailSavePrevMoveX = TailSavePosX;
			TailSavePrevMoveY = TailSavePosY;
			//TailSavePrevMoveX = TailX[t];
			//TailSavePrevMoveY = TailY[t];
		}

		//===< DELAY BETWEEN AREA UPDATES >====
		std::this_thread::sleep_for(std::chrono::milliseconds(UpdateDelay));
	}
}

void Game::Move() {

	//===< BUTTONS FOR SNAKE MOVE >===
	//==< REMEMBER OUR CHOISE AND GO IN IT DIRECTION >===
	if (_kbhit()) {
		char move = _getch();
			switch (move) {
				case 'w': LastSnakeMove = 'w';
				case 'W': LastSnakeMove = 'W';
			 break;

				case 's': LastSnakeMove = 's';
				case 'S': LastSnakeMove = 'S';
		  	 break;
 
				case 'a': LastSnakeMove = 'a';
				case 'A': LastSnakeMove = 'A';
			 break;

				case 'd': LastSnakeMove = 'd';
				case 'D': LastSnakeMove = 'D';	
			break;

				case 77: LastSnakeMove = 77;  break;
				case 72: LastSnakeMove = 72;  break;
				case 75: LastSnakeMove = 75;  break;
				case 80: LastSnakeMove = 80;  break;
			}
	}

	//===< MOVE >====
	switch (LastSnakeMove) {
	case 'w':
		case 'W':
			SnakeY--;
			break;

	case 's':
		case 'S':
			SnakeY++;
		break;

	case 'a': 
		case 'A': 
			SnakeX--;
		break;

	case 'd':
		case 'D':
			SnakeX++;
		break;

		case 77: // right
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

void Game::CheckCollision() {
	 if (SnakeX > AreaWidth - 2 || SnakeY > AreaHeight - 1 || SnakeX < 0 || SnakeY < 0) {
		 // int Time = RecordGameTime();
		 // log.SaveLog(score_, Time);
	 	GameEnd();
	 }
}

void Game::GameWin() {
	mtx_.lock();

	// GameEnd_ = true; ?
	MenuIsActive = true;
	SetConsoleTextAttribute(Window, Colors::GREEN);
	std::cout << " =====< YOU WIN >=====" << std::endl;
	SetConsoleTextAttribute(Window, Colors::YELLOW);
	std::cout << "Your score: " << score_ << std::endl;;


	MainMenu();
	mtx_.unlock();
}

void Game::RecordGameTime() {
	auto Begin = std::chrono::steady_clock::now();

	{
		while (true) {
			if (GameEnd_) {
				auto End = std::chrono::steady_clock::now();
				auto TotalTime = std::chrono::duration_cast<std::chrono::seconds>(Begin - End);
				std::cout << "Second: " << TotalTime.count();
				return;
			}
		}
	}
}

void Game::GameEnd() {
	mtx_.lock();

	// GameEnd_ = true;
	MenuIsActive = true;
	SetConsoleTextAttribute(Window, Colors::RED);
	std::cout << " =====< GAME IS END >=====" << std::endl;
	SetConsoleTextAttribute(Window, Colors::YELLOW);
	std::cout << "Your score: " << score_ << std::endl;;

	
	MainMenu();
	mtx_.unlock();
}

void Game::CheckFood() {
	if (SnakeX == FoodX && SnakeY == FoodY) {
		Eat();
	}
}

void Game::Eat() {
	++CurrentSizeOfTail;
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