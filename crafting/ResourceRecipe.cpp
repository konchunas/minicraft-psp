#include "../item/ToolItem.h"
#include "../entity/Player.h"

#include "ResourceRecipe.h"

ResourceRecipe::~ResourceRecipe() {
	// TODO Auto-generated destructor stub
}

ResourceRecipe::ResourceRecipe(Resource * resource)
: Recipe(new ResourceItem(resource, 1)),
resource(resource)
{

}

void ResourceRecipe::craft(Player * player)
{
	player->inventory->add(0, new ResourceItem(resource, 1));
}
