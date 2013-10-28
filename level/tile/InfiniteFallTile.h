#ifndef INFINITEFALLTILE_H_
#define INFINITEFALLTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class InfiniteFallTile : public Tile {
public:
	InfiniteFallTile(int id);
	virtual ~InfiniteFallTile();

	void render(Screen * screen, Level * level, int x, int y);
	void tick(Level * level, int xt, int yt);
	bool mayPass(Level * level, int x, int y, Entity * e);
};

#endif /* INFINITEFALLTILE_H_ */
