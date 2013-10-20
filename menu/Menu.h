/*
 * Menu.h
 *
 *  Created on: 18 окт. 2013 г.
 *      Author: user
 */

#ifndef MENU_H_
#define MENU_H_

#include <deque>
#include "ListItem.h"
#include "../crafting/Recipe.h"

#include "../item/Item.h"

#include "../Screen.h"

using namespace std;

class Game;
class InputHandler;

class Menu {
public:
	virtual void init(Game * game, InputHandler * input);
	virtual void tick();
	virtual void render(Screen * screen);

	//no time for pesky Java generics
	//simple overload here
	virtual void renderItemList(Screen * screen, int xo, int yo, int x1, int y1, deque<Item*> &listItems, int selected);
	virtual void renderItemList(Screen * screen, int xo, int yo, int x1, int y1, deque<Recipe*> &listItems, int selected);

protected:
	Game * game;
	InputHandler * input;
};

#endif /* MENU_H_ */
