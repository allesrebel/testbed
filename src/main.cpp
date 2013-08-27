#include <SDL2/SDL.h>
#include <cstdlib>

//simple event, wait for key press to continue with test
void waitForPress() {
	bool done = false;
	while (!done) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				done = true;
			} else if (event.type == SDL_QUIT) {
				exit(0);
			}
		}
	}
}

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_VIDEO);   // Initialize SDL2

	SDL_Window* mainWin = SDL_CreateWindow("My Simple Window",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 680, 460, 0);
	waitForPress();

	SDL_DestroyWindow(mainWin);
	SDL_Quit();
	return 0;
}
