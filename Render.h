#pragma once
#include "Snake.h"
#include "State.h"
#include "mics.h"

class Render {
public:

	Render();

	void drawArea(State&, Snake&);

	void foodGenerate();

	void foodFind(State&, Snake&);

	void checkBorders(State&, Snake&);

	void gameEnd(State&, Snake&); // game over

	void gameWin(State&, Snake&);

	void resetData(State&, Snake&);

private:

	//====< GAME AREA SIZE >====
	const int AreaHeight = 30, AreaWidth = 50;

	//====< FOOD SPAWN COORDINATES >=====
	int foodX_, foodY_;

};