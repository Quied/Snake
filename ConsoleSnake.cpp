#include <iostream>
#include "Game.h"
#include "Snake.h"
#include "Loger.h"

int main() {
	srand(time(NULL));

	while (true) {
		Game Setup;
		Loger log;

		 auto begin = std::chrono::steady_clock::now();

			switch (Setup.MainMenu()) {
			case 1:
				 begin = std::chrono::steady_clock::now();

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

			//===< GET TIME IN SECONDS AT THE GAME >===
			auto end = std::chrono::steady_clock::now();
			auto Time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		//	 log.SaveLog(42, Time);
	}
}