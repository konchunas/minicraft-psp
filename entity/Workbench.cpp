#include "../Color.h"
#include "../entity/Player.h"
#include "../Game.h"
#include "../menu/CraftingMenu.h"
#include "../crafting/Crafting.h"

#include "Workbench.h"

Workbench::Workbench():
Furniture("Workbench")
{
	col = Color::get(-1, 100, 321, 431);
	sprite = 4;
	xr = 3;
	yr = 2;
}
Workbench::~Workbench()
{
}

bool Workbench::use(Player * player, int attackDir)
{
	player->game->setMenu(new CraftingMenu(Crafting::workbenchRecipes, player));
	return true;
}
