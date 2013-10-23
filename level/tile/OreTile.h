#ifndef ORETILE_H_
#define ORETILE_H_

#include "Tile.h"

#include "../../item/resource/Resource.h"

class Level;
class Entity;
class Screen;

class OreTile : public Tile {
public:
	OreTile(int id, Resource * toDrop);
	virtual ~OreTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);
	bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
	void hurt(Level * level, int x, int y, int dmg);
	void bumpedInto(Level * level, int x, int y, Entity * entity);
private:
	Resource * toDrop;
	int color;
	
};

#endif /* ORETILE_H_ */
