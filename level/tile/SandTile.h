#ifndef SANDTILE_H_
#define SANDTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class SandTile : public Tile {
public:
	SandTile(int id);
	virtual ~SandTile();
	void render(Screen * screen, Level * level, int x, int y);
	void tick(Level * level, int x, int y);
	void steppedOn(Level * level, int x, int y, Entity * entity);
	bool interact(Level * level, int x, int y, Player * player, Item * item, int attackDir);
};

#endif /* SANDTILE_H_ */
