/*
 * Level.h
 *
 *  Created on: 16 окт. 2013 г.
 *      Author: user
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "../entity/Entity.h"
#include "../Screen.h"
#include <list>

using namespace std;

typedef unsigned short ushort;

class Player;

class Level {
public:
	Level(int w, int h, int level, Level * parentLevel);
	virtual ~Level();
	int w, h;

	ushort * tiles;
	ushort * data;
	list<Entity*> * entitiesInTiles;

	Player * player;

	int grassColor;
	int dirtColor;
	int sandColor;
	int monsterDensity;
	list<Entity*> entities;

	void renderBackground(Screen * screen, int xScroll, int yScroll);
	void renderSprites(Screen * screen, int xScroll, int yScroll);
	void renderLight(Screen * screen, int xScroll, int yScroll);
	Tile * getTile(int x, int y);
	void setTile(int x, int y, Tile * t, int dataVal);
	int getData(int x, int y);
	void setData(int x, int y, int val);
	void add(Entity * entity);
	void remove(Entity * e);
	void trySpawn(int count);
	void tick();
	list<Entity*> getEntities(int x0, int y0, int x1, int y1);

private:
	int depth;
	Random * random;
	list<Entity*> rowSprites;

	//void sortAndRender(Screen screen, List<Entity> list);
	void insertEntity(int x, int y, Entity * e);
	void removeEntity(int x, int y, Entity * e);
};

#endif /* LEVEL_H_ */
