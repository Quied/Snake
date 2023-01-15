#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "State.h"
#include <ctime>

class Loger {

public:

	Loger();

	void showHistory();

	void saveScore(State&);

private:

	 std::string history_ = "history.txt";
	
	bool thereAreHistoryFile_;

};

