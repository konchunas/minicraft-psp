#ifndef FLOWERTILE_H_
#define FLOWERTILE_H_

#include "GrassTile.h"

class Level;
class Entity;
class Player;
class Mob;
class Screen;

class FlowerTile : public GrassTile {
public:
	FlowerTile(int id);
	virtual ~FlowerTile();
	void render(Screen * screen, Level * level, int x, int y);
	bool interact(Level * level, int x, int y, Player * player, Item * item, int attackDir);
	void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);
};

#endif /* FLOWERTILE_H_ */
