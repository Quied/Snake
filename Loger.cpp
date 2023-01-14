#include "Loger.h"

Loger::Loger() {
	std::ifstream file(history_);
	if (!file.is_open()) { thereAreHistoryFile_ = false; }
	else { thereAreHistoryFile_ = true; }
}

void Loger::showHistory() {
	if (thereAreHistoryFile_) {

		std::string temp;
		std::ifstream file(history_);
		std::cout << std::endl;

		std::cout << "    --- HISTORY ---" << std::endl;
		while (std::getline(file, temp))
			std::cout << temp << std::endl;


		std::cout << std::endl;
	}
	else { std::cout << "History is empty" << std::endl << std::endl; }
}