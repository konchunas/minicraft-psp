#ifndef TREETILE_H_
#define TREETILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

#include "../../entity/ItemEntity.h"

class TreeTile : public Tile {
public:
	TreeTile(int id);
	virtual ~TreeTile();
	void render(Screen * screen, Level * level, int x, int y);
	void tick(Level * level, int xt, int yt);
	bool mayPass(Level * level, int x, int y, Entity * e);
	void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);
	bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
private:
	void hurt(Level * level, int x, int y, int dmg);
};

#endif /* TREETILE_H_ */
