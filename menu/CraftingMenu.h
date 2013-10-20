#ifndef CRAFTINGMENU_H_
#define CRAFTINGMENU_H_

#include <deque>

#include "Menu.h"
#include "../entity/Player.h"
#include "../Screen.h"


class CraftingMenu : public Menu
{
public:
	CraftingMenu(deque<Recipe*> &recipes, Player * player);
	virtual ~CraftingMenu();

	void tick();
	void render(Screen * screen);

private:
	Player * player;
	int selected;
	deque<Recipe*> &recipes;


};

#endif /* CRAFTINGMENU_H_ */
