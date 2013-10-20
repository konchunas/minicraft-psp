#ifndef CRAFTING_H_
#define CRAFTING_H_

#include <deque>

#include "Recipe.h"

using namespace std;

class Crafting {
public:
	Crafting();
	virtual ~Crafting();

	static void init();

	static deque<Recipe*> anvilRecipes;
	static deque<Recipe*> ovenRecipes;
	static deque<Recipe*> furnaceRecipes;
	static deque<Recipe*> workbenchRecipes;
};

#endif /* CRAFTING_H_ */
