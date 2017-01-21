#include "SDL2/SDL.h"
#include "SDLUtils.hh"
#include "Constants.hh"
#include <iostream>

int main() {

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *tex;
	bool quit;
	SDL_Event event;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		logSDLError(std::cout, "SDL_Init");
		return 1;
	}

	window = SDL_CreateWindow("Lesson 2", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		logSDLError(std::cout, "CreateRenderer");
		cleanup(window);
		SDL_Quit();
		return 1;
	}

	if ((tex = loadTexture("resources/bmp/square300.bmp", renderer)) == nullptr)
	{
		return 1;
	}

	// MainLoop
	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				quit = true;
				break;
		}

		//First clear the renderer
		SDL_RenderClear(renderer);
		//Draw the texture
		renderTexture(tex, renderer);
		//Update the screen
		SDL_RenderPresent(renderer);
	}

	//Cleanup
	cleanup(window, renderer, tex);
}