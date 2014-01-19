/*
 * Level.cpp
 *
 *  Created on: 16 окт. 2013 г.
 *      Author: user
 */

#include <stdlib.h>

#include "Level.h"
#include "LevelGen.h"
#include "tile/Tile.h"
#include "../entity/Player.h"
#include "../entity/Slime.h"
#include "../entity/Zombie.h"
#include "../entity/AirWizard.h"
#include <oslib/oslib.h>

Level::~Level()
{
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++ )
	{
		delete *it;
	}

	delete[] entitiesInTiles;
	delete[] tiles;
	delete[] data;
	delete random;
}

//	private Comparator<Entity> spriteSorter = new Comparator<Entity>() {
//		public int compare(Entity e0, Entity e1) {
//			if (e1.y < e0.y) return +1;
//			if (e1.y > e0.y) return -1;
//			return 0;
//		}


Level::Level(int w, int h, int level, Level * parentLevel) :
grassColor(141),
dirtColor(322),
sandColor(550),
player(NULL),
monsterDensity(8),
random(new Random())
{
	if (level < 0) {
		dirtColor = 222;
	}
	this->depth = level;
	this->w = w;
	this->h = h;
	byte ** maps;

	if (level == 1) {
		dirtColor = 444;
	}

	if (level == 0)
	{
		maps = LevelGen::createAndValidateTopMap(w, h);
	}
	else if (level < 0)
	{
		maps = LevelGen::createAndValidateUndergroundMap(w, h, -level);
		monsterDensity = 4;
	}
	else
	{
		maps = LevelGen::createAndValidateSkyMap(w, h); // Sky level
		monsterDensity = 4;
	}
	tiles = maps[0];
	data = maps[1];

	if (parentLevel != NULL) {
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				if (parentLevel->getTile(x, y) == Tile::stairsDown)
				{
					setTile(x, y, Tile::stairsUp, 0);
					if (level == 0) {
						setTile(x - 1, y, Tile::hardRock, 0);
						setTile(x + 1, y, Tile::hardRock, 0);
						setTile(x, y - 1, Tile::hardRock, 0);
						setTile(x, y + 1, Tile::hardRock, 0);
						setTile(x - 1, y - 1, Tile::hardRock, 0);
						setTile(x - 1, y + 1, Tile::hardRock, 0);
						setTile(x + 1, y - 1, Tile::hardRock, 0);
						setTile(x + 1, y + 1, Tile::hardRock, 0);
					} else {
						setTile(x - 1, y, Tile::dirt, 0);
						setTile(x + 1, y, Tile::dirt, 0);
						setTile(x, y - 1, Tile::dirt, 0);
						setTile(x, y + 1, Tile::dirt, 0);
						setTile(x - 1, y - 1, Tile::dirt, 0);
						setTile(x - 1, y + 1, Tile::dirt, 0);
						setTile(x + 1, y - 1, Tile::dirt, 0);
						setTile(x + 1, y + 1, Tile::dirt, 0);
					}
				}

			}
	}

	//secret place at the top left of the lowest level
	if (level == -3)
	{
		setTile(1, 1, Tile::water, 0);
		setTile(1, 2, Tile::water, 0);
		setTile(1, 3, Tile::water, 0);
		setTile(1, 4, Tile::water, 0);
		setTile(1, 5, Tile::water, 0);
		setTile(1, 6, Tile::water, 0);

		setTile(2, 1, Tile::water, 0);
		setTile(2, 2, Tile::grass, 0);
		setTile(2, 3, Tile::grass, 0);
		setTile(2, 4, Tile::tree, 0);
		setTile(2, 5, Tile::tree, 0);
		setTile(2, 6, Tile::water, 0);

		setTile(3, 1, Tile::water, 0);
		setTile(3, 2, Tile::grass, 0);
		setTile(3, 3, Tile::grass, 0);
		setTile(3, 4, Tile::grass, 0);
		setTile(3, 5, Tile::tree, 0);
		setTile(3, 6, Tile::tree, 0);

		setTile(4, 1, Tile::water, 0);
		setTile(4, 2, Tile::cactus, 0);
		setTile(4, 3, Tile::grass, 0);
		setTile(4, 4, Tile::grass, 0);
		setTile(4, 5, Tile::grass, 0);
		setTile(4, 6, Tile::tree, 0);

		setTile(5, 1, Tile::lava, 0);
		setTile(5, 2, Tile::sand, 0);
		setTile(5, 3, Tile::sand, 0);
		setTile(5, 4, Tile::farmland, 0);
		setTile(5, 5, Tile::wheat, 0);
		setTile(5, 6, Tile::wheat, 0);

		setTile(6, 1, Tile::lava, 0);
		setTile(6, 2, Tile::sand, 0);
		setTile(6, 3, Tile::sand, 0);
		setTile(6, 4, Tile::sand, 0);
		setTile(6, 5, Tile::sand, 0);
		setTile(6, 5, Tile::dirt, 0);
		setTile(6, 6, Tile::cloudCactus, 0);

		setTile(7, 1, Tile::lava, 0);
		setTile(7, 2, Tile::lava, 0);
		setTile(7, 3, Tile::ironOre, 0);
		setTile(7, 4, Tile::dirt, 0);
		setTile(7, 5, Tile::dirt, 0);
		setTile(7, 6, Tile::cloud, 0);

		setTile(8, 1, Tile::gemOre, 0);
		setTile(8, 2, Tile::lava, 0);
		setTile(8, 3, Tile::lava, 0);
		setTile(8, 4, Tile::goldOre, 0);

		setTile(8, 6, Tile::cloud, 0);

		setTile(9, 2, Tile::gemOre, 0);
		setTile(9, 3, Tile::lava, 0);
		setTile(9, 4, Tile::lava, 0);

		setTile(10, 2, Tile::gemOre, 0);
		setTile(10, 4, Tile::lava, 0);
		setTile(10, 5, Tile::lava, 0);

		setTile(11, 5, Tile::lava, 0);
	}

	entitiesInTiles = new list<Entity*>[w * h];
	//for (int i = 0; i < w * h; i++)
	//{
	//	entitiesInTiles[i] = new list<Entity*>;
	//}

	if (level == 1)
	{
		AirWizard * aw = new AirWizard();
		aw->x = w*8;
		aw->y = h*8;
		add(aw);
	}

}

	void Level::renderBackground(Screen * screen, int xScroll, int yScroll)
	{
		int xo = xScroll >> 4;
		int yo = yScroll >> 4;
		int w = (screen->w + 15) >> 4;
		int h = (screen->h + 15) >> 4;
		screen->setOffset(xScroll, yScroll);
		for (int y = yo; y <= h + yo; ++y)
		{
			for (int x = xo; x <= w + xo; ++x)
			{
				getTile(x, y)->render(screen, this, x, y);
			}
		}
		screen->setOffset(0, 0);
	}

	void Level::renderSprites(Screen * screen, int xScroll, int yScroll) {
		int xo = xScroll >> 4;
		int yo = yScroll >> 4;
		int w = (screen->w + 15) >> 4;
		int h = (screen->h + 15) >> 4;

		screen->setOffset(xScroll, yScroll);
		for (int y = yo; y <= h + yo; ++y)
		{
			if (y < 0 || y >= this->h) continue;
			for (int x = xo; x <= w + xo; ++x)
			{
				if (x < 0 || x >= this->w) continue;
				//rowSprites.splice(rowSprites.end(),entitiesInTiles[x + y * this->w]);
				list<Entity*> &ent = entitiesInTiles[x + y * this->w];
				if (!ent.empty())
				{
					for (list<Entity*>::iterator it = ent.begin(); it != ent.end(); it++ )
					{
						Entity * e = *it;
						e->render(screen);
					}
				}
			}
//			for (list<Entity*>::iterator it = rowSprites.begin(); it != rowSprites.end(); it++ )
//			{
//				Entity * e = *it;
//				e->render(screen);
//			}
			//if (rowSprites.size() > 0) {
			//	sortAndRender(screen, rowSprites);
			//}
			rowSprites.clear();
		}
		screen->setOffset(0, 0);
	}

	void Level::renderLight(Screen * screen, int xScroll, int yScroll) {
		int xo = xScroll >> 4;
		int yo = yScroll >> 4;
		int w = (screen->w + 15) >> 4;
		int h = (screen->h + 15) >> 4;

		screen->setOffset(xScroll, yScroll);
		int r = 4;
		for (int y = yo - r; y <= h + yo + r; y++) {
			for (int x = xo - r; x <= w + xo + r; x++) {
				if (x < 0 || y < 0 || x >= this->w || y >= this->h) continue;
				list<Entity*> &entities = entitiesInTiles[x + y * this->w];
				for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++ )
				{
					Entity * e = *it;
					//Entity * e = entities.at(i);
					// e.render(screen);
					int lr = e->getLightRadius();
					if (lr > 0) screen->renderLight(e->x - 1, e->y - 4, lr * 8);
				}
				int lr = getTile(x, y)->getLightRadius(this, x, y);
				if (lr > 0) screen->renderLight(x * 16 + 8, y * 16 + 8, lr * 8);
			}
		}
		screen->setOffset(0, 0);
	}

//void renderLight(Screen * screen, int x, int y, int r)
//{
//	screen->renderLight(x, y, r);
//}

//	void Level::sortAndRender(Screen * screen, List<Entity> list) {
//		Collections.sort(list, spriteSorter);
//		for (int i = 0; i < list.size(); i++) {
//			list.get(i).render(screen);
//		}
//	}

Tile * Level::getTile(int x, int y)
{
	if (x < 0 || y < 0 || x >= w || y >= h) return Tile::rock;
	return Tile::tiles[tiles[x + y * w]];
}

void Level::setTile(int x, int y, Tile * t, int dataVal)
{
	if (x < 0 || y < 0 || x >= w || y >= h) return;
	tiles[x + y * w] = t->id;
	data[x + y * w] = (byte) dataVal;
}

int Level::getData(int x, int y)
{
	if (x < 0 || y < 0 || x >= w || y >= h) return 0;
	return data[x + y * w] & 0xff;
}

void Level::setData(int x, int y, int val)
{
	if (x < 0 || y < 0 || x >= w || y >= h) return;
	data[x + y * w] = (byte) val;
}

void Level::add(Entity * entity)
{
	if (entity->instanceOf(PLAYER))
	{
		player = (Player*)entity;
	}
	entity->removed = false;
	entities.push_back(entity);
	entity->init(this);

	insertEntity(entity->x >> 4, entity->y >> 4, entity);
	//uncomment to get straight to AirWizard
//	if (entity->instanceOf(PLAYER))
//	{
//		entity->x = w*8;
//		entity->y = h*8;
//		insertEntity(w*8  + 2, h*8 + 2, entity);
//		setTile(entity->x >> 4, (entity->y >> 4) + 1, Tile::stairsUp,0);
//	}
//	else
//	{
//		insertEntity(entity->x >> 4, entity->y >> 4, entity);
//	}

}

void Level::remove(Entity * e)
{
	entities.remove(e);
//	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++ )
//	{
//		if (*it == e)
//		{
//			entities.erase(it);
//			break;
//		}
//	}
	int xto = e->x >> 4;
	int yto = e->y >> 4;
	removeEntity(xto, yto, e);
}

void Level::insertEntity(int x, int y, Entity * e) {
	if (x < 0 || y < 0 || x >= w || y >= h) return;
	entitiesInTiles[x + y * w].push_back(e);
}

void Level::removeEntity(int x, int y, Entity * e)
{
	if (x < 0 || y < 0 || x >= w || y >= h) return;
	entitiesInTiles[x + y * w].remove(e);
//	list<Entity*> &entitiesInTile = entitiesInTiles[x + y * w];
//	for (list<Entity*>::iterator it = entitiesInTile.begin(); it != entitiesInTile.end(); it++ )
//	{
//		if (*it == e)
//		{
//			entitiesInTile.erase(it);
//			break;
//		}
//	}
}

void Level::trySpawn(int count)
{
	for (int i = 0; i < count; i++)
	{
		Mob * mob;

		int minLevel = 1;
		int maxLevel = 1;
		if (depth < 0)
		{
			maxLevel = (-depth) + 1;
		}
		if (depth > 0)
		{
			minLevel = maxLevel = 4;
		}
		int lvl = random->nextInt(maxLevel - minLevel + 1) + minLevel;
		if (random->nextInt(2) == 0)
			mob = new Slime(lvl);
		else
			mob = new Zombie(lvl);

		if (!mob->findStartPos(this))
		{
			delete mob;
		}
		else
		{
			this->add(mob);
		}
	}
}

void Level::tick()
{
	trySpawn(1);

	int tilesTickAttempts = w * h / 50;
	for (int i = 0; i < tilesTickAttempts; ++i)
	{
		int xt = random->nextInt(w);
		int yt = random->nextInt(h);
		getTile(xt, yt)->tick(this, xt, yt);
	}
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++ )
	{
		Entity * e = *it;
		int xto = e->x >> 4;
		int yto = e->y >> 4;

		e->tick();

		if (e->removed)
		{
			removeEntity(xto, yto, e);
			//we should not delete player, because it will freeze on death
			//we should not delete furniture, because it is used in FurnitureItem, when taken
			if (!e->instanceOf(PLAYER) && !e->instanceOf(FURNITURE))
				delete e;
			it = entities.erase(it);
		}
		else
		{
			int xt = e->x >> 4;
			int yt = e->y >> 4;

			if (xto != xt || yto != yt)
			{
				removeEntity(xto, yto, e);
				insertEntity(xt, yt, e);
			}
		}
	}
}

list<Entity*> * Level::getEntities(int x0, int y0, int x1, int y1)
{
	list<Entity*> * result = new list<Entity*>;
	int xt0 = (x0 >> 4) - 1;
	int yt0 = (y0 >> 4) - 1;
	int xt1 = (x1 >> 4) + 1;
	int yt1 = (y1 >> 4) + 1;
	for (int y = yt0; y <= yt1; ++y)
	{
		if (y < 0 || y >= h) continue;
		int yByWidth = y * this->w;
		for (int x = xt0; x <= xt1; ++x)
		{
			if (x < 0  || x >= w) continue;
			list<Entity*> &ent = entitiesInTiles[x + yByWidth];
			if (ent.empty()) continue;
			for (list<Entity*>::iterator it = ent.begin(); it != ent.end(); it++ )
			{
				Entity * e = *it;
				if (e->intersects(x0, y0, x1, y1)) result->push_back(e);
			}
		}
	}
	return result;
}

list<Entity*> * Level::getEntities(int x0, int y0, int x1, int y1, Entity * excluded)
{
	list<Entity*> * result = new list<Entity*>;
	int xt0 = (x0 >> 4) - 1;
	int yt0 = (y0 >> 4) - 1;
	int xt1 = (x1 >> 4) + 1;
	int yt1 = (y1 >> 4) + 1;
	for (int y = yt0; y <= yt1; ++y)
	{
		if (y < 0 || y >= h) continue;
		int yByWidth = y * this->w;
		for (int x = xt0; x <= xt1; ++x)
		{
			if (x < 0  || x >= w) continue;
			list<Entity*> &ent = entitiesInTiles[x + yByWidth];
			if (ent.empty()) continue;
			for (list<Entity*>::iterator it = ent.begin(); it != ent.end(); it++ )
			{
				Entity * e = *it;
				if (e->intersects(x0, y0, x1, y1))
				{
					if (e != excluded)
					{
						result->push_back(e);
					}
				}
			}
		}
	}
	return result;
}

list<Entity*> * Level::getEntities(int x0, int y0)
{
	int x = (x0 >> 4);
	int y = (y0 >> 4);
	return new list<Entity*>(entitiesInTiles[x + y * this->w]);
}

bool Level::isRegionEmpty(int x0, int y0, int x1, int y1)
{
	int xt0 = (x0 >> 4) - 1;
	int yt0 = (y0 >> 4) - 1;
	int xt1 = (x1 >> 4) + 1;
	int yt1 = (y1 >> 4) + 1;
	for (int y = yt0; y <= yt1; ++y)
	{
		if (y < 0 || y >= h) continue;
		int yByWidth = y * this->w;
		for (int x = xt0; x <= xt1; ++x)
		{
			if (x < 0  || x >= w) continue;
			list<Entity*> &ent = entitiesInTiles[x + yByWidth];
			if (ent.empty()) continue;
			for (list<Entity*>::iterator it = ent.begin(); it != ent.end(); it++ )
			{
				Entity * e = *it;
				if (e->intersects(x0, y0, x1, y1)) return false;
			}
		}
	}
	return true;
}

