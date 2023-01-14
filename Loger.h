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
			CSL_CLEAR
			std::string temp;
			std::ifstream file(history_);
			std::cout << std::endl;

			std::cout << "    --- HISTORY ---" << std::endl;
				while (std::getline(file, temp)) 
					std::cout << temp << std::endl;
		
				
				std::cout << std::endl;
		}
		else {
			std::cout << "History is empty" << std::endl << std::endl;
		}
	}

	void SaveLog(int score, int seconds) {
		std::ofstream file(history_, std::fstream::app);
			
		file << "Score: "; file << score; 
		file << " Secons: "; file << seconds;
		file << std::endl;

		std::cout << "Statistic was saved" << std::endl;
	}

	void DeleteHistory();

};