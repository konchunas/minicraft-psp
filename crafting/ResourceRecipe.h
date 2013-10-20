#ifndef RESOURCERECIPE_H_
#define RESOURCERECIPE_H_

#include "../item/resource/Resource.h"
#include "../entity/Player.h"

#include "Recipe.h"

class Player;

class ResourceRecipe : public Recipe {
public:
	ResourceRecipe(Resource * resource);
	virtual ~ResourceRecipe();

	void craft(Player * player);

private:
	Resource * resource;
};

#endif /* RESOURCERECIPE_H_ */
