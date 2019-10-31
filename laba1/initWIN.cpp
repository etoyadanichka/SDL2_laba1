#include"initWin.h"
#include<string>
initWIN::initWIN(const std::string& title, int width, int height) :
	_title(title),_width(width), _height(height)
{
	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);
	if (_window == nullptr)
	{
		std::cerr << "Fail with window init\n";
	}

	_renderer = SDL_CreateRenderer(_window, -1, 0);
	if (_renderer == nullptr)
	{
		std::cerr << "Fail with renderer init\n";
	}

}

initWIN::~initWIN()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}

void initWIN::drawIMG()
{
	
	SDL_RenderPresent(_renderer);
}
