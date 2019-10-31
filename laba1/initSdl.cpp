#include"initSdl.h"
#include <iostream>

initSDL::initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Fail with sdl init\n";
	}
	
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cerr << "Fail with img init\n";
	}

	if (TTF_Init() == -1)
	{
		std::cerr << "Fail with ttf init\n";
	}
}

void initSDL::loop() {
	
	SDL_Event event;

	while (Active) {
		if (SDL_WaitEvent(&event)) {
			if (event.type == SDL_QUIT) {
				Active = false;
			}
		/*	if (event.type == SDL_KEYDOWN) {
				Active = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				Active = false;
			}*/
		}
	}
};


initSDL::~initSDL()
{
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}



