#include "Update.h"

void Update::windowUpdate(State &state, Render &render, Snake &snake) {

	while (true) {
		if (state.gameActive) {

			render.drawArea(state, snake);
			snake.moveAction(state.lastMoveDirection);
			render.foodFind(state, snake);
			render.checkBorders(state, snake);
			render.snakeTailCollision(state, snake);
			render.delayBetweenWindowUpdate(state);

		}
	}

}