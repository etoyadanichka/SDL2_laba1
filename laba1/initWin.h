#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include"initSDL.h"

class initWIN :public initSDL
{
private:
	
	int _width = 800, _height = 600;
	std::string _title;
	SDL_Window* _window = nullptr;
	
public:
	initWIN(const std::string &title, int width, int height);
	initWIN() {};
	~initWIN();

	void drawIMG();
	//void drawText();



protected:

	SDL_Renderer* _renderer = nullptr;
	SDL_Texture* _texture = nullptr;
	TTF_Font* _font = nullptr;

};

