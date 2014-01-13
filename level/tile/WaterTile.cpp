/*
 * WaterTile.cpp
 *
 *  Created on: 16 окт. 2013 г.
 *      Author: user
 */

#include "WaterTile.h"

#include "../../Color.h"
#include "../Level.h"

WaterTile::~WaterTile() {
	// TODO Auto-generated destructor stub
}

WaterTile::WaterTile(int id) : Tile(id),
wRandom(new Random())
{
	connectsToSand = true;
	connectsToWater = true;
}

void WaterTile::render(Screen * screen, Level * level, int x, int y)
{
	//wRandom->setSeed((tickCount + (x / 2 - y) * 4311) / 10 * 54687121 + x * 3271612 + y * 3412987161);
	int col = Color::get(005, 005, 115, 115);
	int transitionColor1 = Color::get(3, 005, level->dirtColor - 111, level->dirtColor);
	int transitionColor2 = Color::get(3, 005, level->sandColor - 110, level->sandColor);

	bool u = !level->getTile(x, y - 1)->connectsToWater;
	bool d = !level->getTile(x, y + 1)->connectsToWater;
	bool l = !level->getTile(x - 1, y)->connectsToWater;
	bool r = !level->getTile(x + 1, y)->connectsToWater;

	bool su = u && level->getTile(x, y - 1)->connectsToSand;
	bool sd = d && level->getTile(x, y + 1)->connectsToSand;
	bool sl = l && level->getTile(x - 1, y)->connectsToSand;
	bool sr = r && level->getTile(x + 1, y)->connectsToSand;

	if (!u && !l) {
		screen->render(x * 16 + 0, y * 16 + 0, wRandom->nextInt(4), col, wRandom->nextInt(4));
	} else
		screen->render(x * 16 + 0, y * 16 + 0, (l ? 14 : 15) + (u ? 0 : 1) * 32, (su || sl) ? transitionColor2 : transitionColor1, 0);

	if (!u && !r) {
		screen->render(x * 16 + 8, y * 16 + 0, wRandom->nextInt(4), col, wRandom->nextInt(4));
	} else
		screen->render(x * 16 + 8, y * 16 + 0, (r ? 16 : 15) + (u ? 0 : 1) * 32, (su || sr) ? transitionColor2 : transitionColor1, 0);

	if (!d && !l) {
		screen->render(x * 16 + 0, y * 16 + 8, wRandom->nextInt(4), col, wRandom->nextInt(4));
	} else
		screen->render(x * 16 + 0, y * 16 + 8, (l ? 14 : 15) + (d ? 2 : 1) * 32, (sd || sl) ? transitionColor2 : transitionColor1, 0);
	if (!d && !r) {
		screen->render(x * 16 + 8, y * 16 + 8, wRandom->nextInt(4), col, wRandom->nextInt(4));
	} else
		screen->render(x * 16 + 8, y * 16 + 8, (r ? 16 : 15) + (d ? 2 : 1) * 32, (sd || sr) ? transitionColor2 : transitionColor1, 0);
}

bool WaterTile::mayPass(Level * level, int x, int y, Entity * e)
{
	return e->canSwim();
}

void WaterTile::tick(Level * level, int xt, int yt)
{
	int xn = xt;
	int yn = yt;

	if (random->nextInt(2))
		xn += random->nextInt(2) * 2 - 1;
	else
		yn += random->nextInt(2) * 2 - 1;

	if (level->getTile(xn, yn) == Tile::hole) {
		level->setTile(xn, yn, this, 0);
	}
}

