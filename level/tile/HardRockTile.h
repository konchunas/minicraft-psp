#ifndef HARDROCKTILE_H_
#define HARDROCKTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class HardRockTile : public Tile {
public:
	HardRockTile(int id);
	virtual ~HardRockTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);
	bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
	void hurt(Level * level, int x, int y, int dmg);
	void tick(Level * level, int xt, int yt);
	
};

#endif /* HARDROCKTILE_H_ */
