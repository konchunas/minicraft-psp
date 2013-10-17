#ifndef WATERTILE_H_
#define WATERTILE_H_

#include "../../Random.h"
#include "Tile.h"

class Level;
class Entity;
class Screen;

class WaterTile : public Tile {
public:
	WaterTile(int id);
	virtual ~WaterTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	void tick(Level * level, int xt, int yt);

private:
	Random * wRandom;
};

#endif /* WATERTILE_H_ */
