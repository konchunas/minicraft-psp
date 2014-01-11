#ifndef ENTITY_H_
#define ENTITY_H_

#include "level/tile/Tile.h"
#include "Screen.h"
#include "../Typeable.h"

class Level;
class Mob;
class Player;
class Item;
class ItemEntity;

class Entity : public Typeable {
public:
	Entity();
	virtual ~Entity();
	int x, y;
	int xr;
	int yr;
	bool removed;
	Level * level;

	virtual void render(Screen * screen);
	virtual void tick();
	virtual void remove();
	virtual void init(Level * level);
	virtual bool intersects(int x0, int y0, int x1, int y1);
	virtual bool blocks(Entity * e);
	virtual void hurt(Tile * tile, int x, int y, int dmg);
	virtual void hurt(Mob * mob, int dmg, int attackDir);
	virtual bool move(int xa, int ya);
	virtual bool canSwim();
	virtual int getLightRadius();
	virtual bool isBlockableBy(Mob * mob);
	virtual bool use(Player * player, int attackDir);
	virtual bool interact(Player * player, Item * item, int attackDir);
	virtual void touchItem(ItemEntity * itemEntity);
	//this was protected in java
	virtual void touchedBy(Entity * entity);

protected:
	static Random * random;
	virtual bool move2(int xa, int ya);
};

#endif /* ENTITY_H_ */
