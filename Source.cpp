#include "State.h"
#include "Input.h"
#include "Loger.h"
#include "Render.h"
#include "Update.h"
#include "Snake.h"

int main() {
	srand(time(NULL));
	system("mode con cols=150 lines=40");

	std::vector<std::thread> threads;
	std::mutex mutex;

	 State state;
	 Input input;
	 Update update;
	 Render render;

	 Snake snake(30, 50);

	 state.menu();

	threads.emplace_back([&]() {
		std::scoped_lock lock(mutex);
		render.drawArea(state, snake);
    });

	threads.emplace_back([&]() {
		// std::scoped_lock lock(mutex);
		input.directionUpdate(state);
	});
	
	threads.emplace_back([&]() {
		std::scoped_lock lock(mutex);
		update.windowUpdate(state, render, snake);
    });


	for (auto& thread : threads)
		thread.join();

}