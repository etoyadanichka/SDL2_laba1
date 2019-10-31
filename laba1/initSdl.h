#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class initSDL {
public:
	initSDL();
	~initSDL();

	void loop();
private:
		bool Active = true;
		/*some changes init sdl*/
};


