#ifndef LEVEL_H_
#define LEVEL_H_

#include "../entity/Entity.h"
#include "../Screen.h"
#include <list>

using namespace std;

typedef unsigned char byte;

class Player;

class Level {
public:
	Level(int w, int h, int level, Level * parentLevel);
	virtual ~Level();
	int w, h;

	byte * tiles;
	byte * data;

	Player * player;

	int grassColor;
	int dirtColor;
	int sandColor;
	int monsterDensity;

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
	list<Entity*> * getEntities(int x0, int y0, int x1, int y1);
	list<Entity*> * getEntities(int x0, int y0);
	list<Entity*> * getEntities(int x0, int y0, int x1, int y1, Entity * exclude);
	bool isRegionEmpty(int x0, int y0, int x1, int y1);

private:
	int depth;
	Random * random;
	list<Entity*> rowSprites;

	list<Entity*> entities;
	list<Entity*> * entitiesInTiles;

	//void sortAndRender(Screen screen, List<Entity> list);
	void insertEntity(int x, int y, Entity * e);
	void removeEntity(int x, int y, Entity * e);
};

#endif /* LEVEL_H_ */
