#include "../Color.h"
#include "Player.h"
#include "../Game.h"
#include "../menu/CraftingMenu.h"
#include "../crafting/Crafting.h"

#include "Oven.h"

Oven::Oven(): Furniture("Oven") {
	col = Color::get(-1, 000, 332, 442);
	sprite = 2;
	xr = 3;
	yr = 2;
}
Oven::~Oven()
{
}

bool Oven::use(Player * player, int attackDir)
{
	player->game->setMenu(new CraftingMenu(Crafting::ovenRecipes, player));
	return true;
}
