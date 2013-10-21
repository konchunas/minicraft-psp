#include "Tile.h"
#include "../Level.h"
#include "../../entity/Entity.h"
#include "../../entity/Mob.h"
#include "../../entity/Player.h"
#include "../../Screen.h"
#include "../../item/Item.h"


#include "GrassTile.h"
#include "RockTile.h"
#include "WaterTile.h"
#include "FLowerTile.h"
#include "TreeTile.h"
#include "DirtTile.h"
#include "SandTile.h"
#include "CactusTile.h"
#include "HoleTile.h"
#include "SaplingTile.h"
#include "FarmTile.h"
#include "WheatTile.h"
#include "LavaTile.h"
#include "StairsTile.h"


Tile** Tile::tiles = new Tile*[256];
Tile * Tile::grass = new GrassTile(0);
Tile * Tile::rock = new RockTile(1);
Tile * Tile::water = new WaterTile(2);
Tile * Tile::flower = new FlowerTile(3);
Tile * Tile::tree = new TreeTile(4);
Tile * Tile::dirt = new DirtTile(5);
Tile * Tile::sand = new SandTile(6);
Tile * Tile::cactus = new CactusTile(7);
Tile * Tile::hole = new HoleTile(8);
Tile * Tile::treeSapling = new SaplingTile(9, grass, tree);
Tile * Tile::cactusSapling = new SaplingTile(10, sand, cactus);
Tile * Tile::farmland = new FarmTile(11);
Tile * Tile::wheat = new WheatTile(12);
Tile * Tile::lava = new LavaTile(13);
Tile * Tile::stairsDown = new StairsTile(14, false);
Tile * Tile::stairsUp = new StairsTile(15, true);
//Tile * Tile::infiniteFall = new InfiniteFallTile(16);
//Tile * Tile::cloud = new CloudTile(17);
//Tile * Tile::hardRock = new HardRockTile(18);
//Tile * Tile::ironOre = new OreTile(19, Resource::ironOre);
//Tile * Tile::goldOre = new OreTile(20, Resource::goldOre);
//Tile * Tile::gemOre = new OreTile(21, Resource::gem);
//Tile * Tile::cloudCactus = new CloudCactusTile(22);

int Tile::tickCount = 0;

Tile::Tile(int id):
connectsToGrass(false),
connectsToSand(false),
connectsToLava(false),
connectsToWater(false)
{
	this->id = (ushort) id;
	tiles[id] = this;

}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

void Tile::render(Screen * screen, Level * level, int x, int y) {
}

bool Tile::mayPass(Level * level, int x, int y, Entity * e) {
	return true;
}

int Tile::getLightRadius(Level * level, int x, int y) {
	return 0;
}

void Tile::hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir)
{

}

void Tile::bumpedInto(Level * level, int xt, int yt, Entity * entity) {
}

void Tile::tick(Level * level, int xt, int yt) {
}

void Tile::steppedOn(Level * level, int xt, int yt, Entity * entity) {
}

bool Tile::interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir)
{
	return false;
}

bool Tile::use(Level * level, int xt, int yt, Player * player, int attackDir)
{
	return false;
}

bool Tile::connectsToLiquid() {
	return connectsToWater || connectsToLava;
}

