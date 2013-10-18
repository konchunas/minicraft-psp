#ifndef INVENTORYMENU_H_
#define INVENTORYMENU_H_

#include "Menu.h"
#include "../entity/Player.h"
#include "../Screen.h"

class Game;

class InventoryMenu : public Menu {
public:
	InventoryMenu(Player * player);
	virtual ~InventoryMenu();

	void tick();
	void render(Screen * screen);

private:
	Player * player;
	int selected;
};

#endif /* INVENTORYMENU_H_ */
