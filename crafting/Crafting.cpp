#include "ToolRecipe.h"
#include "../item/ToolType.h"
#include "../item/resource/Resource.h"

#include "../entity/Workbench.h"
#include "../entity/Furnace.h"
#include "../entity/Oven.h"

#include "FurnitureRecipe.h"
#include "ResourceRecipe.h"

#include "Crafting.h"

deque<Recipe*> Crafting::anvilRecipes;
deque<Recipe*> Crafting::ovenRecipes;
deque<Recipe*> Crafting::furnaceRecipes;
deque<Recipe*> Crafting::workbenchRecipes;

void Crafting::init()
{
	//workbenchRecipes.push_back((new FurnitureRecipe<Lantern>())->addCost(Resource::wood, 5)->addCost(Resource::slime, 10)->addCost(Resource::glass, 4));
	workbenchRecipes.push_back((new FurnitureRecipe<Oven>())->addCost(Resource::stone, 15));
	workbenchRecipes.push_back((new FurnitureRecipe<Furnace>())->addCost(Resource::stone, 20));
	workbenchRecipes.push_back((new FurnitureRecipe<Workbench>())->addCost(Resource::wood, 20));
	//workbenchRecipes.push_back((new FurnitureRecipe(Chest.class)->addCost(Resource::wood, 20));
	//workbenchRecipes.push_back(((new FurnitureRecipe(Anvil.class)->addCost(Resource::ironIngot, 5));

	workbenchRecipes.push_back((new ToolRecipe(ToolType::sword, 0))->addCost(Resource::wood, 5));
	workbenchRecipes.push_back((new ToolRecipe(ToolType::axe, 0))->addCost(Resource::wood, 5));
	workbenchRecipes.push_back((new ToolRecipe(ToolType::hoe, 0))->addCost(Resource::wood, 5));
	workbenchRecipes.push_back((new ToolRecipe(ToolType::pickaxe, 0))->addCost(Resource::wood, 5));
	workbenchRecipes.push_back((new ToolRecipe(ToolType::shovel, 0))->addCost(Resource::wood, 5));
	workbenchRecipes.push_back((new ToolRecipe(ToolType::sword, 1))->addCost(Resource::wood, 5)->addCost(Resource::stone, 5));
	workbenchRecipes.push_back((new ToolRecipe(ToolType::axe, 1))->addCost(Resource::wood, 5)->addCost(Resource::stone, 5));
	workbenchRecipes.push_back((new ToolRecipe(ToolType::hoe, 1))->addCost(Resource::wood, 5)->addCost(Resource::stone, 5));
	workbenchRecipes.push_back((new ToolRecipe(ToolType::pickaxe, 1))->addCost(Resource::wood, 5)->addCost(Resource::stone, 5));
	workbenchRecipes.push_back((new ToolRecipe(ToolType::shovel, 1))->addCost(Resource::wood, 5)->addCost(Resource::stone, 5));

//	anvilRecipes.push_back((new ToolRecipe(ToolType::sword, 2)->addCost(Resource::wood, 5)->addCost(Resource::ironIngot, 5));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::axe, 2)->addCost(Resource::wood, 5)->addCost(Resource::ironIngot, 5));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::hoe, 2)->addCost(Resource::wood, 5)->addCost(Resource::ironIngot, 5));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::pickaxe, 2)->addCost(Resource::wood, 5)->addCost(Resource::ironIngot, 5));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::shovel, 2)->addCost(Resource::wood, 5)->addCost(Resource::ironIngot, 5));
//
//	anvilRecipes.push_back((new ToolRecipe(ToolType::sword, 3)->addCost(Resource::wood, 5)->addCost(Resource::goldIngot, 5));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::axe, 3)->addCost(Resource::wood, 5)->addCost(Resource::goldIngot, 5));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::hoe, 3)->addCost(Resource::wood, 5)->addCost(Resource::goldIngot, 5));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::pickaxe, 3)->addCost(Resource::wood, 5)->addCost(Resource::goldIngot, 5));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::shovel, 3)->addCost(Resource::wood, 5)->addCost(Resource::goldIngot, 5));
//
//	anvilRecipes.push_back((new ToolRecipe(ToolType::sword, 4)->addCost(Resource::wood, 5)->addCost(Resource::gem, 50));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::axe, 4)->addCost(Resource::wood, 5)->addCost(Resource::gem, 50));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::hoe, 4)->addCost(Resource::wood, 5)->addCost(Resource::gem, 50));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::pickaxe, 4)->addCost(Resource::wood, 5)->addCost(Resource::gem, 50));
//	anvilRecipes.push_back((new ToolRecipe(ToolType::shovel, 4)->addCost(Resource::wood, 5)->addCost(Resource::gem, 50));
//
	furnaceRecipes.push_back((new ResourceRecipe(Resource::ironIngot))->addCost(Resource::ironOre, 4)->addCost(Resource::coal, 1));
	furnaceRecipes.push_back((new ResourceRecipe(Resource::goldIngot))->addCost(Resource::goldOre, 4)->addCost(Resource::coal, 1));
	furnaceRecipes.push_back((new ResourceRecipe(Resource::glass))->addCost(Resource::sand, 4)->addCost(Resource::coal, 1));
//
	ovenRecipes.push_back((new ResourceRecipe(Resource::bread))->addCost(Resource::wheat, 4));
}

