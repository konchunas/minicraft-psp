#ifndef SAPLINGTILE_H_
#define SAPLINGTILE_H_

//#include "../../Entity.h"
#include "Tile.h"

class Level;
class Entity;
class Screen;

class SaplingTile : public Tile {
public:
	SaplingTile(int id, Tile * onType, Tile * growsTo);
	virtual ~SaplingTile();
	void render(Screen * screen, Level * level, int x, int y);
	void tick(Level * level, int xt, int yt);
	void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);
	
private:
	Tile * onType;
	Tile * growsTo;
};

#endif /* SAPLINGTILE_H_ */
