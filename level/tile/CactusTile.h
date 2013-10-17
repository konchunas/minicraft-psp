#ifndef CACTUSTILE_H_
#define CACTUSTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class CactusTile : public Tile {
public:
	CactusTile(int id);
	virtual ~CactusTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);
	void bumpedInto(Level * level, int x, int y, Entity * entity);
	void tick(Level * level, int xt, int yt);
};

#endif /* CACTUSTILE_H_ */
