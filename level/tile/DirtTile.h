#ifndef DIRTTILE_H_
#define DIRTTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class DirtTile : public Tile {
public:
	DirtTile(int id);
	virtual ~DirtTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool interact(Level * level, int x, int y, Player * player, Item * item, int attackDir);
};

#endif /* DIRTTILE_H_ */
