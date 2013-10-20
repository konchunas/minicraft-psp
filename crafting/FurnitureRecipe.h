#ifndef FURNITURERECIPE_H_
#define FURNITURERECIPE_H_

#include "Recipe.h"
#include "../item/FurnitureItem.h"
#include "../entity/Player.h"

template<class T>
class FurnitureRecipe : public Recipe {
public:
	FurnitureRecipe():
	Recipe(new FurnitureItem(new T()))
	{
	}

	~FurnitureRecipe()
	{
	}

	//template<class T>
	void craft(Player * player)
	{
		player->inventory->add(0, new FurnitureItem(new T()));
	}

};

#endif /* FURNITURERECIPE_H_ */
