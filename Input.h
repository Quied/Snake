#pragma once
#include <vector>
#include <thread>
#include <mutex>
#include <iostream>
#include <conio.h>

#include "Snake.h"
#include "State.h"
#include "mics.h"

class Input {
public:

	void directionUpdate(State &);

	void snakeMove(State&, Snake&);

private:

	std::mutex mtx_;

};