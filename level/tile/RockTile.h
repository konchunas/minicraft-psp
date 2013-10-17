#ifndef ROCKTILE_H_
#define ROCKTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class RockTile : public Tile {
public:
	RockTile(int id);
	virtual ~RockTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	void tick(Level * level, int xt, int yt);
};

#endif /* ROCKTILE_H_ */
