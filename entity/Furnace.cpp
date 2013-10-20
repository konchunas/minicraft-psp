#include "../Color.h"
#include "../entity/Player.h"
#include "../Game.h"
#include "../menu/CraftingMenu.h"
#include "../crafting/Crafting.h"

#include "Furnace.h"


Furnace::Furnace()
:Furniture("Furnace")
{
	col = Color::get(-1, 000, 222, 333);
	sprite = 3;
	xr = 3;
	yr = 2;
}
Furnace::~Furnace()
{
}

bool Furnace::use(Player * player, int attackDir)
{
	player->game->setMenu(new CraftingMenu(Crafting::furnaceRecipes, player));
	return true;
}
