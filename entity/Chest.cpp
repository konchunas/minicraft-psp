#include "../Color.h"
#include "Player.h"
#include "../Game.h"
#include "../menu/ContainerMenu.h"
#include "../entity/Inventory.h"
#include "../crafting/Crafting.h"

#include "Chest.h"

Chest::~Chest()
{
	// TODO Auto-generated destructor stub
}

Chest::Chest() : Furniture("Chest"),
inventory(new Inventory())
{
	col = Color::get(-1, 110, 331, 552);
	sprite = 1;
}

bool Chest::use(Player * player, int attackDir)
{
	player->game->setMenu(new ContainerMenu(player, "Chest", inventory));
	return true;
}
