/*
 * Resource.cpp
 *
 *  Created on: 17 окт. 2013 г.
 *      Author: user
 */

#include "Resource.h"
#include <oslib/oslib.h>

#include "../../level/tile/Tile.h"
#include "../../level/Level.h"
#include "../../entity/Player.h"
#include "../../Color.h"


Resource::~Resource() {
	// TODO Auto-generated destructor stub
}

 Resource * Resource::wood = new Resource("Wood", 1 + 4 * 32, Color::get(-1, 200, 531, 430));
 Resource * Resource::stone = new Resource("Stone", 2 + 4 * 32, Color::get(-1, 111, 333, 555));
 //Resource * Resource::flower = new PlantableResource("Flower", 0 + 4 * 32, Color::get(-1, 10, 444, 330), Tile.flower, Tile.grass);
 //Resource * Resource::acorn = new PlantableResource("Acorn", 3 + 4 * 32, Color::get(-1, 100, 531, 320), Tile.treeSapling, Tile.grass) lic static Resource dirt = new PlantableResource("Dirt", 2 + 4 * 32, Color::get(-1, 100, 322, 432), Tile.dirt, Tile.hole, Tile.water, Tile.lava);
 //Resource * Resource::sand = new PlantableResource("Sand", 2 + 4 * 32, Color::get(-1, 110, 440, 550), Tile.sand, Tile.grass, Tile.dirt);
 //Resource * Resource::cactusFlower = new PlantableResource("Cactus", 4 + 4 * 32, Color::get(-1, 10, 40, 50), Tile.cactusSapling, Tile.sand);
 //Resource * Resource::seeds = new PlantableResource("Seeds", 5 + 4 * 32, Color::get(-1, 10, 40, 50), Tile.wheat, Tile.farmland);
 Resource * Resource::wheat = new Resource("Wheat", 6 + 4 * 32, Color::get(-1, 110, 330, 550));
 //Resource * Resource::bread = new FoodResource("Bread", 8 + 4 * 32, Color::get(-1, 110, 330, 550), 2, 5);
 //Resource * Resource::apple = new FoodResource("Apple", 9 + 4 * 32, Color::get(-1, 100, 300, 500), 1, 5);

 Resource * Resource::coal = new Resource("COAL", 10 + 4 * 32, Color::get(-1, 000, 111, 111));
 Resource * Resource::ironOre = new Resource("I.ORE", 10 + 4 * 32, Color::get(-1, 100, 322, 544));
 Resource * Resource::goldOre = new Resource("G.ORE", 10 + 4 * 32, Color::get(-1, 110, 440, 553));
 Resource * Resource::ironIngot = new Resource("IRON", 11 + 4 * 32, Color::get(-1, 100, 322, 544));
 Resource * Resource::goldIngot = new Resource("GOLD", 11 + 4 * 32, Color::get(-1, 110, 330, 553));

 Resource * Resource::slime = new Resource("SLIME", 10 + 4 * 32, Color::get(-1, 10, 30, 50));
 Resource * Resource::glass = new Resource("glass", 12 + 4 * 32, Color::get(-1, 555, 555, 555));
 Resource * Resource::cloth = new Resource("cloth", 1 + 4 * 32, Color::get(-1, 25, 252, 141));
 //Resource * Resource::cloud = new PlantableResource("cloud", 2 + 4 * 32, Color::get(-1, 222, 555, 444), Tile.cloud, Tile.infiniteFall);
 Resource * Resource::gem = new Resource("gem", 13 + 4 * 32, Color::get(-1, 101, 404, 545));



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

