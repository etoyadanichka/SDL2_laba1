#pragma once
#include "initWin.h"

class renderTEX : public initWIN
{
public:
	renderTEX(const initWIN& window, int x, int y, int w, int h, const std::string& image_path);
private:
	int _x, _y;
	int _w, _h;
};
