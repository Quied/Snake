#pragma once
#include <iostream>
#include "mics.h"
#include "Loger.h"

// Loger loger; 

class State {

public:
	
	void menu();

	uint32_t updateDelay = { 220 }; // milliseconds
	uint32_t score_ { 1 };

	bool gameActive = false;
	char lastMoveDirection = 'w';

};