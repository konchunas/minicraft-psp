#include "../Color.h"
#include "Lantern.h"

Lantern::~Lantern()
{
	// TODO Auto-generated destructor stub
}

Lantern::Lantern() : Furniture("Lantern")
{
	col = Color::get(-1, 000, 111, 555);
	sprite = 5;
	xr = 3;
	yr = 2;
}

int Lantern::getLightRadius()
{
	return 8;
}

