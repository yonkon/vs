#include "Figure.h"


Figure::Figure(int _x, int _y, int _type, int _color)
{
	x = _x;
	y = _y;
	color = _color;
	type = _type;
}

Figure::Figure(Figure^ f) {
	x = f->x;
	y = f->y;
	color = f->color;
	type = f->type;
}