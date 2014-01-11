#ifndef TILE_H_
#define TILE_H_

#include "../../Random.h"

class Level;
class Entity;
class Screen;
class Mob;
class Player;
class Item;

typedef unsigned short ushort;

class Tile {
public:
	Tile(int id);
	virtual ~Tile();

	static Tile **tiles;
	static int tickCount;
	static Tile * rock;
	static Tile * grass;
	static Tile * water;
	static Tile * flower;
	static Tile * tree;
	static Tile * dirt;
	static Tile * sand;
	static Tile * cactus;
	static Tile * hole;
	static Tile * treeSapling;
	static Tile * cactusSapling;
	static Tile * farmland;
	static Tile * wheat;
	static Tile * lava;
	static Tile * stairsDown;
	static Tile * stairsUp;
	static Tile * infiniteFall;
	static Tile * cloud;
	static Tile * hardRock;
	static Tile * ironOre;
	static Tile * goldOre;
	static Tile * gemOre;
	static Tile * cloudCactus;

	bool connectsToGrass;
	bool connectsToSand;
	bool connectsToLava;
	bool connectsToWater;

	ushort id;

	static void init();
	virtual void render(Screen * screen, Level * level, int x, int y);
	virtual bool mayPass(Level * level, int x, int y, Entity * e);
	virtual int getLightRadius(Level * level, int x, int y);
	virtual void hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir);
	virtual void bumpedInto(Level * level, int xt, int yt, Entity * entity);
	virtual void tick(Level * level, int xt, int yt);
	virtual void steppedOn(Level * level, int xt, int yt, Entity * entity);
	virtual bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
	virtual bool use(Level * level, int xt, int yt, Player * player, int attackDir);
	virtual bool connectsToLiquid();

protected:
	static Random * random;

};

#endif /* TILE_H_ */
