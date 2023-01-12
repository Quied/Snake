#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Loger {

	const std::string history_ = "history.txt";
	bool ThereAreHistory;

public:

	Loger() {
		std::ifstream file(history_);
		if (!file.is_open()) { ThereAreHistory = false; }
		else { ThereAreHistory = true; }
	}

	void ShowHistory() {
		if (ThereAreHistory) {
			std::string temp;
			std::ifstream file(history_);

				while (std::getline(file, temp)) 
					std::cout << temp << std::endl;
				
		}
		else {
			std::cout << "History is empty";
		}
	}
	void DeleteHistory();

};