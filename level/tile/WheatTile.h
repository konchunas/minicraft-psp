#ifndef WHEATTILE_H_
#define WHEATTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class WheatTile : public Tile {
public:
	WheatTile(int id);
	virtual ~WheatTile();
	void render(Screen * screen, Level * level, int x, int y);
	void tick(Level * level, int xt, int yt);
	bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
	void steppedOn(Level * level, int xt, int yt, Entity * entity);
	void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);

private:
	void harvest(Level * level, int x, int y);
	
};

#endif /* WHEATTILE_H_ */
