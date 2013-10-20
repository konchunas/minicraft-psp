#ifndef RECIPE_H_
#define RECIPE_H_

#include <deque>
#include "../menu/ListItem.h"
#include "../Screen.h"

class Resource;
class Player;
class Item;

using namespace std;

class Recipe : public ListItem {
public:
	Recipe(Item * resultTemplate);
	virtual ~Recipe();

	deque<Item*> costs;
	bool canCraft;
	Item * resultTemplate;

	Recipe * addCost(Resource * resource, int count);
	void checkCanCraft(Player * player);
	virtual void renderInventory(Screen * screen, int x, int y);
	virtual void craft(Player * player) = 0;
	void deductCost(Player * player);
};

#endif /* RECIPE_H_ */
