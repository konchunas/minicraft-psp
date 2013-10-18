#include "InventoryMenu.h"

#include "../Font.h"
#include "../Game.h"
#include "../entity/Player.h"
#include "../entity/Inventory.h"
#include "../item/Item.h"

InventoryMenu::~InventoryMenu() {
	// TODO Auto-generated destructor stub
}

InventoryMenu::InventoryMenu(Player * player):
selected(0)
{
	this->player = player;

	if (player->activeItem != NULL)
	{
		player->inventory->items.push_front(player->activeItem);
		player->activeItem = NULL;
	}
}

void InventoryMenu::tick()
{
	if (input->menu->clicked) game->setMenu(NULL);

	if (input->up->clicked) selected--;
	if (input->down->clicked) selected++;

	int len = player->inventory->items.size();
	if (len == 0) selected = 0;
	if (selected < 0) selected += len;
	if (selected >= len) selected -= len;

	if (input->attack->clicked && len > 0)
	{
		Item * item = player->inventory->removeAt(selected);
		player->activeItem = item;
		game->setMenu(NULL);
	}
}

void InventoryMenu::render(Screen * screen)
{
	//oslDebug("about to render");
	Font::renderFrame(screen, "inventory", 1, 1, 12, 9);
	renderItemList(screen, 1, 1, 12, 9, player->inventory->items, selected);
}
