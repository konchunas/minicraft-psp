#ifndef LAVATILE_H_
#define LAVATILE_H_

//#include "../../Entity.h"
#include "Tile.h"

class Level;
class Entity;
class Screen;

class LavaTile : public Tile {
public:
	LavaTile(int id);
	virtual ~LavaTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool mayPass(Level * level, int x, int y, Entity * e);
	void tick(Level * level, int xt, int yt);
	int getLightRadius(Level * level, int x, int y);
private:
	Random * wRandom;
};

#endif /* LAVATILE_H_ */
