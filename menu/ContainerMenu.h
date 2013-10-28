#ifndef CONTAINERMENU_H_
#define CONTAINERMENU_H_

#include "Menu.h"
#include <string>

#include "../entity/Inventory.h"
#include "../entity/Player.h"
#include "../Screen.h"


using namespace std;

class ContainerMenu : public Menu {
public:
	ContainerMenu(Player * player, string title, Inventory * container);
	virtual ~ContainerMenu();

	void tick();
	void render(Screen * screen);

private:
	Player * player;
	Inventory * container;
	int selected;
	string title;
	int oSelected;
	int window;
};

#endif /* CONTAINERMENU_H_ */
