#include <iostream>
#include "Game.h"
#include "Snake.h"
#include "Loger.h"
/*
int main() {
	srand(time(NULL));

	while (true) {
		Game Setup;
		Loger log;

			switch (Setup.MainMenu()) {
			case 1:

					while (true) {
						CSL_CLEAR;
						Setup.DrawGameArea();
					}
					
				break;

			case 2:
				// Make in game end
				// Loger log;
				// log.ShowHistory();
				break;

			case 3:
				return 1;
				break;

			default: 
				std::cout << "Try choise other...\n\n";
				break;
			}

	}
}*/


int main() {
	srand(time(NULL));

	Game Setup;
	
	Setup.MainMenu();

	std::thread Render([&]() {
		while (true) {
			CSL_CLEAR
			Setup.DrawGameArea();		
		}
	});

	std::thread Control([&]() {
		while (true) {
		//	Setup.Move();
			Setup.CheckCollision();
			Setup.CheckFood();
		}
	});


	std::thread Time([&]() {
		Setup.RecordGameTime();
	});

	Time.join();
	Control.join();
	Render.join();
}

