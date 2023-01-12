#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Loger {

	const std::string history_ = "history.txt";
	bool ThereAreHistory_;

public:

	Loger() {
		std::ifstream file(history_);
		if (!file.is_open()) { ThereAreHistory_ = false; }
		else { ThereAreHistory_ = true; }
	}

	void ShowHistory() {
		if (ThereAreHistory_) {
			std::string temp;
			std::ifstream file(history_);

				while (std::getline(file, temp)) 
					std::cout << temp << std::endl;
				
		}
		else {
			std::cout << "History is empty";
		}
	}

	void SaveLog(int score, int seconds) {
		std::ofstream file(history_, std::fstream::app);
			
		file << "Score: "; file << score; 
		file << " Secons: "; file << seconds;
		file << std::endl;

		std::cout << "Log was saved" << std::endl;
	}

	void DeleteHistory();

};