#include <iostream>
#include "Game.h"
#include "Snake.h"

int main() {

	while (true) {
		Game Setup;

			switch (Setup.MainMenu()) {

			case 1:
				
				while (true) {
					CSL_CLEAR;
					Setup.DrawGameArea();
				}
				break;

			case 2:

				break;

			case 3:
				return 1;
				break;

			default: 
				std::cout << "Try choise other...\n\n";
				break;
			}
	}

}