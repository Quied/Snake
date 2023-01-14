#include "State.h"

void State::menu() {
	std::cout << "<===== MENU ====>" << std::endl << std::endl;
	std::cout << "1: Start " << std::endl;
	std::cout << "2: History " << std::endl;
	std::cout << "3: Exit " << std::endl;
	int Decide; std::cout << ": "; std::cin >> Decide;


	switch (Decide) {
	case GameMenu::START:

		CONSOLE_CLEAR;
		gameActive = true;

		break;

	case GameMenu::HISTORY:

		CONSOLE_CLEAR;
	//	loger.showHistory();
		menu();

		break;

	case GameMenu::EXIT:

		exit(0);

		break;
	}
}