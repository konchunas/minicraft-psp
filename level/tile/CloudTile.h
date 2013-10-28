#ifndef CLOUDTILE_H_
#define CLOUDTILE_H_

//#include "../../Entity.h"
#include "Tile.h"

class Level;
class Entity;
class Screen;

class CloudTile : public Tile {
public:
	CloudTile(int id);
	virtual ~CloudTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
	
};

#endif /* CLOUDTILE_H_ */
