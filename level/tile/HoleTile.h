#ifndef HOLETILE_H_
#define HOLETILE_H_

//#include "../../Entity.h"
#include "Tile.h"

class Level;
class Entity;
class Screen;

class HoleTile : public Tile {
public:
	HoleTile(int id);
	virtual ~HoleTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	
};

#endif /* HOLETILE_H_ */
