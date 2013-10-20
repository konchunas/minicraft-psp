#ifndef FARMTILE_H_
#define FARMTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class FarmTile : public Tile {
public:
	FarmTile(int id);
	virtual ~FarmTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
	void tick(Level * level, int xt, int yt);
	void steppedOn(Level * level, int xt, int yt, Entity * entity);
	
};

#endif /* FARMTILE_H_ */
