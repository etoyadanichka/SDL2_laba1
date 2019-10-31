#include"renderTEX.h"



renderTEX::renderTEX(const initWIN& window, int x, int y, int w, int h, const std::string& image_path)
	:initWIN(window), _x(x), _y(y), _w(w), _h(h)
{
	
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);

	SDL_Surface* _surface = IMG_Load(image_path.c_str());
	if (!_surface)
	{
		std::cerr << "Failed img\n ";
	}
	_texture = SDL_CreateTextureFromSurface(_renderer, _surface);
	if (!_texture)
	{
		std::cerr << "Failed texture\n ";
	}
	SDL_FreeSurface(_surface);

	SDL_Rect _rect = { _x, _y, _w, _h };

	SDL_RenderCopy(_renderer, _texture, nullptr, &_rect);
	
	_font = TTF_OpenFont("res/CharisSILR.ttf", 35);
	if (_font == NULL)
	{
		std::cerr << "Erorr with Font\n";
	}
	SDL_Color Red = { 255, 0, 0 };
	_surface = TTF_RenderUTF8_Blended(_font, u8"Родионов Даниил Александрович И983", Red);
	_texture = SDL_CreateTextureFromSurface(_renderer, _surface);
	int z, e;
	SDL_QueryTexture(_texture, NULL, NULL, &z, &e);
	//SDL_Rect dst;
	_rect.x = _x - 100;
	_rect.y = _y + 450;
	_rect.w = z;
	_rect.h = e;
	SDL_RenderCopy(_renderer, _texture, NULL, &_rect);

	SDL_FreeSurface(_surface);

	SDL_version linked;
	char buf[70];
	SDL_GetVersion(&linked);
	sprintf_s(buf, "%s %d%c%d%c%d", "SDL Version", linked.major, '.', linked.minor, '.', linked.patch);
	_surface= TTF_RenderUTF8_Blended(_font, buf, Red);
	_texture = SDL_CreateTextureFromSurface(_renderer, _surface);

	SDL_QueryTexture(_texture, NULL, NULL, &z, &e);
	//SDL_Rect dst;
	_rect.x = _x - 100;
	_rect.y = _y + 500;
	_rect.w = z;
	_rect.h = e;
	SDL_RenderCopy(_renderer, _texture, NULL, &_rect);

		/*font = TTF_OpenFont("CharisSILR.ttf", 20);
			SDL_Color White = { 0, 0, 0 };
			SDL_Surface* surfaceMessage = TTF_RenderUTF8_Blended(font, u8"Федяров Максим Анатольевич И983", White);
			SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
			renderTexture(Message, renderer, 20, 20);

			void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int w, int h) {
		SDL_Rect dst;
		dst.x = x;
		dst.y = y;
		dst.w = w;
		dst.h = h;
		SDL_RenderCopy(renderer, tex, NULL, &dst);
	}
	void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y) {
		int w, h;
		SDL_QueryTexture(tex, NULL, NULL, &w, &h);
		renderTexture(tex, renderer, x, y, w, h);
	}

			SDL_version linked;
			char buf[70];
			SDL_GetVersion(&linked);
			sprintf_s(buf, "%s %d%c%d%c%d", "SDL Version", linked.major, '.', linked.minor, '.', linked.patch);
			surfaceMessage = TTF_RenderUTF8_Blended(font, buf, White);
			Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

			renderTexture(Message, renderer, 20, 50);*/
		

	
}
/*Rect::Rect(const Window& window, int x, int y, int w, int h, const std::string& image_path):
Window(window), _x(x), _y(y), _w(w), _h(h) {
	SDL_Surface* surface = IMG_Load(image_path.c_str());

	if (!surface) {
		std::cerr << "Failed img\n ";
	}
	_texture = SDL_CreateTextureFromSurface(_renderer, surface);
	if (!_texture) {
		std::cerr << "Failed texture\n ";
	}

	SDL_FreeSurface(surface);
}
Rect::~Rect() {
	SDL_DestroyTexture(_texture);

}

void Rect::draw() {
	SDL_Rect _rect = { _x, _y, _w, _h };

	if (_texture) {
		SDL_RenderCopy(_renderer, _texture, nullptr, &_rect);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &_rect);
	}
}*/