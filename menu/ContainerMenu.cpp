#include "../Font.h"
#include "../Game.h"
#include "../entity/Player.h"
#include "../entity/Inventory.h"
#include "../item/Item.h"

#include "ContainerMenu.h"

ContainerMenu::~ContainerMenu() {
	// TODO Auto-generated destructor stub
}

ContainerMenu::ContainerMenu(Player * player, string title, Inventory * container):
selected(0), window(0)
{
	this->player = player;
	this->title = title;
	this->container = container;
}

void ContainerMenu::tick()
{
	if (input->menu->clicked) game->setMenu(NULL);

	if (input->left->clicked) {
		window = 0;
		int tmp = selected;
		selected = oSelected;
		oSelected = tmp;
	}
	if (input->right->clicked) {
		window = 1;
		int tmp = selected;
		selected = oSelected;
		oSelected = tmp;
	}

	Inventory * i = window == 1 ? player->inventory : container;
	Inventory * i2 = window == 0 ? player->inventory : container;

	int len = i->items.size();
	if (selected < 0) selected = 0;
	if (selected >= len) selected = len - 1;

	if (input->up->clicked) selected--;
	if (input->down->clicked) selected++;

	if (len == 0) selected = 0;
	if (selected < 0) selected += len;
	if (selected >= len) selected -= len;

	if (input->attack->clicked && len > 0) {
		i2->add(oSelected, i->removeAt(selected));
		if (selected >= i->items.size()) selected = i->items.size() - 1;
	}
}

void ContainerMenu::render(Screen * screen)
{
	if (window == 1) screen->setOffset(6 * 8, 0);
	Font::renderFrame(screen, title, 1, 1, 12, 9);
	renderItemList(screen, 1, 1, 12, 9, container->items, window == 0 ? selected : -oSelected - 1);

	Font::renderFrame(screen, "inventory", 13, 1, 13 + 11, 9);
	renderItemList(screen, 13, 1, 13 + 11, 9, player->inventory->items, window == 1 ? selected : -oSelected - 1);
	screen->setOffset(0, 0);
}
