
#include "../Color.h"
#include "Anvil.h"
#include "Player.h"
#include "../Game.h"
#include "../menu/CraftingMenu.h"
#include "../crafting/Crafting.h"

Anvil::~Anvil()
{
	// TODO Auto-generated destructor stub
}
Anvil::Anvil() : Furniture("Anvil")
{
	col = Color::get(-1, 000, 111, 222);
	sprite = 0;
	xr = 3;
	yr = 2;
}

bool Anvil::use(Player * player, int attackDir)
{
	player->game->setMenu(new CraftingMenu(Crafting::anvilRecipes, player));
	return true;
}
