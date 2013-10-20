#include "../item/ToolItem.h"
#include "../entity/Player.h"

#include "ToolRecipe.h"

ToolRecipe::ToolRecipe(ToolType * type, int level):
Recipe(new ToolItem(type, level))
{
	this->type = type;
	this->level = level;
}

ToolRecipe::~ToolRecipe()
{
	// TODO Auto-generated destructor stub
}

void ToolRecipe::craft(Player * player)
{
	player->inventory->add(0, new ToolItem(type, level));
}

