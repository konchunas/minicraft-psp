#include "../Font.h"
#include "../Color.h"

#include "Recipe.h"

#include "../item/Item.h"
#include "../item/resource/Resource.h"
#include "../entity/Player.h"


Recipe::~Recipe() {
	// TODO Auto-generated destructor stub
}

Recipe::Recipe(Item * resultTemplate):
canCraft(false)
{
	this->resultTemplate = resultTemplate;
}

Recipe * Recipe::addCost(Resource * resource, int count)
{
	costs.push_back(new ResourceItem(resource, count));
	return this;
}

void Recipe::checkCanCraft(Player * player)
{
	for (deque<Item*>::iterator it = costs.begin(); it != costs.end(); it++ )
	{
		Item * item = *it;
		if (item->instanceOf(RESOURCE_ITEM))
		{
			ResourceItem * ri = static_cast<ResourceItem*>(item);
			if (!player->inventory->hasResources(ri->resource, ri->count))
			{
				canCraft = false;
				return;
			}
		}
	}
	canCraft = true;
}

void Recipe::renderInventory(Screen * screen, int x, int y)
{
	screen->render(x, y, resultTemplate->getSprite(), resultTemplate->getColor(), 0);
	int textColor = canCraft ? Color::get(-1, 555, 555, 555) : Color::get(-1, 222, 222, 222);
	Font::draw(resultTemplate->getName(), screen, x + 8, y, textColor);
}

void Recipe::deductCost(Player * player)
{
	for (deque<Item*>::iterator it = costs.begin(); it != costs.end(); it++ )
	{
		Item * item = *it;
		if (item->instanceOf(RESOURCE_ITEM)) {
			ResourceItem * ri = static_cast<ResourceItem*>(item);
			player->inventory->removeResource(ri->resource, ri->count);
		}
	}
}
