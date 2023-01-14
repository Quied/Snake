#pragma once
#include <iostream>
#include <fstream>
#include <string>
// #include "mics.h"
#include <ctime>

class Loger {

public:

	Loger();

	void showHistory();


private:
	const std::string history_ = "history.txt";
	bool thereAreHistoryFile_;

};