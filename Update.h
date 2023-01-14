#pragma once
#include <thread>
#include <chrono>

#include "State.h"
#include "Render.h"
#include "Input.h"

class Update {
public: 

	void windowUpdate(State &, Render &, Snake &);


};