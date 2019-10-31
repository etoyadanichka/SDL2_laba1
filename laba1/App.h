#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include"initSdl.h"
#include"initWin.h"
#include"renderTEX.h"


class App {
public:
	App() {
		initWIN window("LABA NUMBER 1", 800, 600);
		renderTEX tex(window, 175, 20, 400, 400, "res/1.png");
		window.drawIMG();
		window.loop();
	}
};