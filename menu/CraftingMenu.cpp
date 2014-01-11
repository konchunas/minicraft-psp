
#include <sstream>

#include "../crafting/Recipe.h"
#include "../entity/Player.h"
#include "../Font.h"
#include "../Color.h"
#include "../Game.h"
#include "../Sound.h"

#include "CraftingMenu.h"


CraftingMenu::~CraftingMenu() {
	// TODO Auto-generated destructor stub
}

CraftingMenu::CraftingMenu(deque<Recipe*> &recipes, Player * player)
:recipes(recipes),
selected(0)
{
	this->player = player;

	for (deque<Recipe*>::iterator it = recipes.begin(); it != recipes.end(); it++ )
	{
		Recipe * recipe = *it;
		recipe->checkCanCraft(player);
	}

//		Collections.sort(this->recipes, new Comparator<Recipe>() {
//			public int compare(Recipe r1, Recipe r2) {
//				if (r1.canCraft && !r2.canCraft) return -1;
//				if (!r1.canCraft && r2.canCraft) return 1;
//				return 0;
//			}
//		});
}

void CraftingMenu::tick()
{
	if (input->menu->clicked ||
		input->exit->clicked)
	{
		game->setMenu(NULL);
	}

	if (input->up->clicked) selected--;
	if (input->down->clicked) selected++;

	int len = recipes.size();
	if (len == 0) selected = 0;
	if (selected < 0) selected += len;
	if (selected >= len) selected -= len;

	if (input->attack->clicked && len > 0)
	{
		Recipe * r = recipes.at(selected);
		r->checkCanCraft(player);
		if (r->canCraft) {
			r->deductCost(player);
			r->craft(player);
			Sound::craft->play();
		}
		for (deque<Recipe*>::iterator it = recipes.begin(); it != recipes.end(); it++ )
		{
			Recipe * recipe = *it;
			recipe->checkCanCraft(player);
		}
	}
}

void CraftingMenu::render(Screen * screen)
{
	Font::renderFrame(screen, "Have", 12, 1, 19, 3);
	Font::renderFrame(screen, "Cost", 12, 4, 19, 9);
	Font::renderFrame(screen, "Crafting", 0, 1, 11, 9);
	renderItemList(screen, 0, 1, 11, 9, recipes, selected);

	if (recipes.size() > 0)
	{
		Recipe * recipe = recipes.at(selected);
		int hasResultItems = player->inventory->count(recipe->resultTemplate);
		int xo = 13 * 8;
		screen->render(xo, 2 * 8, recipe->resultTemplate->getSprite(), recipe->resultTemplate->getColor(), 0);
		stringstream hasResultItemsStream;
		hasResultItemsStream<<hasResultItems;
		Font::draw(hasResultItemsStream.str(), screen, xo + 8, 2 * 8, Color::get(-1, 555, 555, 555));

		deque<Item*> &costs = recipe->costs;
		for (int i = 0; i < costs.size(); i++)
		{
			Item * item = costs.at(i);
			int yo = (5 + i) * 8;
			screen->render(xo, yo, item->getSprite(), item->getColor(), 0);
			int requiredAmt = 1;
			if (item->instanceOf(RESOURCE_ITEM)) {
				requiredAmt = static_cast<ResourceItem*>(item)->count;
			}
			int has = player->inventory->count(item);
			int color = Color::get(-1, 555, 555, 555);
			if (has < requiredAmt) {
				color = Color::get(-1, 222, 222, 222);
			}
			if (has > 99) has = 99;
			//implement sstrem here
			stringstream stat;
			stat << requiredAmt <<"/" << has;
			Font::draw(stat.str(), screen, xo + 8, yo, color);
		}
	}
	// renderItemList(screen, 12, 4, 19, 11, recipes.get(selected).costs, -1);
}

