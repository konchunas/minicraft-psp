#ifndef CLOUDCACTUSTILE_H_
#define CLOUDCACTUSTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class CloudCactusTile : public Tile {
public:
	CloudCactusTile(int id);
	virtual ~CloudCactusTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);
	bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
	void bumpedInto(Level * level, int x, int y, Entity * entity);
private:
	void hurt(Level * level, int x, int y, int dmg);
};

#endif /* CLOUDCACTUSTILE_H_ */
