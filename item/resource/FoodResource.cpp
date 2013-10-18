
#include "FoodResource.h"

FoodResource::~FoodResource() {
	// TODO Auto-generated destructor stub
}

FoodResource::FoodResource(string name, int sprite, int color, int heal, int staminaCost)
:Resource(name, sprite, color)
{
	this->heal = heal;
	this->staminaCost = staminaCost;
}

bool FoodResource::interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir)
{
	if (player->health < player->maxHealth && player->payStamina(staminaCost)) {
		player->heal(heal);
		return true;
	}
	return false;
}


