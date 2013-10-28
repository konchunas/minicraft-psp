#include "Tile.h"
#include "../Level.h"
#include "../../entity/Entity.h"
#include "../../entity/Mob.h"
#include "../../entity/Player.h"
#include "../../Screen.h"
#include "../../item/Item.h"
#include "../../item/resource/Resource.h"


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
#include "InfiniteFallTile.h"
#include "CloudTile.h"
#include "HardRockTile.h"
#include "OreTile.h"
#include "CloudCactusTile.h"


Tile** Tile::tiles;
Tile * Tile::grass;
Tile * Tile::rock;
Tile * Tile::water;
Tile * Tile::flower;
Tile * Tile::tree;
Tile * Tile::dirt;
Tile * Tile::sand;
Tile * Tile::cactus;
Tile * Tile::hole;
Tile * Tile::treeSapling;
Tile * Tile::cactusSapling;
Tile * Tile::farmland;
Tile * Tile::wheat;
Tile * Tile::lava;
Tile * Tile::stairsDown;
Tile * Tile::stairsUp;
Tile * Tile::infiniteFall;
Tile * Tile::cloud;
Tile * Tile::hardRock;

Tile * Tile::ironOre;
Tile * Tile::goldOre;
Tile * Tile::gemOre;
Tile* Tile::cloudCactus;

int Tile::tickCount = 0;

void Tile::init()
{
	Tile::tiles = new Tile*[256];
	Tile::grass = new GrassTile(0);
	Tile::rock = new RockTile(1);
	Tile::water = new WaterTile(2);
	Tile::flower = new FlowerTile(3);
	Tile::tree = new TreeTile(4);
	Tile::dirt = new DirtTile(5);
	Tile::sand = new SandTile(6);
	Tile::cactus = new CactusTile(7);
	Tile::hole = new HoleTile(8);
	Tile::treeSapling = new SaplingTile(9, grass, tree);
	Tile::cactusSapling = new SaplingTile(10, sand, cactus);
	Tile::farmland = new FarmTile(11);
	Tile::wheat = new WheatTile(12);
	Tile::lava = new LavaTile(13);
	Tile::stairsDown = new StairsTile(14, false);
	Tile::stairsUp = new StairsTile(15, true);

	Tile::infiniteFall = new InfiniteFallTile(16);
	Tile::cloud = new CloudTile(17);
	Tile::hardRock = new HardRockTile(18);

	Tile::ironOre = new OreTile(19, Resource::ironOre);
	Tile::goldOre = new OreTile(20, Resource::goldOre);
	Tile::gemOre = new OreTile(21, Resource::gem);
	Tile::cloudCactus = new CloudCactusTile(22);
}

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

