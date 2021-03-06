/*
 * Resource.cpp
 *
 *  Created on: 17 ���. 2013 �.
 *      Author: user
 */

#include "Resource.h"
#include <oslib/oslib.h>

#include "../../level/tile/Tile.h"
#include "../../level/Level.h"
#include "../../entity/Player.h"
#include "../../Color.h"

#include "PlantableResource.h"
#include "FoodResource.h"

Resource * Resource::wood;
Resource * Resource::stone;
Resource * Resource::flower;
Resource * Resource::acorn;
Resource * Resource::dirt;
Resource * Resource::sand;
Resource * Resource::cactusFlower;
Resource * Resource::seeds;
Resource * Resource::wheat;
Resource * Resource::bread;
Resource * Resource::apple;

Resource * Resource::coal;
Resource * Resource::ironOre;
Resource * Resource::goldOre;
Resource * Resource::ironIngot;
Resource * Resource::goldIngot;

Resource * Resource::slime;
Resource * Resource::glass;
Resource * Resource::cloth;
Resource * Resource::cloud;
Resource * Resource::gem;

Resource::~Resource() {
	// TODO Auto-generated destructor stub
}

//a little thing changed here, so last arguments are target tile, followed by amount of source tiles and list of source tiles themselves
void Resource::init()
{
	Resource::wood = new Resource("Wood", 1 + 4 * 32, Color::get(-1, 200, 531, 430));
	Resource::stone = new Resource("Stone", 2 + 4 * 32, Color::get(-1, 111, 333, 555));
	Resource::wheat = new Resource("Wheat", 6 + 4 * 32, Color::get(-1, 110, 330, 550));
	Resource::bread = new FoodResource("Bread", 8 + 4 * 32, Color::get(-1, 110, 330, 550), 2, 5);
	Resource::apple = new FoodResource("Apple", 9 + 4 * 32, Color::get(-1, 100, 300, 500), 1, 5);

	Resource::coal = new Resource("COAL", 10 + 4 * 32, Color::get(-1, 000, 111, 111));
	Resource::ironOre = new Resource("I.ORE", 10 + 4 * 32, Color::get(-1, 100, 322, 544));
	Resource::goldOre = new Resource("G.ORE", 10 + 4 * 32, Color::get(-1, 110, 440, 553));
	Resource::ironIngot = new Resource("IRON", 11 + 4 * 32, Color::get(-1, 100, 322, 544));
	Resource::goldIngot = new Resource("GOLD", 11 + 4 * 32, Color::get(-1, 110, 330, 553));

	Resource::slime = new Resource("SLIME", 10 + 4 * 32, Color::get(-1, 10, 30, 50));
	Resource::glass = new Resource("glass", 12 + 4 * 32, Color::get(-1, 555, 555, 555));
	Resource::cloth = new Resource("cloth", 1 + 4 * 32, Color::get(-1, 25, 252, 141));
	Resource::gem = new Resource("gem", 13 + 4 * 32, Color::get(-1, 101, 404, 545));
}

void Resource::initPlantable()
{
	Resource::flower = new PlantableResource("Flower", 0 + 4 * 32, Color::get(-1, 10, 444, 330), Tile::flower, 1, Tile::grass);
	Resource::acorn = new PlantableResource("Acorn", 3 + 4 * 32, Color::get(-1, 100, 531, 320), Tile::treeSapling, 1, Tile::grass);
	Resource::dirt = new PlantableResource("Dirt", 2 + 4 * 32, Color::get(-1, 100, 322, 432), Tile::dirt, 3, Tile::hole, Tile::water, Tile::lava);
	Resource::sand = new PlantableResource("Sand", 2 + 4 * 32, Color::get(-1, 110, 440, 550), Tile::sand, 2, Tile::grass, Tile::dirt);
	Resource::cactusFlower = new PlantableResource("Cactus", 4 + 4 * 32, Color::get(-1, 10, 40, 50), Tile::cactusSapling, 1, Tile::sand);
	Resource::seeds = new PlantableResource("Seeds", 5 + 4 * 32, Color::get(-1, 10, 40, 50), Tile::wheat, 1, Tile::farmland);
	Resource::cloud = new PlantableResource("cloud", 2 + 4 * 32, Color::get(-1, 222, 555, 444), Tile::cloud, 1, Tile::infiniteFall);
}



Resource::Resource(string name, int sprite, int color)
{
	if (name.length() > 6)
		oslDebug("Name cannot be longer than six characters!");
	this->name = name;
	this->sprite = sprite;
	this->color = color;
}

bool Resource::interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir)
{
	return false;
}

