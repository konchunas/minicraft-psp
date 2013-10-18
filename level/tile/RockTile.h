#ifndef ROCKTILE_H_
#define ROCKTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;
class Mob;
class Player;

class RockTile : public Tile {
public:
	RockTile(int id);
	virtual ~RockTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	void tick(Level * level, int xt, int yt);
	void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);
	bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
	void hurt(Level * level, int x, int y, int dmg);

};

#endif /* ROCKTILE_H_ */
