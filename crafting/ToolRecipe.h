#ifndef TOOLRECIPE_H_
#define TOOLRECIPE_H_

#include "../item/ToolType.h"

#include "Recipe.h"

class ToolRecipe : public Recipe {
public:
	ToolRecipe(ToolType * type, int level);
	virtual ~ToolRecipe();

	void craft(Player * player);

private:
	ToolType * type;
	int level;
};

#endif /* TOOLRECIPE_H_ */
