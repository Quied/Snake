#include "Game.h"

HANDLE Window = GetStdHandle(STD_OUTPUT_HANDLE);

//===< NUMBER OF COLOR >====
enum Colors {
	BLUE = 1,
	GREEN,
	YELLOW = 6
};

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

void Game::DrawGameArea() const {

	//====<  DRAW UPPER BORDERS >====
	for (int i = 0; i < this->AreaWidth ; i++) {
		std::cout << "X";
		
	}

	//===< SCORE >===
	std::cout << "  SCORE: " << this->score_;
	std::cout << std::endl;

	//====<  DRAW CENTRAL BORDERS >====
	for (int i = 0; i < this->AreaHeight; i++) {
		for (int j = 0; j < this->AreaWidth; j++) {
			if (j == 0 || j == this->AreaWidth - 2) std::cout << "X";
			// std::cout << " ";

			//==< DRAW SNAKE >===
			 if (i == this->SnakeY && j == this->SnakeX) {
				 std::cout << this->SnakeHad;
			 }
			 else if (i == this->FoodY && j == this->FoodX) {
				 std::cout << Food;
			 }
			 else {
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

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Game::FoodGenerate() {
	FoodY = rand() % AreaHeight;
	FoodX = rand() % AreaWidth;
}